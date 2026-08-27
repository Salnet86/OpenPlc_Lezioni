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
  __INIT_VAR(data__->BT1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BT2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMER_OK,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TMER1,retain);
  SR_init__(&data__->SR1,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TMER1.,IN,,__GET_VAR(data__->BT1,));
  __SET_VAR(data__->TMER1.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TON_body__(&data__->TMER1);
  __SET_VAR(data__->,TIMER_OK,,__GET_VAR(data__->TMER1.Q));
  __SET_VAR(data__->SR1.,S1,,__GET_VAR(data__->TIMER_OK,));
  __SET_VAR(data__->SR1.,R,,__GET_VAR(data__->BT2,));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->,LED,,__GET_VAR(data__->SR1.Q1));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





