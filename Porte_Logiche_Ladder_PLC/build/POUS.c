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
  __INIT_LOCATED(BOOL,__IX100_0,data__->A1,retain)
  __INIT_LOCATED_VALUE(data__->A1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_1,data__->A2,retain)
  __INIT_LOCATED_VALUE(data__->A2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_0,data__->Q0,retain)
  __INIT_LOCATED_VALUE(data__->Q0,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_2,data__->A3,retain)
  __INIT_LOCATED_VALUE(data__->A3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_3,data__->A4,retain)
  __INIT_LOCATED_VALUE(data__->A4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_1,data__->Q1,retain)
  __INIT_LOCATED_VALUE(data__->Q1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_4,data__->A5,retain)
  __INIT_LOCATED_VALUE(data__->A5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_5,data__->A6,retain)
  __INIT_LOCATED_VALUE(data__->A6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_6,data__->A7,retain)
  __INIT_LOCATED_VALUE(data__->A7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_7,data__->A8,retain)
  __INIT_LOCATED_VALUE(data__->A8,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_2,data__->Q2,retain)
  __INIT_LOCATED_VALUE(data__->Q2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_8,data__->A9,retain)
  __INIT_LOCATED_VALUE(data__->A9,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_9,data__->A10,retain)
  __INIT_LOCATED_VALUE(data__->A10,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_3,data__->Q3,retain)
  __INIT_LOCATED_VALUE(data__->Q3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_10,data__->A11,retain)
  __INIT_LOCATED_VALUE(data__->A11,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_11,data__->A12,retain)
  __INIT_LOCATED_VALUE(data__->A12,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_4,data__->Q4,retain)
  __INIT_LOCATED_VALUE(data__->Q4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX100_12,data__->A13,retain)
  __INIT_LOCATED_VALUE(data__->A13,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX100_5,data__->Q5,retain)
  __INIT_LOCATED_VALUE(data__->Q5,__BOOL_LITERAL(FALSE))
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_LOCATED(data__->,Q0,,(__GET_LOCATED(data__->A2,) && __GET_LOCATED(data__->A1,)));
  __SET_LOCATED(data__->,Q1,,(__GET_LOCATED(data__->A3,) || __GET_LOCATED(data__->A4,)));
  __SET_LOCATED(data__->,Q2,,((__GET_LOCATED(data__->A6,) && !(__GET_LOCATED(data__->A5,))) || (!(__GET_LOCATED(data__->A8,)) && __GET_LOCATED(data__->A7,))));
  __SET_LOCATED(data__->,Q3,,(!(__GET_LOCATED(data__->A10,)) && !(__GET_LOCATED(data__->A9,))));
  __SET_LOCATED(data__->,Q4,,(!(__GET_LOCATED(data__->A11,)) || !(__GET_LOCATED(data__->A12,))));
  __SET_LOCATED(data__->,Q5,,!(__GET_LOCATED(data__->A13,)));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





