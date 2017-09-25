#ifndef TRAIN_H
#define TRAIN_H 

#include <iostream>
#include <stack>
using namespace std;

typedef struct Stack{
	stack<int> s;
	Stack* next;
}Stack;

class Train{
	private:
		Stack* head;
		int s_count, next_out, n, step_count;
	public:
		Train();
		Train(int n);
		bool pop_from_stacks(int num);
		void push_to_stacks(int num);
		void push_new_stack(int num);
		void push_old_stack(int stack_index, int num);
		void free_stacks();
		int get_s_count();
		int get_step_count();
}; 


#endif
