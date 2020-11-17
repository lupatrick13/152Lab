#ifndef STATEMENTGENERATOR_H_
#define STATEMENTGENERATOR_H_

#include <vector>
#include <map>

#include "CodeGenerator.h"

namespace backend { namespace compiler {

using namespace std;

class StatementGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    StatementGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler) {}

    /**
     * Emit code for an assignment statement.
     * @param ctx the AssignmentStatementContext.
     */
    void emitAssignment(GooeyParser::AssignmentStatementContext *ctx);

    /**
     * Emit code for an IF statement.
     * @param ctx the IfStatementContext.
     */
    void emitIf(GooeyParser::IfStatementContext *ctx);


    /**
     * Emit code for a WHILE statement.
     * @param ctx the WhileStatementContext.
     */
    void emitWhile(GooeyParser::WhileStatementContext *ctx);

    /**
     * Emit code for a FOR statement.
     * @param ctx the ForStatementContext.
     */
    void emitFor(GooeyParser::ForStatementContext *ctx);

    /**
     * Emit code for a function call statement.
     * @param ctx the FunctionCallContext.
     */
    void emitFunctionCall(GooeyParser::FunctionCallContext *ctx);
    void emitProcedureCall(GooeyParser::ProcedureCallContext *ctx);
    void emitPredefined(GooeyParser::PredefinedRoutineCallContext *ctx);
    void emitAdd(GooeyParser::ArgumentListContext *argCtx, SymtabEntry *var1,vector<GooeyParser::ExpressionContext*> *indexs, int check );
    void emitAdd(GooeyParser::ArgumentListContext *argCtx, SymtabEntry *var1,
			vector<GooeyParser::ExpressionContext*> *indexs);
    void emitSetText(GooeyParser::ArgumentListContext *argCtx, SymtabEntry *var);
    void emitAddAction(GooeyParser::ActionNameContext *ctx, SymtabEntry *var);
    void emitLoadArray(SymtabEntry *array, vector<GooeyParser::ExpressionContext *> *indexs);
private:


    /**
     * Emit code for the LOOKUPSWITCH instruction.
     * @param entries the table entries.
     * @param branchLabels the branch labels.
     */
    void emitLookupSwitch(map<int, Label *> *labelMap,
                          vector<Label *>& branchLabels);

    /**
     * Emit a call to a procedure or a function.
     * @param routineId the routine name's symbol table entry.
     * @param argListCtx the ArgumentListContext.
     */
    void emitCall(SymtabEntry *routineId,
                  GooeyParser::ArgumentListContext *argListCtx);

    void emitCreate(GooeyParser::ArgumentListContext *argCtx, SymtabEntry *entry, vector<GooeyParser::ExpressionContext*> *indexs);




};

}} // namespace backend::compiler

#endif /* STATEMENTGENERATOR_H_ */
