PROGRAM program0
  VAR
    bt1 : BOOL;
    bt2 : BOOL;
    LED : BOOL;
    SR0 : SR;
  END_VAR

  SR0(S1 := bt1, R := bt2);
  LED := SR0.Q1;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
