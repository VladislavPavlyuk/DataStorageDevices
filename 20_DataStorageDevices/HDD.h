#pragma once
#include <iostream>
#include <fstream>
#include "Device.h"

using namespace std;

class HDD :public Device
{
protected:

	int HDD_speed;

public:
	HDD()
	{
		HDD_speed = 0;
	}

	HDD(string company, string model, string name, int capacity, int quantity, int HDD_speed) : Device(company, model, name, capacity, quantity)
	{
		this->HDD_speed = HDD_speed;
	}

	void setHDD_speed(int speed)
	{
		this->HDD_speed = speed;
	}

	int getHDD_speed()
	{
		return HDD_speed;
	}

	void Print() override
	{
		Device::Print();

		cout << "\t\t" << HDD_speed << endl;
	}

	void Save(ostream& out) override
	{
		Device::Save(out);

		out << HDD_speed << endl;
	}

	void Load(ifstream& in) override
	{
		name = "HDD";

		Device::Load(in);

		char buf[300];

		in.getline(buf, 300);

		HDD_speed = atoi(buf);
	}
};



