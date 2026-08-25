PROGRAM program0
  VAR
    Papre AT %IX100.0 : BOOL;
    Pstop AT %IX100.1 : BOOL;
    FR1 AT %IX100.2 : BOOL;
    FCaperto AT %IX100.3 : BOOL;
    Pchiude AT %IX100.4 : BOOL;
    FR2 AT %IX100.5 : BOOL;
    FCchiuso AT %IX100.6 : BOOL;
    FT1 AT %IX100.7 : BOOL;
    M_0_0 AT %MX0.0 : BOOL;
    M_0_1 AT %MX0.1 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
  END_VAR
  VAR
    T37 AT %QX100.0 : BOOL;
  END_VAR
  VAR
    TON1 : TON;
  END_VAR
  VAR
    T38 AT %QX100.1 : BOOL;
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
