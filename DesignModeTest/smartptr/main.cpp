#include<iostream>

using namespace std;

int main()
{
	int value = 12;

	int *p = &value;

	shared_ptr<int> np1(p);
	shared_ptr<int> np2(p);
	shared_ptr<int> np3(p);

	int n = np3.use_count();
	return 0;
}