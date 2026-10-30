PROGRAM program0
  VAR
    bt1 : BOOL;
    led_verde : BOOL;
    T1 : BOOL;
    SR0 : SR;
    TON0 : TON;
  END_VAR

  SR0(S1 := bt1, R := T1);
  led_verde := SR0.Q1;
  TON0(IN := SR0.Q1, PT := T#10s);
  T1 := TON0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
