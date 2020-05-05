#include "lst.h"

LST::LST(int d[], sch_loop_func_t t[],int e[],int n){
		max_loops = n;
		for(int i=0; i < max_loops; i++){
				deadline[i] = d[i];
				tasks[i] = t[i];
				execution[i]=e[i];
		}
}

/*
slack = d-t-(e-t)
d=process deadline
t= the real time since the cycle start
e= execution time
*/
int LST::slack(int d, int t, int e){
	return d-t-(e-t);
}

void LST::computeSlackArray(int time){
		int s;		
		for(int d = 0; d < max_loops; d++){
				s = slack(deadline[d],time,execution[d]);
				slacktime[d] = s;
		}
}

void LST::insertionSortBySlack(){
		sch_loop_func_t key_task;
		int i, j, key_slack;
		for (i = 1; i < max_loops; i++){
				key_task = tasks[i];
				key_slack = slacktime[i];
				j = i - 1;

				/* Move elements of arr[0..i-1], that are
				greater than key, to one position ahead
				of their current position */
				while (j >= 0 && slacktime[j] > key_slack){
						tasks[j + 1] = tasks[j];
						slacktime[j + 1] = slacktime[j];
						j = j - 1;
				}
				tasks[j + 1] = key_task;
				slacktime[j + 1] = key_slack;
		}
}


