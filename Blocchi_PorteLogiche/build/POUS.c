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
  __INIT_VAR(data__->P1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT18_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_AND1_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->P1,),
    (BOOL)__GET_VAR(data__->P2,)));
  __SET_VAR(data__->,LED1,,__GET_VAR(data__->_TMP_AND1_OUT,));
  __SET_VAR(data__->,_TMP_OR2_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->P3,),
    (BOOL)__GET_VAR(data__->P4,)));
  __SET_VAR(data__->,LED2,,__GET_VAR(data__->_TMP_OR2_OUT,));
  __SET_VAR(data__->,_TMP_AND10_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->P5,),
    (BOOL)__GET_VAR(data__->P6,)));
  __SET_VAR(data__->,LED2,,__GET_VAR(data__->_TMP_AND10_OUT,));
  __SET_VAR(data__->,_TMP_NOT18_OUT,,!(__GET_VAR(data__->P7,)));
  __SET_VAR(data__->,LED4,,__GET_VAR(data__->_TMP_NOT18_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





