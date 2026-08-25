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
  __INIT_VAR(data__->PAPRE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PSTOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FR1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FCAPERTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PCHIUDE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FR2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FCCHIUSO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FT1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_0_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_0_1,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->T37,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON1,retain);
  __INIT_VAR(data__->T38,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  if (__GET_VAR(data__->PAPRE,)) {
    __SET_VAR(data__->,M_0_0,,__BOOL_LITERAL(TRUE));
  };
  if (((__GET_VAR(data__->FCAPERTO,) || __GET_VAR(data__->FR1,)) || __GET_VAR(data__->PSTOP,))) {
    __SET_VAR(data__->,M_0_0,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->FCAPERTO,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,T37,,__GET_VAR(data__->TON0.Q,));
  if ((__GET_VAR(data__->PCHIUDE,) || __GET_VAR(data__->T37,))) {
    __SET_VAR(data__->,M_0_1,,__BOOL_LITERAL(TRUE));
  };
  if (((__GET_VAR(data__->FCCHIUSO,) || __GET_VAR(data__->FR2,)) || __GET_VAR(data__->PSTOP,))) {
    __SET_VAR(data__->,M_0_1,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->FT1,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,T38,,__GET_VAR(data__->TON1.Q,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





