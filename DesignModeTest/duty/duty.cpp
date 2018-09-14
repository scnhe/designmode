#include<iostream>
using namespace std;
//职责链模式
enum RequestLevel
{
	One = 1,
	Two,
	Three
};
class Leader
{
public:
	Leader(Leader *leader) :m_leader(leader) {}
	virtual ~Leader() {}
	virtual void handleRequest(RequestLevel level) = 0;
protected:
	Leader *m_leader;
};
class Monitor :public Leader
{
public:
	Monitor(Leader *leader) :Leader(leader) {}
	void handleRequest(RequestLevel level)
	{
		if (level < Two)
		{
			cout << "Monitor handle request :" << level << endl;
		}
		else
		{
			m_leader->handleRequest(level);
		}
	}
};
class Captain :public Leader
{
public:
	Captain(Leader *leader) :Leader(leader) {}
	void handleRequest(RequestLevel level)
	{
		if (level < Three)
		{
			cout << "Captain handle request :" << level << endl;
		}
		else
		{
			m_leader->handleRequest(level);
		}
	}
};

class General :public Leader
{
public:
	General(Leader *leader) :Leader(leader) {}
	void handleRequest(RequestLevel level)
	{

		cout << "General handle request :" << level << endl;

	}
};
//END
int main()
{
	cout << "Test 职责链..." << endl;
	Leader * general = new General(nullptr);
	Leader * cap = new Captain(general);
	Leader * mon = new Monitor(cap);
	mon->handleRequest(Two);


	delete mon;
	delete cap;
	delete general;
}