void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->I_CUCINA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_CUCINA0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_CAMERA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_SOGIORNO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_SOGIORNO0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_BAGNO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_DORMITORIO1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_DORMITORIO2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_DORMITORIO3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P_SALITA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P_DISCESA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P_STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FC_ALTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FC_BASSO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_CHIAVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FC_APERTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FC_CHIUSO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FOTOCELLULA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_CUCINA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_CAMERA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_SOGGIORNO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_BAGNO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_DORMITORIO1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_DORMITORIO2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_DORMITORIO3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_DISCESA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_SALITA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_CANCELLO_AVANTI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q_CANCELLO_INDIETRO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_STATO_CUCINA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_STATO_CAMERA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_STATO_DORMI1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_STATO_DORMI2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_STATO_DORMI3,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->TON_Q,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  if ((!(__GET_VAR(data__->M_STATO_CUCINA,)) && (__GET_VAR(data__->I_CUCINA,) || __GET_VAR(data__->M_STATO_CUCINA,)))) {
    __SET_VAR(data__->,M_STATO_CUCINA,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,Q_CUCINA,,__GET_VAR(data__->M_STATO_CUCINA,));
  if ((!(__GET_VAR(data__->M_STATO_CAMERA,)) && (__GET_VAR(data__->I_CAMERA,) || __GET_VAR(data__->M_STATO_CAMERA,)))) {
    __SET_VAR(data__->,M_STATO_CAMERA,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,Q_CAMERA,,__GET_VAR(data__->M_STATO_CUCINA,));
  if ((!(__GET_VAR(data__->M_STATO_DORMI1,)) && (__GET_VAR(data__->I_DORMITORIO1,) || __GET_VAR(data__->M_STATO_DORMI1,)))) {
    __SET_VAR(data__->,M_STATO_DORMI1,,__BOOL_LITERAL(TRUE));
  };
  if ((!(__GET_VAR(data__->M_STATO_DORMI2,)) && (__GET_VAR(data__->I_DORMITORIO2,) || __GET_VAR(data__->M_STATO_DORMI2,)))) {
    __SET_VAR(data__->,M_STATO_DORMI2,,__BOOL_LITERAL(TRUE));
  };
  if ((!(__GET_VAR(data__->M_STATO_DORMI3,)) && (__GET_VAR(data__->M_STATO_DORMI3,) || __GET_VAR(data__->M_STATO_DORMI3,)))) {
    __SET_VAR(data__->,M_STATO_DORMI3,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,Q_DORMITORIO1,,__GET_VAR(data__->M_STATO_DORMI1,));
  __SET_VAR(data__->,Q_DORMITORIO2,,__GET_VAR(data__->M_STATO_DORMI2,));
  __SET_VAR(data__->,Q_DORMITORIO3,,__GET_VAR(data__->M_STATO_DORMI3,));
  __SET_VAR(data__->,Q_SALITA,,(((!(__GET_VAR(data__->Q_DISCESA,)) && !(__GET_VAR(data__->FC_ALTO,))) && !(__GET_VAR(data__->P_STOP,))) && (!(__GET_VAR(data__->Q_SALITA,)) || __GET_VAR(data__->P_SALITA,))));
  __SET_VAR(data__->,Q_DISCESA,,(((!(__GET_VAR(data__->Q_SALITA,)) && !(__GET_VAR(data__->FC_BASSO,))) && !(__GET_VAR(data__->P_STOP,))) && (!(__GET_VAR(data__->Q_DISCESA,)) || __GET_VAR(data__->P_DISCESA,))));
  __SET_VAR(data__->,Q_CANCELLO_AVANTI,,(((!(__GET_VAR(data__->Q_CANCELLO_INDIETRO,)) && __GET_VAR(data__->FOTOCELLULA,)) && !(__GET_VAR(data__->FC_APERTO,))) && (__GET_VAR(data__->I_CHIAVE,) || !(__GET_VAR(data__->Q_CANCELLO_AVANTI,)))));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->FC_APERTO,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 5000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,TON_Q,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->,Q_CANCELLO_INDIETRO,,(((!(__GET_VAR(data__->Q_CANCELLO_AVANTI,)) && !(__GET_VAR(data__->FOTOCELLULA,))) && !(__GET_VAR(data__->FC_CHIUSO,))) && (__GET_VAR(data__->Q_CANCELLO_INDIETRO,) || __GET_VAR(data__->TON_Q,))));
  if (__GET_VAR(data__->I_CUCINA,)) {
    __SET_VAR(data__->,M_STATO_CUCINA,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->I_CAMERA,)) {
    __SET_VAR(data__->,M_STATO_CAMERA,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->I_DORMITORIO1,)) {
    __SET_VAR(data__->,M_STATO_DORMI1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->M_STATO_DORMI2,)) {
    __SET_VAR(data__->,M_STATO_DORMI2,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->M_STATO_DORMI3,)) {
    __SET_VAR(data__->,M_STATO_DORMI3,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->P_STOP,)) {
    __SET_VAR(data__->,Q_SALITA,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->P_STOP,)) {
    __SET_VAR(data__->,Q_DISCESA,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->FC_ALTO,)) {
    __SET_VAR(data__->,Q_SALITA,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->FC_BASSO,)) {
    __SET_VAR(data__->,Q_SALITA,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->FC_APERTO,)) {
    __SET_VAR(data__->,Q_CANCELLO_AVANTI,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->FC_CHIUSO,)) {
    __SET_VAR(data__->,Q_CANCELLO_INDIETRO,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





