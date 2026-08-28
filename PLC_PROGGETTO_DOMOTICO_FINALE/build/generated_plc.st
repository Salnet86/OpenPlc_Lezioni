PROGRAM program0
  VAR
    I_Cucina : BOOL;
    I_Cucina0 : BOOL;
    I_Camera : BOOL;
    I_Sogiorno : BOOL;
    I_Sogiorno0 : BOOL;
    I_Bagno : BOOL;
    I_Dormitorio1 : BOOL;
    I_Dormitorio2 : BOOL;
    I_Dormitorio3 : BOOL;
    P_Salita : BOOL;
    P_Discesa : BOOL;
    P_Stop : BOOL;
    FC_Alto : BOOL;
    FC_Basso : BOOL;
    I_Chiave : BOOL;
    FC_Aperto : BOOL;
    FC_Chiuso : BOOL;
    Fotocellula : BOOL;
    Q_Cucina : BOOL;
    Q_Camera : BOOL;
    Q_Soggiorno : BOOL;
    Q_Bagno : BOOL;
    Q_Dormitorio1 : BOOL;
    Q_Dormitorio2 : BOOL;
    Q_Dormitorio3 : BOOL;
    Q_Discesa : BOOL;
    Q_Salita : BOOL;
    Q_Cancello_Avanti : BOOL;
    Q_Cancello_Indietro : BOOL;
    M_Stato_Cucina : BOOL;
    M_Stato_Camera : BOOL;
    M_Stato_Dormi1 : BOOL;
    M_Stato_Dormi2 : BOOL;
    M_Stato_Dormi3 : BOOL;
    TON0 : TON;
    TON_Q : BOOL;
  END_VAR

  IF NOT(M_Stato_Cucina) AND (I_Cucina OR M_Stato_Cucina) THEN
    M_Stato_Cucina := TRUE; (*set*)
  END_IF;
  Q_Cucina := M_Stato_Cucina;
  IF NOT(M_Stato_Camera) AND (I_Camera OR M_Stato_Camera) THEN
    M_Stato_Camera := TRUE; (*set*)
  END_IF;
  Q_Camera := M_Stato_Cucina;
  IF NOT(M_Stato_Dormi1) AND (I_Dormitorio1 OR M_Stato_Dormi1) THEN
    M_Stato_Dormi1 := TRUE; (*set*)
  END_IF;
  IF NOT(M_Stato_Dormi2) AND (I_Dormitorio2 OR M_Stato_Dormi2) THEN
    M_Stato_Dormi2 := TRUE; (*set*)
  END_IF;
  IF NOT(M_Stato_Dormi3) AND (M_Stato_Dormi3 OR M_Stato_Dormi3) THEN
    M_Stato_Dormi3 := TRUE; (*set*)
  END_IF;
  Q_Dormitorio1 := M_Stato_Dormi1;
  Q_Dormitorio2 := M_Stato_Dormi2;
  Q_Dormitorio3 := M_Stato_Dormi3;
  Q_Salita := NOT(Q_Discesa) AND NOT(FC_Alto) AND NOT(P_Stop) AND (NOT(Q_Salita) OR P_Salita);
  Q_Discesa := NOT(Q_Salita) AND NOT(FC_Basso) AND NOT(P_Stop) AND (NOT(Q_Discesa) OR P_Discesa);
  Q_Cancello_Avanti := NOT(Q_Cancello_Indietro) AND Fotocellula AND NOT(FC_Aperto) AND (I_Chiave OR NOT(Q_Cancello_Avanti));
  TON0(IN := FC_Aperto, PT := T#5000ms);
  TON_Q := TON0.Q;
  Q_Cancello_Indietro := NOT(Q_Cancello_Avanti) AND NOT(Fotocellula) AND NOT(FC_Chiuso) AND (Q_Cancello_Indietro OR TON_Q);
  IF I_Cucina THEN
    M_Stato_Cucina := FALSE; (*reset*)
  END_IF;
  IF I_Camera THEN
    M_Stato_Camera := FALSE; (*reset*)
  END_IF;
  IF I_Dormitorio1 THEN
    M_Stato_Dormi1 := FALSE; (*reset*)
  END_IF;
  IF M_Stato_Dormi2 THEN
    M_Stato_Dormi2 := FALSE; (*reset*)
  END_IF;
  IF M_Stato_Dormi3 THEN
    M_Stato_Dormi3 := FALSE; (*reset*)
  END_IF;
  IF P_Stop THEN
    Q_Salita := FALSE; (*reset*)
  END_IF;
  IF P_Stop THEN
    Q_Discesa := FALSE; (*reset*)
  END_IF;
  IF FC_Alto THEN
    Q_Salita := FALSE; (*reset*)
  END_IF;
  IF FC_Basso THEN
    Q_Salita := FALSE; (*reset*)
  END_IF;
  IF FC_Aperto THEN
    Q_Cancello_Avanti := FALSE; (*reset*)
  END_IF;
  IF FC_Chiuso THEN
    Q_Cancello_Indietro := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
