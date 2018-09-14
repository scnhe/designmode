#include<iostream>
using namespace std;
#include<list>
//组合模式
class Company
{
public:
	Company(string name) :m_name(name)
	{}
	virtual ~Company() {}
	virtual void add(Company* company) = 0;
	virtual void remove(string name) = 0;
	virtual void display(int depth) = 0;
	string getName()
	{
		return m_name;
	}

protected:
	string m_name;
};

//具体的公司
class ConcreteCompany :public Company   //树枝
{
public:
	ConcreteCompany(string name) :Company(name)
	{}
	~ConcreteCompany()
	{
		cout << "~ConcreteCompany()" << endl;
	}
	void add(Company* company) override;
	void remove(string name) override;
	void display(int depth) override;

private:
	list<shared_ptr<Company>> m_listCompany;

};

void ConcreteCompany::add(Company* company)
{
	shared_ptr<Company> temp(company);
	m_listCompany.push_back(temp);
}

void ConcreteCompany::remove(string name)
{
	list<shared_ptr<Company>>::iterator iter = m_listCompany.begin();
	for (; iter != m_listCompany.end(); iter++)
	{
		shared_ptr<Company> temp(*iter);
		
		string strName = temp.get()->getName();
		if (name == strName)
		{
			m_listCompany.erase(iter);
		}
	}
}

void ConcreteCompany::display(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}
	cout << m_name.data() << endl;
	list<shared_ptr<Company>>::iterator iter = m_listCompany.begin();
	for (; iter != m_listCompany.end(); iter++)
	{
		shared_ptr<Company> temp(*iter);
		temp.get()->display(depth + 2);
	}
}

//公司下的部门
class FinanceDept :public Company    //树叶
{
public:
	FinanceDept(string name) :Company(name)
	{}
	~FinanceDept()
	{
		cout << "~FinanceDept()" << endl;
	}
	void add(Company* company) override;
	void remove(string name) override;
	void display(int depth) override;
};

void FinanceDept::add(Company* company)
{
	cout << "FinanceDept add failed" << endl;
}

void FinanceDept::remove(string name)
{
	cout << "FinanceDept remove failed" << endl;
}

void FinanceDept::display(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}
	cout << m_name.data() << endl;
}

//公司下的部门
class HRDept :public Company  //树叶
{
public:
	HRDept(string name) :Company(name)
	{}
	~HRDept()
	{
		cout << "~HRDept()" << endl;
	}
	void add(Company* company) override;
	void remove(string name) override;
	void display(int depth) override;
};

void HRDept::add(Company* company)
{
	cout << "HRDept add failed" << endl;
}

void HRDept::remove(string name)
{
	cout << "HRDept remove failed" << endl;
}

void HRDept::display(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}
	cout << m_name.data() << endl;
}

int main(int argc, char *argv[])
{
	Company* root = new ConcreteCompany("zong");
	Company* f1 = new FinanceDept("F1");
	Company* h1 = new HRDept("H1");
	root->add(f1);
	root->add(h1);
	Company* c1 = new ConcreteCompany("fen1");
	Company* f2 = new FinanceDept("F2");
	Company* h2 = new HRDept("H2");
	c1->add(f2);
	c1->add(h2);
	root->add(c1);
	root->display(0);
	delete root;

	return 0;
}