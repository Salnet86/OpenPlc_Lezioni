VAR
    S1 : BOOL;
    LED : BOOL;
    TP1 : TP;
END_VAR


TP1(IN := S1, PT := T#5s);


IF TP1.Q THEN
    LED := TRUE;
ELSE
    LED := FALSE;
END_IF;