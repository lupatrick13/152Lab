/**
 * <h1>Predefined</h1>
 *
 * <p>Enter the predefined Pascal types, identifiers, and constants
 * into the symbol table.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef PREDEFINED_H_
#define PREDEFINED_H_

#include <vector>

#include "../../Object.h"
#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"

namespace intermediate { namespace symtab {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Predefined
{
public:
    // Predefined types.
    static Typespec *integerType;
    static Typespec *realType;
    static Typespec *booleanType;
    static Typespec *charType;
    static Typespec *stringType;
    static Typespec *buttonType;
    static Typespec *labelType;
    static Typespec *panelType;
    static Typespec *textType;
    static Typespec *undefinedType;

    // Predefined identifiers.
    static SymtabEntry *integerId;
    static SymtabEntry *realId;
    static SymtabEntry *booleanId;
    static SymtabEntry *charId;
    static SymtabEntry *stringId;
    static SymtabEntry *buttonId;
    static SymtabEntry *labelId;
    static SymtabEntry *panelId;
    static SymtabEntry *textId;
    static SymtabEntry *falseId;
    static SymtabEntry *trueId;
    static SymtabEntry *roundId;
    static SymtabEntry *succId;
    static SymtabEntry *truncId;
    static SymtabEntry *createId;
    static SymtabEntry *addId;
    static SymtabEntry *finishId;


    /**
     * Initialize a symbol table stack with predefined identifiers.
     * @param symTab the symbol table stack to initialize.
     */
    static void initialize(SymtabStack *symtabStack);

private:
    /**
     * Initialize the predefined types.
     * @param symtabStack the symbol table stack to initialize.
     */
    static void initializeTypes(SymtabStack *symtabStack);

    /**
     * Initialize the predefined constant.
     * @param symtabStack the symbol table stack to initialize.
     */
    static void initializeConstants(SymtabStack *symtabStack);

    /**
     * Initialize the standard procedures and functions.
     * @param symtabStack the symbol table stack to initialize.
     */
    static void initializeStandardRoutines(SymtabStack *symtabStack);

    /**
     * Enter a standard procedure or function into the symbol table stack.
     * @param symTabStack the symbol table stack to initialize.
     * @param defn either PROCEDURE or FUNCTION.
     * @param name the procedure or function name.
     */
    static SymtabEntry *enterStandard(SymtabStack *symtabStack,
                                      const Kind kind, const string name,
                                      const Routine code);
};

}}  // namespace intermediate::symtab

#endif /* PREDEFINED_H_ */
