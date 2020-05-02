/*
 * rt_requirements.c
 *
 *  Created on: Mar 9, 2020
 *      Author: Jared
 */


#define SCH_FUNC_OFF	0
#define SCH_FUNC_ON		1

typedef void ( * sch_loop_func_t)(void);

#define MAX_LOOPS		10
typedef unsigned long uint32_t;
typedef unsigned long uint8_t;

class Edf {
		private:
			
		public:
				int find_frame_size( int p[], int e[], int D[] );
};

class Scheduler{
		private:
				//uint8_t sch_loop_funcs_on_overriden[MAX_LOOPS];
				//sch_loop_func_t sch_loop_funcs_overriden[MAX_LOOPS];
				uint8_t sch_loop_funcs_period[MAX_LOOPS];
				uint8_t sch_loop_funcs_execution[MAX_LOOPS];
				uint8_t sch_loop_funcs_deadline[MAX_LOOPS];
		public:
				uint8_t sch_add_loop( sch_loop_func_t loop_func, uint8_t period, uint8_t execution, uint8_t deadline );
};





