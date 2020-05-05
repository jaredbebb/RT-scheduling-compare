#include "lst.h"
#include "tasks.h"

/* System timer, SysTick */
#define SYST_CSR      (*( ( volatile unsigned long *) 0xE000E010 )) // SystTick Control and Status Register
#define SYST_RVR    (*( ( volatile unsigned long *) 0xE000E014 )) // SysTick Reload Value Register
// #define SYST_CVR      (*( ( volatile unsigned long *) 0xE000E018 )) // SysTick Current Value Register
// #define SYST_CALIB      (*( ( volatile unsigned long *) 0xE000E01C )) // SysTick Calibration Value Register

/*******SYST_CSR bits*******/
#define SBIT_ENABLE     0
#define SBIT_TICKINT    1
#define SBIT_CLKSOURCE  2

/* 100000000Mhz * 1ms = 1000000 - 1 */
#define RELOAD_VALUE  99999

int main ()
{
		SYST_RVR = RELOAD_VALUE;    // Reload value for 1ms tick
	  /* Enable the Systick, Systick Interrup and select CPU Clock Source */	
		//Tasks t_edf(3);
		Tasks t_lst(3);
		
    int i;
		for(i=0;i<50;i++) {
			SYST_CSR = (1<<SBIT_ENABLE) | (1<<SBIT_TICKINT) | (1<<SBIT_CLKSOURCE);
			//t_edf.runEDF();
			t_lst.runLST(SYST_CSR);
    }
    //while(1){}
}
