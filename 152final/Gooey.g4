grammar Gooey;

@header {
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;
}

program           : programHeader block;
programHeader     : GOOEY title ';' ; 

finish :
	FIN;
title   locals [ SymtabEntry *entry = nullptr ]
    : IDENTIFIER ;

block         	: declarations '.' (functiondef '.')? MAIN ':'compoundStatement finish;

declarations locals [ SymtabEntry *entry = nullptr ]	
	: VAR ':' variableDeclarationsList ;

variableDeclarationsList : variableDeclarations ( ';' variableDeclarations)* ';';
variableDeclarations 	: types variableIdentifierList;
variableIdentifierList	: variableIdentifier ( ',' variableIdentifier)*;
variableIdentifier		locals [Typespec *type = nullptr, SymtabEntry *entry]
						: IDENTIFIER modifier?;
	
types locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]  
	: IDENTIFIER;	
	
functiondef : FUNC ':' (funcDec)*;
funcDec locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
	: returnType functionName parameter '{' declarations? statement '}' ;
	
parameter			: '(' parameterDecList? ')' ;
parameterDecList 	: parameterDec (';' parameterDec)* ;
parameterDec		: types parameterIdList;
parameterIdList		: parameterId (','parameterId)*;
parameterId			locals [Typespec *type = nullptr, SymtabEntry *entry = nullptr]
					: IDENTIFIER;

returnType locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
:	IDENTIFIER;

variable locals [Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
	: IDENTIFIER modifier?;
	
modifier : '[' INTEGER ']';
sign : '-' | '+' ;
functionCall : functionName '(' argumentList? ')';
procedureCall : functionName '(' argumentList? ')';
functionName    locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ] 
    : IDENTIFIER ;
argumentList : argument ( ',' argument )* ;
argument     : expression ;

statement : compoundStatement
          | assignmentStatement
          | ifStatement
          | whileStatement
          | forStatement
          | emptyStatement
          | procedureCall
          | predefinedRoutineCall
          ;

predefinedRoutineCall locals [SymtabEntry *routine = nullptr]
					:	variable '.' predefinedRoutine '(' argumentList? ')';
predefinedRoutine	: CREATE
					| ADD
					| FINISH;
compoundStatement : '{' statementList '}';
emptyStatement : ;
     
statementList       : statement ( ';' statement )* ;
assignmentStatement : lhs '=' rhs ';'?;

lhs                 locals [ Typespec *type = nullptr ] 
    : variable ;
rhs : expression ;

ifStatement    : IF expression '{' statement '}' ( ELSE '{' statement '}')? ;

whileStatement  : WHILE '(' expression ')' '{' statement '}' ;

forStatement : FOR '(' variable '=' expression TO expression')' '{' statement '}';

expression          locals [ Typespec *type = nullptr, SymtabEntry *entry ] 
    : simpleExpression (relOp simpleExpression)? ;
    
simpleExpression    locals [ Typespec *type = nullptr ] 
    : sign? term (addOp term)* ;
    
term                locals [ Typespec *type = nullptr ]
    : factor (mulOp factor)* ;

factor              locals [ Typespec *type = nullptr ] 
    : variable             # variableFactor
    | number               # numberFactor
    | characterConstant    # characterFactor
    | stringConstant       # stringFactor
    | functionCall         # functionCallFactor
    | '!' factor           # notFactor
    | '(' expression ')'   # parenthesizedFactor
    ;

     
number          : sign? unsignedNumber ;
unsignedNumber  : REAL | INTEGER ;

characterConstant : CHARACTER ;
stringConstant    : STRING ;
       
relOp : '=' | '!=' | '<' | '<=' | '>' | '>=' ;
addOp : '+' | '-' | OR ;
mulOp : '*' | '/' | AND ;

fragment A : ('a' | 'A') ;
fragment B : ('b' | 'B') ;
fragment C : ('c' | 'C') ;
fragment D : ('d' | 'D') ;
fragment E : ('e' | 'E') ;
fragment F : ('f' | 'F') ;
fragment G : ('g' | 'G') ;
fragment H : ('h' | 'H') ;
fragment I : ('i' | 'I') ;
fragment J : ('j' | 'J') ;
fragment K : ('k' | 'K') ;
fragment L : ('l' | 'L') ;
fragment M : ('m' | 'M') ;
fragment N : ('n' | 'N') ;
fragment O : ('o' | 'O') ;
fragment P : ('p' | 'P') ;
fragment Q : ('q' | 'Q') ;
fragment R : ('r' | 'R') ;
fragment S : ('s' | 'S') ;
fragment T : ('t' | 'T') ;
fragment U : ('u' | 'U') ;
fragment V : ('v' | 'V') ;
fragment W : ('w' | 'W') ;
fragment X : ('x' | 'X') ;
fragment Y : ('y' | 'Y') ;
fragment Z : ('z' | 'Z') ;

GOOEY  		: G O O E Y; 
AND			: A N D ;
OR			: O R;
WHILE		: W H I L E;
FOR			: F O R;
IF			: I F ;
ELSE		: E L S E;
TO			: T O;
BY			: B Y;
VAR			: V A R;
FUNC		: F U N C;
FIN			: F I N;
MAIN 		: M A I N;
CREATE		: C R E A T E;
ADD			: A D D;
FINISH		: F I N I S H;

IDENTIFIER : [a-zA-Z][a-zA-Z0-9]* ;
INTEGER    : [0-9]+ ;

REAL       : INTEGER '.' INTEGER ;

NEWLINE : '\r'? '\n' -> skip  ;
WS      : [ \t]+ -> skip ; 

QUOTE     : '"' ;
CHARACTER : QUOTE CHARACTER_CHAR QUOTE ;
STRING    : QUOTE STRING_CHAR* QUOTE ;

fragment CHARACTER_CHAR : ~('\'')   // any non-quote character
                        ;

fragment STRING_CHAR : QUOTE QUOTE  // two consecutive quotes
                     | ~('"')      // any non-quote character
                     ;

COMMENT : '//' COMMENT_CHARACTER* -> skip ;

fragment COMMENT_CHARACTER : ~('\n') ;
                     