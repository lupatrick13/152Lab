/*
 * ActionGenerator.cpp
 *
 *  Created on: Nov 13, 2020
 *      Author: patrick
 */
#include <string>
#include <vector>
#include <map>

#include "GooeyBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"
#include <backend/compiler/ActionGenerator.h>

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

void ActionGenerator::emitAction(GooeyParser::ActDecContext *ctx)
{

	emitDirective(SOURCE, baseClass);
	emitDirective(CLASS, programName + "_" + actionName);
	emitDirective(SUPER, "java/lang/Object");
	emitDirective(IMPLEMENTS, "java/awt/event/ActionListener");

	emitConstructor();
	emitBody(ctx->compoundStatement());
	close();
}

void ActionGenerator::emitConstructor()
{
    emitLine();
    emitComment("Main class constructor");
    emitDirective(METHOD_PUBLIC, "<init>()V");
    emitDirective(VAR, "0 is this L" + programName + "_" + actionName+ ";");
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

void ActionGenerator::emitBody(GooeyParser::CompoundStatementContext *ctx)
{
	emitLine();
	emitDirective(METHOD_PUBLIC, "actionPerformed(Ljava/awt/event/ActionEvent;)V");
	emitDirective(VAR, "0 is this L" +programName+ "_" + actionName + ";");
	emitDirective(VAR, "1 is e Ljava/awt/event/ActionEvent;");
	compiler->visit(ctx);
	emit(RETURN);
    emitDirective(LIMIT_LOCALS, localVariables->count());
    emitDirective(LIMIT_STACK,  7);
    emitDirective(END_METHOD);
}
}}
