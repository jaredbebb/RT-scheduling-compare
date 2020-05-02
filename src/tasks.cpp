#include "tasks.h"

void read(){
}
void check(){
}
void react(){
}

void insertionSort(sch_loop_func_t task[], int period[],int execution[], int deadline[], int n)
{
	sch_loop_func_t key_task;
	int i, j, key_period, key_execution, key_deadline;
    for (i = 1; i < n; i++)
    {
    	key_task = task[i];
    	key_period = period[i];
    	key_execution = execution[i];
    	key_deadline = deadline[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && deadline[j] > key_deadline)
        {
        	task[j + 1] = task[j];
        	period[j + 1] = period[j];
        	execution[j + 1] = execution[j];
        	deadline[j + 1] = deadline[j];
            j = j - 1;
        }
        task[j + 1] = key_task;
        period[j + 1] = key_period;
        execution[j + 1] = key_execution;
        deadline[j + 1] = key_deadline;
    }
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

void Tasks::run(){
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
	insertionSort(functions, p, e, d, n);
}

