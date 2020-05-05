#include "tasks.h"
#include "scheduling.h"
#include "lst.h"

void read(){
}
void check(){
}
void react(){
}

Tasks::Tasks(int max_loops){
		maxloops = max_loops;
}

void Tasks::sch_add_loop(sch_loop_func_t loop_func){
		for(int i= 0; i < MAX_LOOPS; i++){
				if (maxloops > i){
						sch_loop_funcs[i] = loop_func;
				}
		}
}

void Tasks::runEDF(){
	int p[] = {10,10,11};
	int e[] = {5,10,5};
	int d[] = {40,50,30};
	
	int n = (int)(sizeof(d) / sizeof(d[0]));
	
	sch_loop_func_t functions[] = {read,check,react};
	int frame_size;
	Edf edf;
	frame_size = edf.find_frame_size( p, e, d );
	if(frame_size == -1){
		//frame size constraints not met
		return;
	}
	Scheduling s;
	s.insertionSortByDeadline(functions, p, e, d, n);
	for(int f=0; f < maxloops; f++){
		functions[f]();
	}
}

void Tasks::runLST(int time){
	int e[] = {5,10,5};
	int d[] = {40,50,30};
	
	sch_loop_func_t functions[] = {read,check,react};
	LST lst(d,functions,e,MAX_LOOPS);
	lst.computeSlackArray(time);
	lst.insertionSortBySlack();
	for(int f=0; f < maxloops; f++){
		lst.tasks[f]();
	}
}

