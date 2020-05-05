/*
 * rt_requirements.c
 *
 *  Created on: Mar 9, 2020
 *      Author: Jared
 */
#include "utilities.h"

class Edf {
		private:
			
		public:
				int find_frame_size( int p[], int e[], int D[] );
};

class Scheduler{
		private:
				//uint8_t sch_loop_funcs_on_overriden[MAX_LOOPS];
				//sch_loop_func_t sch_loop_funcs_overriden[MAX_LOOPS];
				int sch_loop_funcs_period[MAX_LOOPS];
				int sch_loop_funcs_execution[MAX_LOOPS];
				int sch_loop_funcs_deadline[MAX_LOOPS];
		public:
				int sch_add_loop( sch_loop_func_t loop_func, int period, int execution, int deadline );
};





