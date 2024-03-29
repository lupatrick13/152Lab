#ifndef COMPILER_H_
#define COMPILER_H_

#include "GooeyBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
#include "ProgramGenerator.h"
#include "StatementGenerator.h"
#include "ExpressionGenerator.h"
#include "ActionGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class CodeGenerator;

class Compiler : public GooeyBaseVisitor
{
private:
    SymtabEntry *programId;  // symbol table entry of the program name
    string programName;      // the program name

    CodeGenerator       *code;            // base code generator
    ProgramGenerator    *programCode;     // program code generator
    StatementGenerator  *statementCode;   // statement code generator
    ExpressionGenerator *expressionCode;  // expression code generator
    ActionGenerator 	*actionCode;

public:
    /**
     * Constructor for the base compiler.
     * @param programId the symtab entry for the program name.
     */
    Compiler(SymtabEntry *programId)
        : programId(programId), programName(programId->getName()),
          code(new CodeGenerator(programName, "j", this)),
          programCode(nullptr), statementCode(nullptr),
          expressionCode(nullptr), actionCode(nullptr) {}

    /**
     * Constructor for child compilers of procedures and functions.
     * @param parent the parent compiler.
     */
    Compiler(Compiler *parent)
        : programId(parent->programId), programName(parent->programName),
          code(parent->code), programCode(parent->programCode),
          statementCode(nullptr), expressionCode(nullptr), actionCode(nullptr) {}

    /**
     * Constructor for child compilers of records.
     * @param parent the parent compiler.
     * @param recordId the symbol table entry of the name of the record to compile.
     */
    Compiler(Compiler *parent, SymtabEntry *recordId)
    {
        string recordTypePath = recordId->getType()->getRecordTypePath();
        code = new CodeGenerator(recordTypePath, "j", this);
        createNewGenerators(code);

        programCode->emitRecord(recordId, recordTypePath);
    }

    Compiler(Compiler *parent, string baseProgramName, string actionName, GooeyParser::ActDecContext *ctx)
    {
    	string actionFile = baseProgramName + "_" + actionName;
    	code = new CodeGenerator(baseProgramName, "j", this, actionName);
    	createNewGenerators(code);
    	createNewAction(baseProgramName, actionName, "j", code);
    	actionCode->emitAction(ctx);
    }
    /**
     * Get the name of the object (Jasmin) file.
     * @return the file name.
     */
    string getObjectFileName() { return code->getObjectFileName(); }

    Object visitProgram(GooeyParser::ProgramContext *ctx) override;
    Object visitFuncDec(GooeyParser::FuncDecContext *ctx) override;
    Object visitActDec( GooeyParser::ActDecContext *ctx) override;
    Object visitStatement(GooeyParser::StatementContext *ctx) override;
    Object visitAssignmentStatement(GooeyParser::AssignmentStatementContext *ctx) override;
    Object visitIfStatement(GooeyParser::IfStatementContext *ctx) override;
    Object visitWhileStatement(GooeyParser::WhileStatementContext *ctx) override;
    Object visitForStatement(GooeyParser::ForStatementContext *ctx) override;
    Object visitExpression(GooeyParser::ExpressionContext *ctx) override;
    Object visitVariableFactor(GooeyParser::VariableFactorContext *ctx) override;
    Object visitVariable(GooeyParser::VariableContext *ctx) override;
    Object visitNumberFactor(GooeyParser::NumberFactorContext *ctx) override;
    Object visitCharacterFactor(GooeyParser::CharacterFactorContext *ctx) override;
    Object visitStringFactor(GooeyParser::StringFactorContext *ctx) override;
    Object visitFunctionCallFactor(GooeyParser::FunctionCallFactorContext *context) override;
    Object visitProcedureCall( GooeyParser::ProcedureCallContext *ctx) override;
    Object visitNotFactor(GooeyParser::NotFactorContext *ctx) override;
    Object visitParenthesizedFactor(GooeyParser::ParenthesizedFactorContext *ctx) override;
    Object visitPredefinedRoutineCall(GooeyParser::PredefinedRoutineCallContext *ctx) override;
    Object visitArgument(GooeyParser::ArgumentContext *ctx) override;



private:
    /**
     * Create new child code generators.
     * @param parentGenerator the parent code generator.
     */
    void createNewGenerators(CodeGenerator *parentGenerator)
    {
        programCode    = new ProgramGenerator(parentGenerator, this);
        statementCode  = new StatementGenerator(programCode, this);
        expressionCode = new ExpressionGenerator(programCode, this);
    }
    void createNewAction(string programName, string actionName, string suffix, CodeGenerator *parentGenerator)
    {
    	actionCode = new ActionGenerator(programName, actionName, suffix, this, parentGenerator);
    }
};

}}  // namespace backend::compiler

#endif /* COMPILER_H_ */
