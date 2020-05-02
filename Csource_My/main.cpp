#include "tasks.h"

int main ()
{
		Tasks t(10);
		int counter=0;
    int ii;
		//1,000,000 loops
		for(ii=0;ii<100000;ii++) {
			counter+=1;
			t.run();

    }
		counter = 13;
    //while(1){}

}
