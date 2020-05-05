#include <vector>
#include "utilities.h"

class LST {
	
	private:
		int length;
		int max_loops;

	public:
		LST(int d[], sch_loop_func_t t[],int e[], int n);
		int slack(int d, int t, int e);
		void computeSlackArray(int time);
		void insertionSortBySlack();

		int deadline[3];
		int execution [3];
		int release [3];
		int slacktime [3];
		sch_loop_func_t tasks [3];
	

	
};
