#include "utilities.h"
#include "edf.h"

class Tasks {
	private:
		int maxloops;
		sch_loop_func_t sch_loop_funcs[10];
	public:
		Tasks(int max_loops);
	
		int p[3];
		int e[3];
		int d[3];
		sch_loop_func_t functions[3];
	
		void runEDFAlg();
		void runTasks();
		void runLST(int time);
		void sch_add_loop(sch_loop_func_t loop_func);
};
