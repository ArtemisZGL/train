#include "train.cpp"
int main()
{
	int num, car_count;
	cout << "�����복����ܸ���: ";
	cin >> car_count;
	
	Train train(car_count);
	for(int i = 0; i < car_count; i++)
	{
		cout << "�������" << i + 1 << "�ڳ�����: " ;
		cin >> num;
		
		if( train.pop_from_stacks(num) ) continue;
		train.push_to_stacks(num);
	}
	cout << "������" << train.get_s_count() << "��ջ" << endl; 
	cout << "������" << train.get_step_count() << "��" << endl; 
	
	train.free_stacks();
	return 0;
}
