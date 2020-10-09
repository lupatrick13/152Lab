PROGRAM TestArray1;

CONST
    max = 9;

TYPE
    vector = ARRAY[0..max] OF integer;
    matrix = ARRAY[0..4, 0..4] OF integer;
    cube   = ARRAY[0..1, 0..2, 0..3] OF integer;

VAR
    i, j, k, n : integer;
    a1         : vector;
    a2         : matrix;
    a3         : cube;

BEGIN
    i := 0; j := 0; k := 0;
END.
