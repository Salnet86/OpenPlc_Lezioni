PROGRAM program0
  VAR
    bt1 : BOOL;
    bt2 : BOOL;
    led : BOOL;
    timer_ok : BOOL;
    tmer1 : TON;
    sr1 : SR;
  END_VAR

  tmer1(
      IN := bt1,
      PT := T#5s,
      Q => timer_ok
  );

  sr1(
      S1 := timer_ok,
      R := bt2,
      Q1 => led
  );
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
