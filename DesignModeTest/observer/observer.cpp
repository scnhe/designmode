#include<iostream>
#include<vector>
#include<list>
using namespace std;

//观察者模式
class View;
class DataModel
{
public:
	virtual ~DataModel() {}
	virtual void add(View * view) = 0;
	virtual void remove(View *view) = 0;
	virtual void notify() = 0;

};
class View
{
public:
	virtual ~View() { cout << "~View()" << endl; }
	virtual void update() = 0;

};

class IntModel :public DataModel
{
public:
	~IntModel()
	{
		clear();
	}
	void add(View *view)
	{
		auto iter = std::find(m_list.begin(),m_list.end(),view);
		if (iter == m_list.end())
		{
			m_list.push_back(view);
		}
	}
	void remove(View *view)
	{
		auto iter = m_list.begin();
		for (iter; iter != m_list.end(); iter++)
		{
			if (*iter == view)
			{
				delete *iter;
				m_list.erase(iter);
				break;
			}
		}
		
	}
	void notify()
	{
		auto iter = m_list.begin();
		for (iter; iter != m_list.end(); iter++)
		{
			(*iter)->update();
		}
	}
private:
	void clear()
	{
		if (!m_list.empty())
		{
			auto iter = m_list.begin();
			for (iter; iter != m_list.end(); iter++)
			{
				delete *iter;
			}
		}
	}
private:
	list<View *>m_list;
	
};

class TreeView :public View
{
public:
	TreeView(string name) :m_name(name), View() {}
	~TreeView() { cout << "~TreeView() "<<m_name.data() << endl; }
	void update()
	{
		cout << m_name.data() << " : Update" << endl;
	}
private:
	string m_name;
};
//END

int main(void)
{

	//观察者
	View *v1 = new TreeView("view1");
	View *v2 = new TreeView("view2"); 
	View *v3 = new TreeView("view3");
	DataModel * model = new IntModel;
	model->add(v1);
	model->add(v2);
	model->add(v3);
	model->notify();
	cout << "remove v2" << endl;
	model->remove(v2);
	model->notify();
	delete model;

	

	
	return 0;
}