#ifndef PROGRAMGENERATOR_H_
#define PROGRAMGENERATOR_H_

#include "CodeGenerator.h"

namespace backend { namespace compiler {

class ProgramGenerator : public CodeGenerator
{
private:
    SymtabEntry *programId;  // symbol table entry of the program name
    int programLocalsCount;  // count of program local variables
public:
    /*
     * Constructor.
     * @param the parent generator.
     * @param compiler the compiler to use.
     */
    ProgramGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler),
          programId(nullptr), programLocalsCount(5) // 5 because _elapsed is long
    {
        localStack = new LocalStack();
    }

    /*
     * Emit code for a program.
     * @param *ctx the ProgramContext.
     */
    void emitProgram(GooeyParser::ProgramContext *ctx);

    /*
     * Create a new compiler instance for a record.
     * @param symtab the record type's symbol table.
     */
    void emitRecords(Symtab *symtab);

    void emitAction(GooeyParser::ActDecContext *ctx);
    /*
     * Emit code for a record.
     */
    void emitRecord(SymtabEntry *recordId, string namePath);

    /*
     * Emit code for a declared procedure or function
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutine(GooeyParser::FuncDecContext *ctx);

private:
    /*
     * Emit field directives for the program variables.
     */
    void emitProgramVariables();

    /*
     * Emit code for the runtime input scanner.
     */
    void emitInputScanner(GooeyParser::ProgramContext *ctx);

    /*
     * Emit code for the main program constructor.
     */
    void emitConstructor();

    void emitSubroutines(GooeyParser::FunctiondefContext *ctx);
    /*
     * Emit code for the program body as the main method.
     * @param *ctx the ProgramContext.
     */
    void emitActions(GooeyParser::ActionDefContext *ctx);
    void emitMainMethod(GooeyParser::ProgramContext *ctx);

    /*
     * Emit the main method prologue.
     * @parm programId the symbol table entry for the program name.
     */
    void emitMainPrologue(SymtabEntry *programId);

    /*
     * Emit the main method epilogue.
     */
    void emitMainEpilogue(int stackSize, SymtabEntry *programId);

    /*
     * Emit the routine header.
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutineHeader(SymtabEntry *routineId);

    /*
     * Emit directives for the local variables.
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutineLocals(SymtabEntry *routineId);

    /*
     * Emit the routine's return code.
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutineReturn(SymtabEntry *routineId);

    /*
     * Emit the routine's epilogue.
     */
    void emitRoutineEpilogue();
};

}} // namespace backend::compiler

#endif /* PROGRAMGENERATOR_H_ */
