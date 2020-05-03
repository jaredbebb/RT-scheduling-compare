#include "lst.h"

/*
slack = (d-t)-c
d=process deadline
t= the real time since the cycle start
c=the time required to complete the remaining portion of the job 
*/
int LST::slack(int d, int t, int c){
	return (d-t)-c;
}
