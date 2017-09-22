//v2.0

#include <iostream>
#include <stack>
using namespace std;

typedef struct Stack{
	stack<int> s;
	Stack* next;
}Stack;

void pop_from_stacks(int num, int next_out, int s_count);
 
int main()
{
	int n, num;
	cout << "请输入车厢的总个数: ";
	cin >> n;
	Stack* head = NULL;
	int s_count = 0, next_out = 1;
	for(int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "节车厢编号: " ;
		cin >> num;
		if(num == next_out)
		{
			cout << num << " 不进栈直接输出 " << endl;
			next_out++;
			
			int loop_count = 0;
			while(true)
			{
				Stack* temp = head;
				while(temp != NULL)
				{
					while(temp != NULL && temp->s.empty())
					{
						temp = temp->next;
						loop_count++;
					}
					if(temp == NULL) break;
					if(temp->s.top() == next_out)
					{
						cout << "从第" << loop_count + 1 << "个栈pop：" << next_out << endl;  
						temp->s.pop();
						next_out++;
						loop_count = 0;
						break;
					}
					temp = temp->next;
					loop_count++;
				}	
				
				if(loop_count == s_count) break;
				if(next_out == n + 1) break; 
			}
			continue;
		}

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
		if(newStack)
		{
			Stack* temp = head;
			int empty_index = 0, loop_count = 0;
			while(temp != NULL)
			{
				loop_count++;
				if(temp->s.empty())
				{
					empty_index = loop_count;
					break;
				}
				temp = temp->next;
			}
			
			if(empty_index == 0)
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
				cout << "开第" << s_count << "个新栈" << "push:" << num << endl; 
			}
			else
			{
				temp = head;
				for(int j = 0; j < empty_index - 1; j++) temp = temp->next;
				temp->s.push(num);
				cout << "在第"<< empty_index << "个栈" << "push:" << num << endl; 
			}
		}
		else
		{
			Stack* temp = head;
			for(int j = 0; j < index; j++) temp = temp->next;
			temp->s.push(num);
			cout << "在第" << index + 1 << "个栈" << "push:" << num << endl; 
		}
	}
	cout << "共用了" << s_count << "个栈" << endl; 
	
	while(head != NULL)
	{
		Stack* temp = head;
		head = head->next;
		delete temp;
	}
}
