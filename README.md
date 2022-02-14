

  this code writen and tested with the arduino platform 
  
  
  support watchdog mode : 
  
	interrupt : whene the wdt counter reach it maximum an interrupt is generated and an interrept 
				handler is executed 
				the interrupt handler can be defined using wdt_set_interrupt_handler() wich take 
				a function ( void func_name() ) as parameter   
				
	reset     : whene the wdt counter reach it maximum the microcontroller reset and start the program again
		    unless wdt_reset() is called before the wdt counter reach it max value
				
	
	interrupt-reset : in this mode an interrupt is excuted then the microcontoller reset  
	
	
	note : 
	   
	       - wdt_config function will configure the watchdog and enable it 
		
	       - any call to wdt_reset will reset the watchdog and prevent eny interrupt or reset so the program 
	         will continue the normal execution 
		
	       - the interrupt mode can be is useful in low power mode , some modes support watchdog wake up
