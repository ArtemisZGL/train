#include"train.hpp"
int main()
{
	int num;
	cout << "请输入车厢的总个数: ";
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "节车厢编号: " ;
		cin >> num;
		
		if( pop_from_stacks(num) ) continue;
		push_to_stacks(num);
	}
	cout << "共用了" << s_count << "个栈" << endl; 
	
	free_stacks();
	return 0;
}
