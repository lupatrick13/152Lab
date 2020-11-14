/*
 * ActionGenerator.h
 *
 *  Created on: Nov 13, 2020
 *      Author: patrick
 */

#ifndef BACKEND_COMPILER_ACTIONGENERATOR_H_
#define BACKEND_COMPILER_ACTIONGENERATOR_H_

#include <vector>
#include <map>

#include "CodeGenerator.h"

namespace backend { namespace compiler {

using namespace std;

class ActionGenerator : public CodeGenerator
{
public:
	ActionGenerator(string baseProgramName, string actionName,  string suffix, Compiler *compiler, CodeGenerator *parent)
		:  CodeGenerator(parent, compiler), actionName(actionName),
		  baseClass(baseProgramName)
	{
		localStack = new LocalStack();
		localVariables = new LocalVariables(2);
	}

	void emitAction(GooeyParser::ActDecContext *ctx);
	void emitConstructor();
	void emitBody(GooeyParser::CompoundStatementContext *ctx);
private:
	string actionName;
	string baseClass;
};
}}
#endif /* BACKEND_COMPILER_ACTIONGENERATOR_H_ */
