/**
 * <h1>Predefined</h1>
 *
 * <p>Enter the predefined Pascal types, identifiers, and constants
 * into the symbol table.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>

#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "Predefined.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

// Predefined types.
intermediate::type::Typespec *Predefined::integerType;
intermediate::type::Typespec *Predefined::realType;
intermediate::type::Typespec *Predefined::booleanType;
intermediate::type::Typespec *Predefined::charType;
intermediate::type::Typespec *Predefined::stringType;
intermediate::type::Typespec *Predefined::buttonType;
intermediate::type::Typespec *Predefined::labelType;
intermediate::type::Typespec *Predefined::panelType;
intermediate::type::Typespec *Predefined::textType;
intermediate::type::Typespec *Predefined::undefinedType;

// Predefined identifiers.
SymtabEntry *Predefined::integerId;
SymtabEntry *Predefined::realId;
SymtabEntry *Predefined::booleanId;
SymtabEntry *Predefined::charId;
SymtabEntry *Predefined::stringId;
SymtabEntry *Predefined::buttonId;
SymtabEntry *Predefined::labelId;
SymtabEntry *Predefined::panelId;
SymtabEntry *Predefined::textId;
SymtabEntry *Predefined::falseId;
SymtabEntry *Predefined::trueId;
SymtabEntry *Predefined::roundId;
SymtabEntry *Predefined::succId;
SymtabEntry *Predefined::truncId;
SymtabEntry *Predefined::createId;
SymtabEntry *Predefined::addId;
SymtabEntry *Predefined::finishId;

void Predefined::initialize(SymtabStack *symtabStack)
{
    initializeTypes(symtabStack);
    initializeConstants(symtabStack);
    initializeStandardRoutines(symtabStack);
}

void Predefined::initializeTypes(SymtabStack *symtabStack)
{
    // Type integer.
    integerId = symtabStack->enterLocal("int", TYPE);
    integerType = new Typespec(SCALAR);
    integerType->setIdentifier(integerId);
    integerId->setType(integerType);

    // Type real.
    realId = symtabStack->enterLocal("real", TYPE);
    realType = new Typespec(SCALAR);
    realType->setIdentifier(realId);
    realId->setType(realType);

    // Type boolean.
    booleanId = symtabStack->enterLocal("boolean", TYPE);
    booleanType = new Typespec(ENUMERATION);
    booleanType->setIdentifier(booleanId);
    booleanId->setType(booleanType);

    // Type char.
    charId = symtabStack->enterLocal("char", TYPE);
    charType = new Typespec(SCALAR);
    charType->setIdentifier(charId);
    charId->setType(charType);

    // Type string.
    stringId = symtabStack->enterLocal("str", TYPE);
    stringType = new Typespec(SCALAR);
    stringType->setIdentifier(stringId);
    stringId->setType(stringType);

    // Type button
    buttonId = symtabStack->enterLocal("button", TYPE);
    buttonType = new Typespec(COMPONENT);
    buttonType->setIdentifier(buttonId);
    buttonId->setType(buttonType);

    // Type label
    labelId = symtabStack->enterLocal("label", TYPE);
    labelType = new Typespec(COMPONENT);
    labelType->setIdentifier(labelId);
    labelId->setType(labelType);

    panelId = symtabStack->enterLocal("panel", TYPE);
    panelType = new Typespec(COMPONENT);
    panelType->setIdentifier(panelId);
    panelId->setType(panelType);

    textId = symtabStack->enterLocal("text", TYPE);
    textType = new Typespec(COMPONENT);
    textType->setIdentifier(textId);
    textId->setType(textType);

    // Undefined type.
    undefinedType = new Typespec(SCALAR);
}

void Predefined::initializeConstants(SymtabStack *symtabStack)
{
    // Boolean enumeration constant false.
    falseId = symtabStack->enterLocal("false", ENUMERATION_CONSTANT);
    falseId->setType(booleanType);
    falseId->setValue(0);

    // Boolean enumeration constant true.
    trueId = symtabStack->enterLocal("true", ENUMERATION_CONSTANT);
    trueId->setType(booleanType);
    trueId->setValue(1);

    // Add false and true to the boolean enumeration type.
    vector<SymtabEntry *> *constants = new vector<SymtabEntry *>;
    constants->push_back(falseId);
    constants->push_back(trueId);
    booleanType->setEnumerationConstants(constants);
}

void Predefined::initializeStandardRoutines(SymtabStack *symtabStack)
{
;
    roundId  = enterStandard(symtabStack, FUNCTION,  "round",   ROUND);
    succId   = enterStandard(symtabStack, FUNCTION,  "succ",    SUCC);
    truncId  = enterStandard(symtabStack, FUNCTION,  "trunc",   TRUNC);
    createId = enterStandard(symtabStack, PROCEDURE,  "create",   CREATE);
    addId = enterStandard(symtabStack, PROCEDURE,  "add",   ADD);
    finishId = enterStandard(symtabStack, PROCEDURE,  "finish",  FINISH);
}

SymtabEntry *Predefined::enterStandard(SymtabStack *symtabStack,
                                       const Kind kind, const string name,
                                       const Routine code)
{
    SymtabEntry *procId = symtabStack->enterLocal(name, kind);
    procId->setRoutineCode(code);

    return procId;
}

}}  // namespace wci::intermediate::symtabimpl
