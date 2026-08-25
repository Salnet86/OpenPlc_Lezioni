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
    Papre : BOOL;
    Pstop : BOOL;
    FR1 : BOOL;
    FCaperto : BOOL;
    Pchiude : BOOL;
    FR2 : BOOL;
    FCchiuso : BOOL;
    FT1 : BOOL;
    M_0_0 : BOOL;
    M_0_1 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
  END_VAR
  VAR
    T37 : BOOL;
  END_VAR
  VAR
    TON1 : TON;
  END_VAR
  VAR
    T38 : BOOL;
  END_VAR

  IF Papre THEN
    M_0_0 := TRUE; (*set*)
  END_IF;
  IF FCaperto OR FR1 OR Pstop THEN
    M_0_0 := FALSE; (*reset*)
  END_IF;
  TON0(IN := FCaperto, PT := T#1000ms);
  T37 := TON0.Q;
  IF Pchiude OR T37 THEN
    M_0_1 := TRUE; (*set*)
  END_IF;
  IF FCchiuso OR FR2 OR Pstop THEN
    M_0_1 := FALSE; (*reset*)
  END_IF;
  TON1(IN := FT1, PT := T#1000ms);
  T38 := TON1.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
