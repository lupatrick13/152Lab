#include "GooeyBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "ExpressionGenerator.h"
#include "Compiler.h"

namespace backend { namespace compiler {

void ExpressionGenerator::emitExpression(GooeyParser::ExpressionContext *ctx)
{
    GooeyParser::SimpleExpressionContext *simpleCtx1 =
                                            ctx->simpleExpression()[0];
    GooeyParser::RelOpContext *relOpCtx = ctx->relOp();
    Typespec *type1 = simpleCtx1->type;
    emitSimpleExpression(simpleCtx1);

    // More than one simple expression?
    if (relOpCtx != nullptr)
    {
        string op = relOpCtx->getText();
        GooeyParser::SimpleExpressionContext *simpleCtx2 =
                                            ctx->simpleExpression()[1];
        Typespec *type2 = simpleCtx2->type;

        bool integerMode   = false;
        bool realMode      = false;
        bool characterMode = false;

        if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }
        else if (   (type1 == Predefined::charType)
                 && (type2 == Predefined::charType))
        {
            characterMode = true;
        }

        Label *trueLabel = new Label();
        Label *exitLabel = new Label();

        if (integerMode || characterMode)
        {
            if(simpleCtx1->array)
            	emit(AALOAD);
            emitSimpleExpression(simpleCtx2);

            if      (op == "==" ) emit(IF_ICMPEQ, trueLabel);
            else if (op == "!=") emit(IF_ICMPNE, trueLabel);
            else if (op == "<" ) emit(IF_ICMPLT, trueLabel);
            else if (op == "<=") emit(IF_ICMPLE, trueLabel);
            else if (op == ">" ) emit(IF_ICMPGT, trueLabel);
            else if (op == ">=") emit(IF_ICMPGE, trueLabel);
        }
        else if (realMode)
        {
            if(simpleCtx1->array)
            	emit(AALOAD);
            if (type1 == Predefined::integerType) emit(I2F);
            emitSimpleExpression(simpleCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            emit(FCMPG);

            if      (op == "==" ) emit(IFEQ, trueLabel);
            else if (op == "!=") emit(IFNE, trueLabel);
            else if (op == "<" ) emit(IFLT, trueLabel);
            else if (op == "<=") emit(IFLE, trueLabel);
            else if (op == ">" ) emit(IFGT, trueLabel);
            else if (op == ">=") emit(IFGE, trueLabel);
        }
        else  // stringMode
        {
            if(simpleCtx1->array)
            	emit(AALOAD);
            emitSimpleExpression(simpleCtx2);
            emit(INVOKEVIRTUAL,
                 "java/lang/String.compareTo(Ljava/lang/String;)I");
            localStack->decrease(1);

            if      (op == "==" ) emit(IFEQ, trueLabel);
            else if (op == "!=") emit(IFNE, trueLabel);
            else if (op == "<" ) emit(IFLT, trueLabel);
            else if (op == "<=") emit(IFLE, trueLabel);
            else if (op == ">" ) emit(IFGT, trueLabel);
            else if (op == ">=") emit(IFGE, trueLabel);
        }

        emit(ICONST_0); // false
        emit(GOTO, exitLabel);
        emitLabel(trueLabel);
        emit(ICONST_1); // true
        emitLabel(exitLabel);

        localStack->decrease(1);  // only one branch will be taken
    }
}

void ExpressionGenerator::emitSimpleExpression(GooeyParser::SimpleExpressionContext *ctx)
{
    int count = ctx->term().size();
    bool negate =    (ctx->sign() != nullptr)
                  && (ctx->sign()->getText() == "-");

    // First term.
    GooeyParser::TermContext *termCtx1 = ctx->term()[0];
    Typespec *type1 = termCtx1->type;
    emitTerm(termCtx1);

    if (negate) emit(type1 == Predefined::integerType ? INEG : FNEG);

    // Loop over the subsequent terms.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->addOp()[i-1]->getText());
        GooeyParser::TermContext *termCtx2 = ctx->term()[i];
        Typespec *type2 = termCtx2->type;

        bool integerMode = false;
        bool realMode    = false;
        bool booleanMode = false;
        bool stringMode  = false;

        if((type1 == Predefined::stringType)
                 || (type2 == Predefined::stringType))
        {
        	stringMode = true;
        }
        else if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }
        else if (   (type1 == Predefined::booleanType)
                 && (type2 == Predefined::booleanType))
        {
            booleanMode = true;
        }

        if (integerMode)
        {
            if(termCtx1->array)
            	emit(AALOAD);
            emitTerm(termCtx2);

            if (op == "+") emit(IADD);
            else           emit(ISUB);
//            localStack->decrease(1);
        }
        else if (realMode)
        {
            if(termCtx1->array)
            	emit(AALOAD);
            if (type1 == Predefined::integerType) emit(I2F);
            emitTerm(termCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            if (op == "+") emit(FADD);
            else           emit(FSUB);
        }
        else if (booleanMode)
        {
            if(termCtx1->array)
            	emit(AALOAD);
            emitTerm(termCtx2);
            emit(IOR);
        }
        else if(stringMode) // stringMode
        {
        	string type;
        	if(type1 != Predefined::stringType)
        	{
        		if(type1->getForm() == Form::ARRAY) type1 = type1->getArrayElementType();
        		type = typeDescriptor(type1);
        	}
        	else if(type2 != Predefined::stringType)
        	{
        		if(type1->getForm() == Form::ARRAY) type2 = type2->getArrayElementType();
        		type = typeDescriptor(type2);
        	}
        	else type = "Ljava/lang/String;";
            emit(NEW, "java/lang/StringBuilder");
            emit(DUP_X1);
            emit(SWAP);
            emit(INVOKESTATIC,
                 string("java/lang/String/valueOf(Ljava/lang/Object;)") +
                 string("Ljava/lang/String;"));
            emit(INVOKESPECIAL,
                 string("java/lang/StringBuilder/<init>") +
                 string("(Ljava/lang/String;)V"));
            localStack->decrease(1);

            emitTerm(termCtx2);
            emit(INVOKEVIRTUAL,
                 string("java/lang/StringBuilder/append(") + type + ")" +
                 string("Ljava/lang/StringBuilder;"));
            localStack->decrease(1);
            emit(INVOKEVIRTUAL,
                 string("java/lang/StringBuilder/toString()") +
                 string("Ljava/lang/String;"));
            localStack->decrease(1);
        }
    }
}

void ExpressionGenerator::emitTerm(GooeyParser::TermContext *ctx)
{
    int count = ctx->factor().size();

    // First factor.
    GooeyParser::FactorContext *factorCtx1 = ctx->factor()[0];
    Typespec *type1 = factorCtx1->type;
    compiler->visit(factorCtx1);

    // Loop over the subsequent factors.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->mulOp()[i-1]->getText());
        GooeyParser::FactorContext *factorCtx2 = ctx->factor()[i];
        Typespec *type2 = factorCtx2->type;

        bool integerMode = false;
        bool realMode    = false;

        if (   (type1 == Predefined::integerType)
            && (type2 == Predefined::integerType))
        {
            integerMode = true;
        }
        else if (   (type1 == Predefined::realType)
                 || (type2 == Predefined::realType))
        {
            realMode = true;
        }

        if (integerMode)
        {
            if(factorCtx1->array)
            	emit(AALOAD);
            compiler->visit(factorCtx2);

            if      (op == "*")   emit(IMUL);
            else if (op == "/")   emit(FDIV);
            else if (op == "div") emit(IDIV);
            else if (op == "mod") emit(IREM);
        }
        else if (realMode)
        {
            if(factorCtx1->array)
            	emit(AALOAD);
            if (type1 == Predefined::integerType) emit(I2F);
            compiler->visit(factorCtx2);
            if (type2 == Predefined::integerType) emit(I2F);

            if      (op == "*") emit(FMUL);
            else if (op == "/") emit(FDIV);
        }
        else  // booleanMode
        {
            if(factorCtx1->array)
            	emit(AALOAD);
            compiler->visit(factorCtx2);
            emit(IAND);
        }
    }
}

void ExpressionGenerator::emitNotFactor(GooeyParser::NotFactorContext *ctx)
{
    compiler->visit(ctx->factor());
    emit(ICONST_1);
    emit(IXOR);
}

void ExpressionGenerator::emitLoadValue(GooeyParser::VariableContext *varCtx)
{
    // Load the scalar value or structure address.
    Typespec *variableType = emitLoadVariable(varCtx);
    SymtabEntry *entry = varCtx->entry;
    vector<GooeyParser::ExpressionContext *> *indexs;
     //Load an array element's or record field's value.
        if (varCtx->modifier(0) != nullptr)
        {
        	vector<GooeyParser::ExpressionContext *> *indexs = new vector<GooeyParser::ExpressionContext *>();
        	for(GooeyParser::ModifierContext *modCtx : varCtx->modifier())
        	{
        		indexs->push_back(modCtx->expression());
        	}
        	int size = indexs->size()-1;
        	int index = 0;
        	for(GooeyParser::ExpressionContext *expCtx : *indexs)
        	{
        		compiler->visit(expCtx);
        		if(index != size) emit(AALOAD);
        		index++;
        	}
        }

}

Typespec *ExpressionGenerator::emitLoadVariable(
                                        GooeyParser::VariableContext *varCtx)
{
    SymtabEntry *variableId = varCtx->entry;
    Typespec *type = variableId->getType();
    while(type->getForm() == Form::ARRAY) type = type->getArrayElementType();
    Typespec *variableType = type;

//    bool modifierCount = varCtx->modifier() != nullptr;

    // Scalar value or structure address.
    CodeGenerator::emitLoadValue(variableId);  // why need CodeGenerator::?


    return variableType;
}

Typespec *ExpressionGenerator::emitLoadArrayElementAccess(
                                GooeyParser::ModifierContext *modCtx)
{

    return nullptr;
}

void ExpressionGenerator::emitLoadArrayElementValue(Typespec *elmtType)
{
    Form form = SCALAR;

    if (elmtType != nullptr)
    {
        elmtType = elmtType->baseType();
        form = elmtType->getForm();
    }

    // Load a character from a string.
    if (elmtType == Predefined::charType)
    {
        emit(INVOKEVIRTUAL, "java/lang/StringBuilder.charAt(I)C");
    }

    // Load an array element.
    else
    {
        emit(  elmtType == Predefined::integerType ? IALOAD
             : elmtType == Predefined::realType    ? FALOAD
             : elmtType == Predefined::booleanType ? BALOAD
             : elmtType == Predefined::charType    ? CALOAD
             : form == ENUMERATION                 ? IALOAD
             :                                       AALOAD);
    }
}



void ExpressionGenerator::emitLoadIntegerConstant(GooeyParser::NumberContext *intCtx)
{
    int value = stoi(intCtx->getText());
    emitLoadConstant(value);
}

void ExpressionGenerator::emitLoadRealConstant(GooeyParser::NumberContext *realCtx)
{
    float value = stof(realCtx->getText());
    emitLoadConstant(value);
}

}} // namespace backend::compiler
