VAR
    S1 : BOOL;
    LED : BOOL;
    TOF1 : TOF;
END_VAR


TOF1(IN := S1, PT := T#5s);


IF TOF1.Q THEN
    LED := TRUE;
ELSE
    LED := FALSE;
END_IF;