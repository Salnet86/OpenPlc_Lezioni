PROGRAM Test_esem
  VAR
    start AT %M0.0 : BOOL;
    st1 AT %M0.1 : BOOL;
    LED_VERDE AT %Q0.0 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
  END_VAR

  INITIAL_STEP Step0:
    COMPUTE_FUNCTION_BLOCKS(S);
  END_STEP

  ACTION COMPUTE_FUNCTION_BLOCKS:
    TON0(IN := st1, PT := T#10s);
  END_ACTION

  TRANSITION FROM Step0 TO Step1
    := start;
  END_TRANSITION

  STEP Step1:
    LED_VERDE(S);
    st1(N);
  END_STEP

  TRANSITION FROM Step1 TO Step2
    := TON0.Q;
  END_TRANSITION

  STEP Step2:
    LED_VERDE(R);
  END_STEP

  TRANSITION FROM Step2 TO Step0
    := NOT start AND NOT LED_VERDE;
  END_TRANSITION

END_PROGRAM

PROGRAM fdb_t1
  VAR
    set : BOOL;
    reset : BOOL;
    led_verde : BOOL;
    t1 : BOOL;
    SR0 : SR;
    TON0 : TON;
  END_VAR

  SR0(S1 := set, R := t1);
  led_verde := SR0.Q1;
  TON0(IN := SR0.Q1, PT := T#10s);
  t1 := TON0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Test_esem;
  END_RESOURCE
END_CONFIGURATION
