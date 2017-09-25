#include "train.hpp"

Train::Train()
{
	s_count = 0;
	n = 0;
	next_out = 1;
	step_count = 0;
	head = NULL;
}

Train::Train(int n)
:s_count(0), next_out(1), n(n), step_count(0)
{
	head = NULL;
}

bool Train::pop_from_stacks(int num)
{
	if(num == next_out)
	{
		cout << num << " ����ջֱ�����\n" << endl;
		step_count++;
		next_out++;
		
		int loop_count = 0;
		while(true)
		{
			Stack* temp = head;

			while(temp != NULL)
			{
				while(temp != NULL && temp->s.empty() && loop_count <= s_count)
				{
					temp = temp->next;
					loop_count++;
				}
				if(temp == NULL || loop_count == s_count) break;
				if(temp->s.top() == next_out)
				{
					cout << "�ӵ�" << loop_count + 1 << "��ջpop��" << next_out << "\n" << endl;  
					temp->s.pop();
					next_out++;
					step_count++;
					loop_count = 0;
					break;
				}
				temp = temp->next;
				loop_count++;
			}		
			if(loop_count == s_count) break;
			if(next_out == n + 1) break; 
		}
		return true;
	}
	return false;
}

void Train::push_to_stacks(int num)
{
	bool newStack = true;
	int index = -1, diff = num, stack_count = 0;
	Stack* p = head;
	while(p != NULL)
	{
		while(p != NULL && p->s.empty() && stack_count <= s_count)
		{
			 p = p->next;
			 stack_count++;
		}
		if(p == NULL) break;
			
		if(p->s.top() > num && (p->s.top() - num) < diff)
		{
			diff = p->s.top() - num;
			index = stack_count;
		}
			
		stack_count++;
		p = p->next;
	}
		
	if(index != -1) newStack = false;
	if(newStack) push_new_stack(num);
	else push_old_stack(index, num);
}

void Train::push_new_stack(int num)
{
	Stack* temp = head;
	int empty_index = -1, loop_count = 0;
	while(temp != NULL)
	{
		if(temp->s.empty())
		{
			empty_index = loop_count;
			break;
		}
		loop_count++;
		temp = temp->next;
	}
			
	if(empty_index == -1)
	{
		Stack* newstack = new Stack;
		newstack->s.push(num);
		newstack->next = NULL;
		temp = head;
		if(head == NULL) head = newstack;
		else
		{
			for(int j = 0; j < s_count - 1; j++) temp = temp->next;
			temp->next = newstack;
		}
		s_count++;
		cout << "����" << s_count << "����ջ" << "push:" << num << "\n" << endl;
		step_count++; 
	}
	else push_old_stack(empty_index, num);
}

void Train::push_old_stack(int stack_index, int num)
{
	Stack* temp = head;
	for(int j = 0; j < stack_index; j++) temp = temp->next;
	temp->s.push(num);
	cout << "�ڵ�"<< stack_index + 1 << "��ջ" << "push:" << num << "\n" << endl;
	step_count++; 
}

void Train::free_stacks()
{
	while(head != NULL)
	{
		Stack* temp = head;
		head = head->next;
		delete temp;
	}
}

int Train::get_s_count()
{
	return s_count;
}

int Train::get_step_count()
{
	return step_count;
}

