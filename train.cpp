#include"train.hpp"
int main()
{
	int num;
	cout << "�����복����ܸ���: ";
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "�ڳ�����: " ;
		cin >> num;
		
		if( pop_from_stacks(num) ) continue;
		push_to_stacks(num);
	}
	cout << "������" << s_count << "��ջ" << endl; 
	
	free_stacks();
	return 0;
}
