
#include "WatchDog.h"



/*
  code test with arduino uno board 
  all mode tested 
  
*/

void wdt_interrupt_handler() 
{
  Serial.println("wdt");
}

uint32_t tmr ;
bool b = true ;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ;
  Serial.println("p start");

  wdt_set_interrupt_handler((interrupt_handler)wdt_interrupt_handler) ;
  wdt_config(_2000_ms , Mode_Interrupt_Reset);
  tmr = millis() ;
}

void loop() {

  if(millis() - tmr > 10000 && b)
  {
    Serial.println("disable wdt interrupt") ;
    wdt_disable() ;
    b = false ;
  }
 //wdt_reset() ;
}
