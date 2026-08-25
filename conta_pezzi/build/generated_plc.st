PROGRAM program0
  VAR
    CTU0 : CTU;
    CU : BOOL;
    PULSE : BOOL;
    Q : BOOL;
    Reset : BOOL;
    Preset_value : INT := 5;
    R_TRIG1 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := PULSE AND CU);
  CTU0(CU := R_TRIG1.Q, R := Reset, PV := Preset_value);
  Q := CTU0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
