#pragma once
#include <iostream>
#include <fstream>
#include "Device.h"


using namespace std;

class DVD :public Device
{
protected:
	int DVD_speed;
public:
	DVD()
	{
		DVD_speed = 0;
	}

	DVD(string company, string model, string name, int capacity, int quantity, int DVD_speed) : Device(company, model, name, capacity, quantity)
	{
		this->DVD_speed = DVD_speed;
	}

	void setDVD_speed(int speed)
	{
		this->DVD_speed = speed;
	}

	int getUSB_speed()
	{
		return DVD_speed;
	}

	void Print() override
	{
		Device::Print();

		cout << "\t\t" << DVD_speed << endl;
	}

	void Save(ostream& out) override
	{
		Device::Save(out);

		out << DVD_speed << endl;
	}

	void Load(ifstream& in) override
	{
		name = "DVD";

		Device::Load(in);

		char buf[300];

		in.getline(buf, 300);

		DVD_speed = atoi(buf);
	}
};
