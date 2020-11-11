#ifndef EXPRESSIONGENERATOR_H_
#define EXPRESSIONGENERATOR_H_

#include "CodeGenerator.h"

namespace backend { namespace compiler {

class ExpressionGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    ExpressionGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler) {}

    /**
     * Emit code for an expression.
     * @param ctx the ExpressionContext.
     */
    void emitExpression(GooeyParser::ExpressionContext *ctx);

    /**
     * Emit code for a simple expression.
     * @param ctx the SimpleExpressionContext.
     */
    void emitSimpleExpression(GooeyParser::SimpleExpressionContext *ctx);

    /**
     * Emit code for a term.
     * @param ctx the TermContext.
     */
    void emitTerm(GooeyParser::TermContext *ctx);

    /**
     * Emit code for NOT.
     * @param ctx the NotFactorContext.
     */
    void emitNotFactor(GooeyParser::NotFactorContext *ctx);

    /**
     * Emit code to load a scalar variable's value
     * or a structured variable's address.
     * @param ctx the VariableContext.
     */
    void emitLoadValue(GooeyParser::VariableContext *varCtx);

    /**
     * Emit code to load a scalar variable's value
     * or a structured variable's address.
     * @param variableNode the variable node.
     */
    Typespec *emitLoadVariable(GooeyParser::VariableContext *varCtx);

    /**
     * Emit code to load an integer constant.
     * @parm intCtx the IntegerConstantContext.
     */
    void emitLoadIntegerConstant(GooeyParser::NumberContext *intCtx);

    /**
     * Emit code to load real constant.
     * @parm intCtx the IntegerConstantContext.
     */
    void emitLoadRealConstant(GooeyParser::NumberContext *realCtx);

private:

    /**
     * Emit code to access an array element by loading the array address
     * and the subscript value. This can subsequently be followed by code
     * to load the array element's value or to store into the array element.
     * @param subscriptsNode the SUBSCRIPTS node.
     * @param elmtType the array element type.
     * @param lastModifier true if this is the variable's last modifier.
     * @return the type of the element.
     */
    Typespec *emitLoadArrayElementAccess(
                                    GooeyParser::ModifierContext *modCtx);

    /**
     * Emit a load of an array element's value.
     * @param elmtType the element type if character, else nullptr.
     */
    void emitLoadArrayElementValue(Typespec *elmtType);

};

}} // namespace backend::compiler

#endif /* EXPRESSIONGENERATOR_H_ */
