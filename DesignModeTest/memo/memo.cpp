#include<iostream>
using namespace std;
//����¼ģʽ
/*
����¼ģʽ���ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬�������Ժ�Ϳ��Խ��ö���ָ���ԭ�������״̬��
��ν����ͨ��һ������¼��ר�Ŵ洢����״̬��
�ؼ����룺����¼�ࡢ�ͻ��ࡢ����¼�����ࣻ�ͻ��಻�뱸��¼����ϣ������뱸��¼��������ϡ�
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