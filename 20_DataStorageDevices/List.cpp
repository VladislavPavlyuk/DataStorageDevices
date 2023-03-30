#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include "List.h"


List::List()
{
	for (size_t i = 0; i < list.GetSize(); i++)
	{
		list;
	}
}

Device* List::Input()
{
	system("cls");
	string company;
	string model;
	string name;
	int capacity;
	int quantity;


	if (cin.peek() == '\n')
		cin.get();

	cout << "Company : ";
	getline(cin, company);
	cout << "Model : ";
	getline(cin, model);
	cout << "Capacity : ";
	cin >> capacity;
	cout << "Quantity : ";
	cin >> quantity;

	cout << "Type:\n1 - USB\n2 - HDD\n3 - DVD" << endl;
	char type = _getch();

	switch (type)
	{
	case '1':
	{
		name = "USB";
		int USB_speed = 0;
		cout << "USB speed : ";
		cin >> USB_speed;
		USB* p = new USB(company, model, name, capacity, quantity, USB_speed);
		return p;
	}break;

	case '2':
	{
		name = "HDD";
		int HDD_speed = 0;
		cout << "HDD speed : ";
		cin >> HDD_speed;
		HDD* p = new HDD(company, model, name, capacity, quantity, HDD_speed);
		return p;
	} break;

	case '3':
	{
		name = "DVD";
		int DVD_speed = 0;
		cout << "DVD speed : ";
		cin >> DVD_speed;
		DVD* p = new DVD(company, model, name, capacity, quantity, DVD_speed);
		return p;
	} break;

	default:
		break;
	}
}

void List::addDevice(Device* p)
{
	this->list.Add(p);
	cout << "\nDevice was successfully added" << endl;
	system("pause");
}

void List::Del(int index)
{
	if (index > 0 && index <= list.GetSize())
	{
		this->list.Remove(index);
		cout << "n\Device was successfully removed" << endl;
	}
	else
	{
		cout << "\nERROR!!! Wrong number" << endl;
	}
	system("pause");
}

void List::ChangeDevice(int index)
{
	if (index > 0 && index <= list.GetSize())
	{
		list[index - 1] = nullptr;
		list[index - 1] = Input();
		cout << "\nDevice was successfully changed" << endl;
	}
	else
	{
		cout << "\nERROR!!! Wrong number!" << endl;
	}
	system("pause");
}
void List::PrintHead()
{
	system("cls");
	cout << "N " << "\tName" << "\tCompany" << "\tModel" << "\tCapacity" << "\tQuantity" << "\tSpeed" << endl;
}

void List::PrintDevices()
{
	PrintHead();

	for (size_t i = 0; i < list.GetSize(); i++)
	{
		cout << i + 1 << "  ";
		list[i]->Print();
	}
	system("pause");
}
void List::FindByCompany()
{
	system("cls");
	int count = 0;
	string temp_company;

	if (cin.peek() == '\n')
		cin.get();

	cout << "Enter company for search : ";
	getline(cin, temp_company);
	PrintHead();
	for (size_t i = 0; i < list.GetSize(); i++)
	{
		if (temp_company == list[i]->getCompany())
		{
			cout << i + 1 << "  ";
			list[i]->Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\nERROR!!! Device was not found" << endl;
	}
	system("pause");
}

void List::FindByModel()
{
	system("cls");
	int count = 0;
	string temp_model;
	if (cin.peek() == '\n')
		cin.get();
	cout << "Enter model for search : ";
	getline(cin, temp_model);
	PrintHead();
	for (size_t i = 0; i < list.GetSize(); i++)
	{
		if (temp_model == list[i]->getModel())
		{
			cout << i + 1 << "  ";
			list[i]->Print();
			count++;
		}
	}

	if (count == 0)
	{
		cout << "\nERROR!!! Device was not found" << endl;
	}
	system("pause");
}

void List::FindByCapacity()
{
	system("cls");
	int count = 0;
	int temp_capacity;
	cout << "Enter capacity of search : ";
	cin >> temp_capacity;
	PrintHead();
	for (size_t i = 0; i < list.GetSize(); i++)
	{
		if (temp_capacity == list[i]->getCapacity())
		{
			cout << i + 1 << "  ";
			list[i]->Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\nERROR!!! Device was not found" << endl;
	}
	system("pause");
}
void List::FindAllUSB()
{
	system("cls");

	List::PrintHead();

	int count = 0;

	for (size_t i = 0; i < list.GetSize(); i++)
	{
		if (typeid(*list[i]) == typeid(USB))
		{
			cout << i + 1 << "  ";
			list[i]->Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\nERROR!!! Device was not found!" << endl;
	}
	system("pause");
}

void List::FindAllHDD()
{
	system("cls");

	PrintHead();

	int count = 0;
	for (size_t i = 0; i < list.GetSize(); i++)
	{
		if (typeid(*list[i]) == typeid(HDD))
		{
			cout << i + 1 << "  ";
			list[i]->Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\nERROR!!! Device was not found" << endl;
	}
	system("pause");
}

void List::FindAllDVD()
{
	system("cls");

	PrintHead();

	int count = 0;
	for (size_t i = 0; i < list.GetSize(); i++)
	{
		if (typeid(*list[i]) == typeid(DVD))
		{
			cout << i + 1 << "  ";
			list[i]->Print();
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\nERROR!!! Device was not found" << endl;
	}
	system("pause");
}

void List::Save(ostream& o)
{
	ofstream out("list.txt", ios::out);
	if (!out.is_open())
	{
		cout << "ERROR!\n";
	}
	for (size_t i = 0; i < list.GetSize(); i++)
	{
		list[i]->Save(out);
	}
	out.close();
}

void List::Load()
{
	ifstream in;
	in.open("list.txt", ios::in);
	if (!in)
	{
		cout << "ERROR!\n";
	}
	else while (!in.eof())
	{
		char buf[300];
		in.getline(buf, 300);
		if (strcmp(buf, "USB") == 0)
		{

			Device* p = new USB;
			p->Load(in);
			this->list.Add(p);
		}
		if (strcmp(buf, "HDD") == 0)
		{
			Device* p = new HDD;
			p->Load(in);
			this->list.Add(p);
		}
		if (strcmp(buf, "DVD") == 0)
		{
			Device* p = new DVD;
			p->Load(in);
			this->list.Add(p);
		}
	}
	in.close();
}