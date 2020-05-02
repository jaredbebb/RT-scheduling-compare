#include "edf.h"

class Tasks {
	private:
		int maxloops;
		sch_loop_func_t sch_loop_funcs[10];
	public:
		Tasks(int max_loops);
		void run();
		void sch_add_loop(sch_loop_func_t loop_func);
};
