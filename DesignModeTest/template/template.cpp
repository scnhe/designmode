#include<iostream>
using namespace std;
//Ä£°åÄ£Ê½
class Computer
{
public:
	void product()
	{
		installCpu();
		installRam();
		installGCard();
	}
protected:
	virtual void installCpu() = 0;
	virtual void installRam() = 0;
	virtual void installGCard() = 0;
};
class ComputerLen :public Computer
{
protected:
	void installCpu() override
	{
		cout << "ComputerA install Intel core i5" << endl;
	}
	void installRam() override
	{
		cout << "ComputerA install 2G Ram" << endl;
	}
	void installGCard() override
	{
		cout << "ComputerA install GTX970 " << endl;
	}

};
class ComputerMac:public Computer
{
protected:
	void installCpu() override
	{
		cout << "ComputerMac install Intel core i7" << endl;
	}
	void installRam() override
	{
		cout << "ComputerMac install 16G Ram" << endl;
	}
	void installGCard() override
	{
		cout << "ComputerMac install GTX1080 " << endl;
	}

};

int main()
{
	Computer * a = new ComputerLen;
	Computer * b = new ComputerMac;
	a->product();
	cout << "-------------" << endl;
	b->product();
	delete a;
	delete b;
	return 0;
}