#pragma once
#include "Vector.h"
#include "USB.h"
#include "HDD.h"
#include "DVD.h"


class List
{
private:
	Vector <Device*> list;

public:
	List();
	Device* Input();
	void addDevice(Device* p);
	void Del(int index);
	void ChangeDevice(int index);
	void PrintHead();
	void PrintDevices();
	void FindByCompany();
	void FindByModel();
	void FindByCapacity();
	void FindAllUSB();
	void FindAllHDD();
	void FindAllDVD();
	void Save(ostream& out);
	void Load();
};
