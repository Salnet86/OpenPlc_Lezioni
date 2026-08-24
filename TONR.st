VAR
    S1 : BOOL;
    RESET : BOOL;
    LED : BOOL;
    TONR1 : TONR;
END_VAR


TONR1(IN := S1, R := RESET, PT := T#10s);


IF TONR1.Q THEN
    LED := TRUE;
ELSE
    LED := FALSE;
END_IF;