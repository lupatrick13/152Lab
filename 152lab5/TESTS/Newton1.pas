PROGRAM Newton1;

VAR
    number : integer;
    root, prvv, diff : real;

BEGIN
    FOR number := 1 TO 25 DO BEGIN
        writeln;
        writeln('Square root of ', number);
        writeln;

        root := 1;
        prvv := 0;
        
        REPEAT
            root := (number/root + root)/2;
            diff := root - prvv;
            IF diff < 0 THEN diff := -diff;
            prvv := root;
            
            writeln(root:24:10);
        UNTIL diff < 1.0e-10;
    END
END.

