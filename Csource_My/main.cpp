#include "jbtimer.h"

typedef unsigned long uint32_t;
int main ()
{
		jbtimer jt;
		jt.start();
		int counter=0;
    int ii;
    //for(ii=0;ii<305419896;ii++) {
		for(ii=0;ii<1000000;ii++) {
			counter+=1;
			//*((uint32_t *)0x40E00018) = 0x87654321;
			//asm("NOP");

    }
		counter = 13;
    //while(1){}
}
