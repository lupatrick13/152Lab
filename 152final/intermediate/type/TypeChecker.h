/**
 * <h1>TypeChecker</h1>
 *
 * <p>Perform type checking.</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef TYPECHECKER_H_
#define TYPECHECKER_H_

#include "intermediate/type/Typespec.h"

namespace intermediate { namespace type {

using namespace std;
using namespace intermediate::type;

class TypeChecker
{
public:
    /**
     * Check if a type specification is integer.
     * @param typespec the type specification to check.
     * @return true if integer, else false.
     */
    static bool isInteger(Typespec *typespec);

    /**
     * Check if both type specifications are integer.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if both are integer, else false.
     */
    static bool areBothInteger(Typespec *typespec1, Typespec *typespec2);

    /**
     * Check if a type specification is real.
     * @param typespec the type specification to check.
     * @return true if real, else false.
     */
    static bool isReal(Typespec *typespec);

    /**
     * Check if a type specification is integer or real.
     * @param typespec the type specification to check.
     * @return true if integer or real, else false.
     */
    static bool isIntegerOrReal(Typespec *typespec);

    /**
     * Check if at least one of two type specifications is real.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if at least one is real, else false.
     */
    static bool isAtLeastOneReal(Typespec *typespec1, Typespec *typespec2);

    /**
     * Check if a type specification is boolean.
     * @param type the type specification to check.
     * @return true if boolean, else false.
     */
    static bool isBoolean(Typespec *typespec);

    /**
     * Check if both type specifications are boolean.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if both are boolean, else false.
     */

    static bool areBothBoolean(Typespec *typespec1, Typespec *typespec2);

    /**
     * Check if a type specification is char.
     * @param type the type specification to check.
     * @return true if char, else false.
     */
    static bool isChar(Typespec *typespec);

    /**
     * Check if a type specification is string.
     * @param type the type specification to check.
     * @return true if boolean, else false.
     */
    static bool isString(Typespec *typespec);

    /**
     * Check if both type specifications are string.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if both are boolean, else false.
     */
    static bool isAtLeastOneString(Typespec *typespec1, Typespec *typespec2);
    static bool areBothString(Typespec *typespec1, Typespec *typespec2);

    /**
     * Check if two type specifications are assignment compatible.
     * @param targetTypespec the target type specification.
     * @param value_typespec the value type specification.
     * @return true if the value can be assigned to the target, else false.
     */
    static bool areAssignmentCompatible(Typespec *targetTypespec,
                                        Typespec *valueTypespec);

    /**
     * Check if two type specifications are comparison compatible.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if the types can be compared to each other, else false.
     */
    static bool areComparisonCompatible(Typespec *typespec1,
                                        Typespec *typespec2);
};

}}  // namespace intermediate::type

#endif /* TYPECHECKER_H_ */
