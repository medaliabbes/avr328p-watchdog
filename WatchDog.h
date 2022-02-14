

#ifndef __AVR_WDT_H__
#define __AVR_WDT_H__



#include "avr/io.h"

typedef enum WTD_Mode
{
  Mode_Interrupt = 0x00, //t
  Mode_Reset , //t
  Mode_Interrupt_Reset //t
}WTD_Mode_t ;

typedef enum WATCH_DOG_TIMEPERSCALER
{
  _16_ms   = 0x00 ,
  _32_ms   = (1<<WDP0) ,
  _64_ms   = (1<<WDP1) ,
  _125_ms  = (1<<WDP0) | (1<<WDP1),
  _250_ms  = (1<<WDP2) ,//t
  _500_ms  = (1<<WDP0) | (1<<WDP2),//t
  _1000_ms = (1<<WDP1) | (1<<WDP2),//t
  _2000_ms = (1<<WDP0) | (1<<WDP1) | (1<<WDP2),//t
  _4000_ms = (1<<WDP3) ,//t
  _8000_ms = (1<<WDP0) | (1<<WDP3)//t
  
}WDT_PERSCALER_t ;

typedef    void (*interrupt_handler)()   ;

void wdt_default_interrupt_handler() ;

void wdt_config(WDT_PERSCALER_t perscaler , WTD_Mode_t);

void wdt_reset() ;

void wdt_disable() ;

void wdt_set_interrupt_handler(interrupt_handler new_handler) ;

#endif
