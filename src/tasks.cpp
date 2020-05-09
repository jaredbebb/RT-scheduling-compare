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

void Tasks::runEDFAlg(){
	p[0] = 10;
	p[1] = 10;
	p[2] = 11;
	e[0] = 5;
	e[1]=10;
	e[2]=5;
	d[0] = 40;
	d[1] =50;
	d[2] =30;
	
	int n = (int)(sizeof(d) / sizeof(d[0]));
	sch_loop_func_t f[] = {read,check,react};
	for(int i=0; i < maxloops; i++){
		functions[i] = f[i];
	}
	//functions[0] = read;
	//functions[0] = check;
	//functions[0] = react;
	int frame_size;
	Edf edf;
	frame_size = edf.find_frame_size( p, e, d );
	if(frame_size == -1){
		//frame size constraints not met
		return;
	}
	Scheduling s;
	s.insertionSortByDeadline(functions, p, e, d, n);
}

void Tasks::runTasks(){
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

