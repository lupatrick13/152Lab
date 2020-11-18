#include <vector>

#include "GooeyBaseVisitor.h"
#include "antlr4-runtime.h"

#include "Directive.h"
#include "Instruction.h"
#include "Compiler.h"
#include "ProgramGenerator.h"
#include "StructuredDataGenerator.h"

namespace backend { namespace compiler {

using namespace std;

void ProgramGenerator::emitProgram(GooeyParser::ProgramContext *ctx)
{
    programId = ctx->programHeader()->title()->entry;
    Symtab *programSymtab = programId->getRoutineSymtab();

    localVariables = new LocalVariables(programLocalsCount);

    if(ctx->block()->actionDef()!= nullptr)
    	emitActions(ctx->block()->actionDef());

    emitRecords(programSymtab);

    emitDirective(SOURCE, programName);
    emitDirective(CLASS_PUBLIC, programName);
    emitDirective(SUPER, "java/lang/Object");

    emitDirective(FIELD_PRIVATE_STATIC, "_mainframe", "Ljavax/swing/JFrame;"); //initializes the frame that holds everything
    emitProgramVariables();
    emitInputScanner(ctx);
    emitConstructor();
    if(ctx->block()->functiondef()!= nullptr)
    	emitSubroutines(ctx->block()->functiondef());


    emitMainMethod(ctx);
}
void ProgramGenerator::emitSubroutines(GooeyParser::FunctiondefContext *ctx){
	if(ctx != nullptr)
	{
		for(GooeyParser::FuncDecContext *defnCtx : ctx->funcDec())
		{
			compiler = new Compiler(compiler);
			compiler->visit(defnCtx);
		}
	}
}
void ProgramGenerator::emitActions(GooeyParser::ActionDefContext *ctx){
	if(ctx != nullptr)
	{
		for(GooeyParser::ActDecContext *defnCtx : ctx->actDec())
		{
			compiler->visit(defnCtx);
		}
	}
}
void ProgramGenerator::emitRecords(Symtab *symtab)
{
    for (SymtabEntry *id : symtab->sortedEntries())
    {
        if (   (id->getKind() == TYPE)
            && (id->getType()->getForm() == RECORD))
        {
            new Compiler(compiler, id);
        }
    }
}
void ProgramGenerator::emitAction(GooeyParser::ActDecContext *ctx)
{
	SymtabEntry *actionId = ctx->actionName()->entry;
	string actionName = actionId->getName();
	new Compiler(compiler, programName, actionName, ctx);
}

void ProgramGenerator::emitRecord(SymtabEntry *recordId, string namePath)
{
    Symtab *recordSymtab = recordId->getType()->getRecordSymtab();

    emitDirective(CLASS_PUBLIC, namePath);
    emitDirective(SUPER, "java/lang/Object");
    emitLine();

    // Emit code for any nested records.
    emitRecords(recordSymtab);


    emitConstructor();
    close();  // the object file
}

void ProgramGenerator::emitProgramVariables()
{
    // Runtime timer and standard in.

    Symtab *symtab = programId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    emitLine();
    emitDirective(FIELD_PRIVATE_STATIC, "_sysin", "Ljava/util/Scanner;");
    emitDirective(FIELD_PROTECTED_STATIC, "_random", "Ljava/util/Random;");

    // Loop over all the program's identifiers and
    // emit a .field directive for each variable.
    for (SymtabEntry *id : ids)
    {
        if (id->getKind() == VARIABLE)
        {
            emitDirective(FIELD_PROTECTED_STATIC, id->getName(),
                          typeDescriptor(id));
        }
    }
}

void ProgramGenerator::emitInputScanner(GooeyParser::ProgramContext *ctx)
{
    emitLine();
    emitComment("Runtime input scanner");
    emitDirective(METHOD_STATIC, "<clinit>()V");
    emitLine();

    emit(NEW, "java/util/Scanner");
    emit(DUP);
    emit(GETSTATIC, "java/lang/System/in Ljava/io/InputStream;");
    emit(INVOKESPECIAL, "java/util/Scanner/<init>(Ljava/io/InputStream;)V");
    emit(PUTSTATIC, programName + "/_sysin Ljava/util/Scanner;");
    //Initialize RNG
    emit(NEW, "java/util/Random");
    emit(DUP);
    emit(INVOKESPECIAL, "java/util/Random/<init>()V");
    emit(PUTSTATIC, programName+"/_random", "Ljava/util/Random;");

    //Initializing the frame
	emitLine();
	emit(NEW, "javax/swing/JFrame");
	emit(DUP);
	emit(LDC, '"' + programName + '"');
	emit(INVOKESPECIAL, "javax/swing/JFrame/<init>(Ljava/lang/String;)V");
	emit(DUP);
	emit(PUTSTATIC, programName + "/_mainframe", "Ljavax/swing/JFrame;");

	if(ctx->INTEGER(0) != nullptr)
	{
		int sizew = stoi(ctx->INTEGER(0)->getText());
		int sizeh = stoi(ctx->INTEGER(1)->getText());
		emit(DUP);
		emit(NEW, "java/awt/Dimension");
		emit(DUP);
		emit(LDC, sizew);
		emit(LDC, sizeh);
		emit(INVOKESPECIAL, "java/awt/Dimension/<init>(II)V");
		emit(INVOKEVIRTUAL,"javax/swing/JFrame/setMinimumSize(Ljava/awt/Dimension;)V"); //sets the minimum size
	}
	emit(GETSTATIC, "javax/swing/JFrame/EXIT_ON_CLOSE", "I");
	emit(INVOKEVIRTUAL, "javax/swing/JFrame/setDefaultCloseOperation(I)V");



    emit(RETURN);

    emitLine();
    emitDirective(LIMIT_LOCALS, 0);
    emitDirective(LIMIT_STACK,  6);
    emitDirective(END_METHOD);

    localStack->reset();
}

void ProgramGenerator::emitConstructor()
{
    emitLine();
    emitComment("Main class constructor");
    emitDirective(METHOD_PUBLIC, "<init>()V");
    emitDirective(VAR, "0 is this L" + programName + ";");
    emitLine();

    emit(ALOAD_0);
    emit(INVOKESPECIAL, "java/lang/Object/<init>()V");
    emit(RETURN);

    emitLine();
    emitDirective(LIMIT_LOCALS, 1);
    emitDirective(LIMIT_STACK,  1);
    emitDirective(END_METHOD);

    localStack->reset();
}



void ProgramGenerator::emitMainMethod(GooeyParser::ProgramContext *ctx)
{
    GooeyParser::FunctiondefContext *RPC = ctx->block()->functiondef() != nullptr ? ctx->block()->functiondef() : nullptr;
    int stackSize = 0;
    if(RPC != nullptr)
    {
		for(GooeyParser::FuncDecContext *Def : RPC->funcDec())
		{
				vector<SymtabEntry *> *parmIds = Def->functionName()->entry->getRoutineParameters();
				int size = parmIds->size();
				stackSize = max(stackSize, size);
		}
    }
	emitLine();
    emitComment("MAIN");
    emitDirective(METHOD_PUBLIC_STATIC,
                              "main([Ljava/lang/String;)V");

    emitMainPrologue(programId);

    // Emit code to allocate any arrays, records, and strings.
    StructuredDataGenerator structureCode(this, compiler);
    structureCode.emitData(programId);

    // Emit code for the compound statement.
    emitLine();
    compiler->visit(ctx->block()->compoundStatement());
    emitMainEpilogue(stackSize, programId);
}

void ProgramGenerator::emitMainPrologue(SymtabEntry *programId)
{
    emitDirective(VAR, "0 is args [Ljava/lang/String;");
    emitDirective(VAR, "1 is _start Ljava/time/Instant;");
    emitDirective(VAR, "2 is _end Ljava/time/Instant;");
    emitDirective(VAR, "3 is _elapsed J");

    // Runtime timer.
    emitLine();
    emit(INVOKESTATIC, "java/time/Instant/now()Ljava/time/Instant;");
    localStack->increase(1);
    emit(ASTORE_1);


}

void ProgramGenerator::emitMainEpilogue(int stackSize, SymtabEntry *programId)
{
    // Print the execution time.
    emitLine();
    emit(INVOKESTATIC, "java/time/Instant/now()Ljava/time/Instant;");
    localStack->increase(1);
    emit(ASTORE_2);
    emit(ALOAD_1);
    emit(ALOAD_2);
    emit(INVOKESTATIC,
         string("java/time/Duration/between(Ljava/time/temporal/Temporal;") +
         string("Ljava/time/temporal/Temporal;)Ljava/time/Duration;"));
    localStack->decrease(1);
    emit(INVOKEVIRTUAL, "java/time/Duration/toMillis()J");
    localStack->increase(1);
    emit(LSTORE_3);
    emit(GETSTATIC, "java/lang/System/out Ljava/io/PrintStream;");
    emit(LDC, "\"\\n[%,d milliseconds execution time.]\\n\"");
    emit(ICONST_1);
    emit(ANEWARRAY, "java/lang/Object");
    emit(DUP);
    emit(ICONST_0);
    emit(LLOAD_3);
    emit(INVOKESTATIC, "java/lang/Long/valueOf(J)Ljava/lang/Long;");
    emit(AASTORE);
    emit(INVOKEVIRTUAL,
         string("java/io/PrintStream/printf(Ljava/lang/String;") +
         string("[Ljava/lang/Object;)Ljava/io/PrintStream;"));
    localStack->decrease(2);
    emit(POP);

    //initialize the frame
    emitLine();
    emit(GETSTATIC, programId->getName() + "/_mainframe", "Ljavax/swing/JFrame;");
    emit(DUP);
    emit(INVOKEVIRTUAL, "javax/swing/JFrame/pack()V");
    emit(LDC, 1);
    emit(INVOKEVIRTUAL, "javax/swing/JFrame/setVisible(Z)V");

    emitLine();
    emit(RETURN);
    emitLine();

    emitDirective(LIMIT_LOCALS, localVariables->count());
    emitDirective(LIMIT_STACK,  max(stackSize,localStack->capacity()));
    emitDirective(END_METHOD);

    close();  // the object file
}

void ProgramGenerator::emitRoutine(GooeyParser::FuncDecContext *ctx)
{

    SymtabEntry *routineId = ctx->functionName()->entry;
    Symtab *routineSymtab = routineId->getRoutineSymtab();

    emitRoutineHeader(routineId);
    emitRoutineLocals(routineId);

    // Generate code to allocate any arrays, records, and strings.
    StructuredDataGenerator structuredCode(this, compiler);
    structuredCode.emitData(routineId);
    localVariables = new LocalVariables(routineSymtab->getMaxSlotNumber());

    // Emit code for the compound statement.
    GooeyParser::CompoundStatementContext *stmtCtx =
        (GooeyParser::CompoundStatementContext *) routineId->getExecutable();
    compiler->visit(stmtCtx);

    emitRoutineReturn(routineId);
    emitRoutineEpilogue();
}

void ProgramGenerator::emitRoutineHeader(SymtabEntry *routineId)
{
    string routineName = routineId->getName();
    vector<SymtabEntry *> *parmIds = routineId->getRoutineParameters();
    string header(routineName + "(");

    // Parameter and return type descriptors.
    if (parmIds != nullptr)
    {
        for (SymtabEntry *parmId : *parmIds)
        {
            header += typeDescriptor(parmId);
        }
    }
    header += ")" + typeDescriptor(routineId);

    emitLine();
    emitComment("FUNCTION " + routineName);

    emitDirective(METHOD_PROTECTED_STATIC, header);
}

void ProgramGenerator::emitRoutineLocals(SymtabEntry *routineId)
{
    Symtab *symtab = routineId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    emitLine();

    // Loop over all the routine's identifiers and
    // emit a .var directive for each variable and formal parameter.
    for (SymtabEntry *id : ids)
    {
        Kind kind = id->getKind();

        if ((kind == VARIABLE) || (kind == VALUE_PARAMETER)
                               || (kind == REFERENCE_PARAMETER))
        {
            int slot = id->getSlotNumber();
            emitDirective(VAR, to_string(slot) + " is " + id->getName(),
                          typeDescriptor(id));
        }
    }
}

void ProgramGenerator::emitRoutineReturn(SymtabEntry *routineId)
{
    emitLine();

    // Function: Return the value in the implied function variable.
    if (routineId->getKind() == FUNCTION)
    {
        Typespec *type = routineId->getType();

        // Get the slot number of the function variable.
        string varName = routineId->getName();
        SymtabEntry *varId = routineId->getRoutineSymtab()->lookup(varName);
        emitLoadLocal(type, varId->getSlotNumber());
        emitReturnValue(type);
    }

    // Procedure: Just return.
    else emit(RETURN);
}

void ProgramGenerator::emitRoutineEpilogue()
{
    emitLine();
    emitDirective(LIMIT_LOCALS, localVariables->count());
    emitDirective(LIMIT_STACK,  localStack->capacity());
    emitDirective(END_METHOD);
}

}} // namespace backend::compiler
