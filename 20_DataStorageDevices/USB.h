#pragma once
#include <iostream>
#include <fstream>
#include "Device.h"

using namespace std;

class USB :public Device
{
protected:
	int USB_speed;
public:
	USB()
	{
		USB_speed = 0;
	}
	USB(string company, string model, string name, int capacity, int quantity, int USB_speed) : Device(company, model, name, capacity, quantity)
	{
		this->USB_speed = USB_speed;
	}

	void setUSB_speed(int speed)
	{
		this->USB_speed = speed;
	}

	int getUSB_speed()
	{
		return USB_speed;
	}

	void Print() override
	{
		Device::Print();

		cout << "\t\t" << USB_speed << endl;
	}

	void Save(ostream& out) override
	{
		Device::Save(out);

		out << USB_speed << endl;
	}

	void Load(ifstream& in) override
	{
		name = "USB";

		Device::Load(in);

		char buf[300];

		in.getline(buf, 300);

		USB_speed = atoi(buf);
	}
};

