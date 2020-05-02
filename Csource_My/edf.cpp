#include "edf.h"



/**
 * Assume clock driven, cyclic scheduling
 */

uint8_t Scheduler::sch_add_loop( sch_loop_func_t loop_func, uint8_t period, uint8_t execution, uint8_t deadline )
{

	//uint8_t i = SCH_NO_TIMEOUT_ID;
	uint8_t i = 0;
	for( i= 0; i < MAX_LOOPS; i++)
	{
		//if (sch_loop_funcs_on_overriden[i] == SCH_FUNC_OFF)
		//{
		//	break;
		//}
	}
	//if (MAX_LOOPS > i)
	//{
	//	sch_loop_funcs_overriden[i] = loop_func;
	//	sch_loop_funcs_on_overriden[i] = SCH_FUNC_ON;

		sch_loop_funcs_period[i] = period;
		sch_loop_funcs_execution[i] = execution;
		sch_loop_funcs_deadline[i] = deadline;

		return i;
	//}
	// else not found free space
	//return 	SCH_NO_TIMEOUT_ID;
}

int min(int x, int y){
	return y ^ ((x ^ y) & -(x < y));
}

int maximum(int arr[], int n){
	int max;
	max = arr[0];
	for(int i = 1; i < n; i++){
		if (arr[i] >= max){
			max = arr[i];
		}
	}
	return max;

}

int gcd_3(int a, int b, int c){
	int limit;
	limit = min(a,b);
	limit = min(limit, c);
    for(int n = (int)limit; n >= 2; n--)
	{
		if ( (a % n == 0) && (b % n == 0) && (c % n == 0) ) {
			return n;
		}
	}
    return 1;
}

int gcd(int a, int b){
	int limit;
	limit = min(a,b);
	for(int n = (int)limit; n >= 2; n--)
	{
		if ( (a % n == 0) && (b % n == 0)) {
			return n;
		}
	}
    return 1;
}

int lcm(int a, int b, int c){
	int ans;
	ans = a;
	ans = (ans*b)/(gcd(ans, b));
	ans = (ans*c)/(gcd(ans, c));
	return ans;
}

int five_point_one(int e[], int n){
	int frame_size;
	frame_size = maximum(e,n);
	return frame_size;
}

int five_point_two(int f, int H){
	int new_f;
	new_f = f;
	while((H % new_f) != 0){
		new_f+=1;
	}
	return new_f;
}

int five_point_three(int f, int p[], int D[]){
	for (int i =0; i < 3; i++){
		if (!(2*(f)-gcd(p[i], f) <= D[i])){
			return -1;
		}
		else{}
	}
	return f;
}

int Edf::find_frame_size( int p[], int e[], int D[] ){
	int f;
	int H;
	H = lcm(p[0], p[1], p[2]);
	f = five_point_one(e,3);
	f = five_point_two(f,H);
	f = five_point_three(f,p, D);
	if (f == -1){
		//means that optimal frame size not found. Need to split job(s) into smaller execution
		return -1;
	}
	return f;
}
