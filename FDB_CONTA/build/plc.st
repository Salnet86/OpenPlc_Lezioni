TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


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
