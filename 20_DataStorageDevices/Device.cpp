#include <iostream>
#include<fstream>
#include "Device.h"

using namespace std;

Device::Device()
{
	string company = " ";
	string model = " ";
	string name = " ";
	int capacity = 0;
	int quantity = 0;
}

Device::Device(string company, string model, string name, int capacity, int quantity)
{
	this->company = company;
	this->model = model;
	this->name = name;
	this->capacity = capacity;
	this->quantity = quantity;
}

Device::~Device()
{

}

void Device::setCompany(string company)
{
	this->company = company;
}
void Device::setModel(string model)
{
	this->model = model;
}
void Device::setName(string name)
{
	this->name = name;
}
void Device::setCapacity(int capacity)
{
	this->capacity = capacity;
}
void Device::setQuantity(int quantity)
{
	this->quantity = quantity;
}
string Device::getCompany()
{
	return company;
}
string Device::getModel()
{
	return model;
}
string Device::getName()
{
	return name;
}
int Device::getCapacity()
{
	return capacity;
}
int Device::getQuantity()
{
	return quantity;
}

void Device::Print()
{
	cout << "\t" << name << "\t" << company << "\t" << model << "\t" << capacity << "\t\t" << quantity;
}

void Device::Save(ostream& out)
{
	out << name << endl;
	out << company << endl;
	out << model << endl;
	out << capacity << endl;
	out << quantity << endl;

}

void Device::Load(ifstream& in)
{
		//string name, company, model;
		//int capacity, quantity;
		char buf[300];

		in.getline(buf, 300);
		company = buf;
		in.getline(buf, 300);
		model = buf;
		in.getline(buf, 300);
		capacity = atoi(buf);
		in.getline(buf, 300);
		quantity = atoi(buf);
}
