//v1.0

#include <iostream>
using namespace std;
#include <stack>

typedef struct{
	stack<int> s;
}Stack;
 
int main()
{
	int n, num;
	cout << "please input size the num";
	cin >> n;
	stack<int> s[5];
	int s_count = 0, next_out = 1;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		if(num == next_out)
		{
			cout << num << " 不进栈直接输出 " << endl;
			next_out++;
			
			int loop_count = 0;
			while(true)
			{
				for(int j = 0; j < s_count; j++)
				{
					while(s[j].empty())
					{
						j++;
						loop_count++;
					}
					if(s[j].top() == next_out)
					{
						cout << "从第" << j << "个栈pop：" << next_out << endl;  
						s[j].pop();
						next_out++;
						loop_count = 0;
						break;
					}
					loop_count++;
				}
				if(loop_count == s_count) break;
				if(next_out == n + 1) break; 
			}
			continue;
		}
		
		bool newStack = true;
		int index = -1, diff = num;
		for(int j = 0; j < s_count; j++)
		{
			if(s[j].empty()) j++;
			if(s[j].top() > num && ( s[j].top() - num ) < diff)
			{
				diff = s[j].top() - num;
				index = j;
			}
		}
		if(index != -1) newStack = false;
		if(newStack)
		{
			s[s_count].push(num);
			s_count++;
			cout << "开一个新栈" << "push:" << num << endl; 
		}
		else
		{
			s[index].push(num);
			cout << "在第"<< index << "个栈" << "push:" << num << endl; 
		}
	}
}
