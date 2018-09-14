#include<iostream>
using namespace std;

//建造者模式

typedef enum
{
	type1,
	type2,
	type3

}ProductType;
class Product
{
public:
	void setNum(int num)
	{
		m_num = num;
	}
	void setColor(string color)
	{
		m_color = color;
	}
	void setType(ProductType type)
	{
		m_type = type;
	}
	void showProduct()
	{
		cout << "Product:" << endl;
		cout << "	num: " << m_num << endl;
		cout << "	color: " << m_color.data() << endl;
		cout << "	type: " << m_type << endl;
	}
private:
	int m_num;
	string m_color;
	ProductType m_type;
};

class Builder
{
public:
	Builder() {}
	virtual ~Builder() {}
	virtual void buildNum(int num) = 0;
	virtual void buildColor(string color) = 0;
	virtual void buildType(ProductType type) = 0;
	virtual void createProduct() = 0;
	virtual Product * getProduct() = 0;
	virtual void show() = 0;

};
class BuilderA :public Builder
{
public:
	BuilderA() {}
	~BuilderA() {}
	void buildNum(int num) override
	{
		cout << "BuilderA build Num: "<<num << endl;
		m_product->setNum(num);

	}
	void buildColor(string color) override
	{
		cout << "BuilderA build color: " << color.data() << endl;
		m_product->setColor(color);
	}
	void buildType(ProductType type) override
	{
		cout << "BuilderA build type: " << type << endl;
		m_product->setType(type);
	}
	void createProduct() override
	{
		cout << "BuilderA CreateProduct"<< endl;
		m_product = new Product;
	}
	Product * getProduct() override
	{
		return m_product;
	}
	void show() override
	{
		m_product->showProduct();
	}
private:
	Product * m_product;
};
class Director
{
public:
	Director(Builder * builder) :m_builder(builder)
	{}
	void construct(int num,string color,ProductType type)
	{
		m_builder->createProduct();
		m_builder->buildNum(num);
		m_builder->buildColor(color);
		m_builder->buildType(type);
	}

private:
	Builder * m_builder;
};