PROGRAM TestArray3;

TYPE
    matrix = ARRAY[0..4, 0..4] OF real;

VAR
    M : matrix;
    i, j : integer;

BEGIN
    writeln(M[i][j]:6:2);
END.
