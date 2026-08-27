PROGRAM program0
  VAR
    BT1 : BOOL;
    BT2 : BOOL;
    LED : BOOL;
    SR0 : SR;
    TP0 : TP;
  END_VAR

  TP0(IN := BT1, PT := T#5s);
  SR0(S1 := TP0.Q, R := BT2);
  LED := SR0.Q1;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
