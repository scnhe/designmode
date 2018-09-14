#include<iostream>
using namespace std;
//备忘录模式
/*
备忘录模式：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可以将该对象恢复到原来保存的状态。
如何解决：通过一个备忘录类专门存储对象状态。
关键代码：备忘录类、客户类、备忘录管理类；客户类不与备忘录类耦合，而是与备忘录管理类耦合。
*/
typedef struct// infomation  need to be stored
{
	int grade;
	string arm;
	string corps;

}GameValue;
class Memento
{
public :
	Memento() {}
	Memento(GameValue value) :m_gameValue(value)
	{
	}
	GameValue getValue()
	{
		return m_gameValue;
	}
private:
	GameValue m_gameValue;
};
class Game
{
public:
	Game(GameValue value) :m_gameValue(value) {}
	void addGrade()
	{
		m_gameValue.grade++;
	}
	void replaceArm(string arm)
	{
		m_gameValue.arm = arm;
	}
	void replaceCorps(string corps)
	{
		m_gameValue.corps = corps;
	}
	Memento saveValue()
	{
		Memento memento(m_gameValue);
		return memento;
	}
	void load(Memento memento)
	{
		m_gameValue = memento.getValue();
	}
	void showValue()
	{
		cout << "Grade : " << m_gameValue.grade << endl;
		cout << "Arm : " << m_gameValue.arm.data() << endl;
		cout << " Corps : " << m_gameValue.corps.data() << endl;
	}
private:
	GameValue m_gameValue;
};
class Caretake
{
public:
	void save(Memento memento)
	{
		m_memento = memento;
	}
	Memento load()
	{
		return m_memento;
	}
private:
	Memento m_memento;
};
int main()
{
	GameValue v1 = {0,"Ak","3K"};
	Game game(v1);
	game.addGrade();
	game.showValue();
	cout << "-------------------" << endl;
	Caretake care;
	care.save(game.saveValue());
	game.addGrade();
	game.replaceArm("M16");
	game.replaceCorps("XZD");
	game.showValue();
	cout << "-----------------" << endl;
	game.load(care.load());
	game.showValue();
	
	return 0;
}