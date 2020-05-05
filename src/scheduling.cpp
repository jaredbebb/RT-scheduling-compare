#include "scheduling.h"

 
 void Scheduling::insertionSortByDeadline(sch_loop_func_t task[], int period[],int execution[], int deadline[], int n)
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
