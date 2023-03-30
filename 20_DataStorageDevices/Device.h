#pragma once
#include <iostream>
#include<fstream>
using namespace std;

class Device
{
protected:
	string company;
	string model;
	string name;
	int capacity;
	int quantity;

public:
	Device();
	Device(string company, string model, string name, int capacity, int quantity);
	void setCompany(string company);
	void setModel(string model);
	void setName(string name);
	void setCapacity(int capacity);
	void setQuantity(int quantity);
	string getCompany();
	string getModel();
	string getName();
	int getCapacity();
	int getQuantity();

	virtual ~Device() = 0;
	virtual void Print() = 0;
	virtual void Save(ostream& o) = 0;
	virtual void Load(ifstream& in) = 0;
};



