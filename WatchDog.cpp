
#include "WatchDog.h"
#include "Arduino.h"


interrupt_handler myhandler = wdt_default_interrupt_handler ;

void wdt_config(WDT_PERSCALER_t perscaler ,WTD_Mode_t mode)
{
    cli();
   
    WDTCSR |= (1<<WDCE) | (1<<WDE); // work //System reset mode
    
    WDTCSR = (1<<WDCE)  | perscaler;
    if( mode == Mode_Interrupt)
    {
      WDTCSR |= (1<<WDIE) ;// interrupt enable
    }
    else if( mode == Mode_Reset )
    {
      WDTCSR |= (1<<WDCE) | (1<<WDE); // reset mode
    }
    else if( mode == Mode_Interrupt_Reset )
    {
      WDTCSR |= (1<<WDCE) | (1<<WDE) | (1<<WDIE);//interrupt & reset mode 
    }
    
    sei() ;
}

void wdt_reset()
{
  asm("WDR");
}

void wdt_disable()
{
  cli();
  asm("WDR");
  MCUSR=0;
  WDTCSR|=_BV(WDCE) | _BV(WDE);
  WDTCSR=0;
  sei() ;
}

void wdt_default_interrupt_handler()
{
  Serial.println("WDT  interrupt");
}


void wdt_set_interrupt_handler(interrupt_handler new_handler)
{
  myhandler = new_handler ;
}

ISR(WDT_vect)
{
    //wdt_interrupt_handler();
    myhandler() ;
}
