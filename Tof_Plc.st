VAR
S1 : BOOL;
LED : BOOL;
TOF1 : TOF;
END_VAR

TOF1(IN := S1, PT := T#5s);

LED := TOF1.Q;