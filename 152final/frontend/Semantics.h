#ifndef SEMANTICS_H_
#define SEMANTICS_H_

#include <map>

#include "GooeyBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/util/BackendMode.h"
#include "SemanticErrorHandler.h"

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Semantics : public GooeyBaseVisitor
{
private:
    BackendMode mode;
    SymtabStack *symtabStack;
    SymtabEntry *programId;
    SemanticErrorHandler error;

    map<string, Typespec *> *typeTable;

    /**
     * Return the number of values in a datatype.
     * @param type the datatype.
     * @return the number of values.
     */
    int typeCount(Typespec *type);

    /**
     * Determine whether or not an expression is a variable only.
     * @param exprCtx the ExpressionContext.
     * @return true if it's an expression only, else false.
     */
    bool expressionIsVariable(GooeyParser::ExpressionContext *exprCtx);

    /**
     * Perform semantic operations on procedure and function call arguments.
     * @param listCtx the ArgumentListContext.
     * @param parameters the vector of parameters to fill.
     */
    void checkCallArguments(GooeyParser::ArgumentListContext *listCtx,
                            vector<SymtabEntry *> *parms);

    /**
     * Determine the datatype of a variable that can have modifiers.
     * @param varCtx the VariableContext.
     * @param varType the variable's datatype without the modifiers.
     * @return the datatype with any modifiers.
     */
    Typespec *variableDatatype(GooeyParser::VariableContext *varCtx,
                               Typespec *varType);

    /**
     * Create the fully qualified type pathname of a record type.
     * @param recordType the record type.
     * @return the pathname.
     */
    string createRecordTypePath(Typespec *recordType);

    /**
     * Create the symbol table for a record type.
     * @param ctx the RecordFieldsContext,
     * @param ownerId the symbol table entry of the owner's identifier.
     * @return the symbol table.
     */

public:
    Semantics(BackendMode mode) : mode(mode), programId(nullptr)
    {
        // Create and initialize the symbol table stack.
        symtabStack = new SymtabStack();
        Predefined::initialize(symtabStack);

        typeTable = new map<string, Typespec *>();
        (*typeTable)["int"] 	= Predefined::integerType;
        (*typeTable)["real"]    = Predefined::realType;
        (*typeTable)["bool"] 	= Predefined::booleanType;
        (*typeTable)["char"]    = Predefined::charType;
        (*typeTable)["str"]  	= Predefined::stringType;
        (*typeTable)["char"]    = Predefined::charType;
        (*typeTable)["button"]  = Predefined::buttonType;
        (*typeTable)["label"] 	= Predefined::labelType;
        (*typeTable)["panel"]  	= Predefined::panelType;
    }

    /**
     * Get the symbol table entry of the program identifier.
     * @return the entry.
     */
    SymtabEntry *getProgramId() { return programId; }

    /**
     * Get the count of semantic errors.
     * @return the count.
     */
    int getErrorCount() const { return error.getCount(); }

    /**
     * Return the default value for a given datatype.
     * @param type the datatype.
     */
    static Object defaultValue(Typespec *type);

    Object visitProgram(GooeyParser::ProgramContext *ctx) 							override;
    Object visitVariable(GooeyParser::VariableContext *ctx)							override;
    Object visitVariableDeclarations(GooeyParser::VariableDeclarationsContext *ctx) override;
    Object visitArrayVardec(GooeyParser::ArrayVardecContext *ctx)					override;
    Object visitTypes(GooeyParser::TypesContext *ctx) 								override;
    Object visitProgramHeader(GooeyParser::ProgramHeaderContext *ctx)				override;
    Object visitFuncDec(GooeyParser::FuncDecContext *ctx) 							override;
    Object visitParameterDecList( GooeyParser::ParameterDecListContext *ctx)		override;
    Object visitParameterDec(GooeyParser::ParameterDecContext *ctx) 				override;
    Object visitReturnType(GooeyParser::ReturnTypeContext *ctx) 					override;
    Object visitAssignmentStatement(GooeyParser::AssignmentStatementContext *ctx) 	override;
    Object visitLhs(GooeyParser::LhsContext *ctx) 									override;
    Object visitExpression(GooeyParser::ExpressionContext *ctx) 					override;
    Object visitSimpleExpression(GooeyParser::SimpleExpressionContext *ctx) 		override;
    Object visitTerm(GooeyParser::TermContext *ctx) 								override;
    Object visitVariableFactor(GooeyParser::VariableFactorContext *ctx)				override;
    Object visitParenthesizedFactor(GooeyParser::ParenthesizedFactorContext *ctx) 	override;
    Object visitNotFactor(GooeyParser::NotFactorContext *ctx)						override;
    Object visitStringFactor(GooeyParser::StringFactorContext *ctx)					override;
    Object visitCharacterFactor(GooeyParser::CharacterFactorContext *ctx)			override;
    Object visitNumberFactor(GooeyParser::NumberFactorContext *ctx)					override;
    Object visitProcedureCall(GooeyParser::ProcedureCallContext *ctx)				override;
    Object visitFunctionCallFactor( GooeyParser::FunctionCallFactorContext *ctx)	override;
    Object visitPredefinedRoutineCall(GooeyParser::PredefinedRoutineCallContext *ctx) override;
    Object visitActDec(GooeyParser::ActDecContext *ctx)								override;
    Object visitActionName(GooeyParser::ActionNameContext *ctx)						override;
};

} // namespace frontend

#endif /* SEMANTICS_H_ */
