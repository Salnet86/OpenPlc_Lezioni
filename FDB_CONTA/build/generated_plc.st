PROGRAM program0
  VAR
    bt1 : BOOL;
    reset : BOOL;
    OT_CV : INT;
    IN_PV : INT := 5;
    led : BOOL;
    CTU0 : CTU;
    R_TRIG1 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := bt1);
  CTU0(CU := R_TRIG1.Q, R := reset, PV := IN_PV);
  led := CTU0.Q;
  OT_CV := CTU0.CV;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
