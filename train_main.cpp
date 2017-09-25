#include "train.cpp"
int main()
{
	int num, car_count;
	cout << "请输入车厢的总个数: ";
	cin >> car_count;
	
	Train train(car_count);
	for(int i = 0; i < car_count; i++)
	{
		cout << "请输入第" << i + 1 << "节车厢编号: " ;
		cin >> num;
		
		if( train.pop_from_stacks(num) ) continue;
		train.push_to_stacks(num);
	}
	cout << "共用了" << train.get_s_count() << "个栈" << endl; 
	cout << "共用了" << train.get_step_count() << "步" << endl; 
	
	train.free_stacks();
	return 0;
}
