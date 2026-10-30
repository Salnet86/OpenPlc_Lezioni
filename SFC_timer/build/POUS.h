#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM TEST_ESEM
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,ST1)
  __DECLARE_VAR(BOOL,LED_VERDE)
  TON TON0;
  STEP __step_list[3];
  UINT __nb_steps;
  ACTION __action_list[3];
  UINT __nb_actions;
  __IEC_BOOL_t __transition_list[3];
  __IEC_BOOL_t __debug_transition_list[3];
  UINT __nb_transitions;
  TIME __lasttick_time;

} TEST_ESEM;

void TEST_ESEM_init__(TEST_ESEM *data__, BOOL retain);
// Code part
void TEST_ESEM_body__(TEST_ESEM *data__);
// PROGRAM FDB_T1
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,LED_VERDE)
  __DECLARE_VAR(BOOL,T1)
  SR SR0;
  TON TON0;

} FDB_T1;

void FDB_T1_init__(FDB_T1 *data__, BOOL retain);
// Code part
void FDB_T1_body__(FDB_T1 *data__);
#endif //__POUS_H
