/*
������ ��������� ����������
����������� ���������, ������� ��������� ������ ��������� ����������, ����� ���, USB-����-����������, ����������� ������� ����, DVD�����.
������ �������� ���������� �������� �������� ���������������� ������:
- ����� �USB-����-�����������;
- ����� ������������ ������� ����;
- ����� �DVD�����.
��� ��� ������ �������� ������������ �� ������������ �������� ������ ��������� ����������.
� ������� ������ �������� ��� �������������, ������, ������������, ������� ��������, ����������. ����� �������� ����� ������������ ��������-
�����������, � ����� �������� ������, �������� � ����������. � ����������� ������� ���������������� ������ ������, �������� � ����������.
����� ����, ������ �� ����������� ������� ����������� ���������� ������:
- ����� �USB-����-�����������: �������� USB;
- ����� ������������ ������� ����: �������� �������� ��������;
- ����� �DVD�����: �������� ������.
������ � ��������� ��������������� ������� ������������ ����� ��������� �� ������� �����, ������� �������� � ������������ �������.
��������� ������ ������������� ����������� ����������, �������� (�� ������), ������, ��������� (�� ������) ����������� ���������� ��������,
������ ��
��������� ��������, � ����� ����������� �������� ������ �� ����� � ���������� ������ � ����.
���� ������������� ��������� ������� ��������� ��� ������������� �������� ���������� ������ ��� �������� ������ �� �����. � ��������� �������
��� ������������� �������� ���������� ���������� ��������� �������� RTTI (������������ ������������� ����) ���� ����������� ���������� ����� � �������������� ��������� dynamic_cast.
*/

#include <iostream>
#include<Windows.h>
#include <conio.h>
#include<fstream>
#include"Device.h"
#include"List.h"

using namespace std;

int main()
{


    int size = 0;

    List list;

    ofstream out;

    list.Load();

    while (true)
    {
        system("cls");

        cout << "\tM E N U:\n1) Add device\n2) Remove Device\n3) Change Device\n4) Search Device\n5) Print list of Devices\n0) Exit" << endl;

        char choice = _getch();

        switch (choice)
        {
        case '1':
        {
            list.addDevice(list.Input());

        } break;

        case '2':
        {
            int index;
            cout << "Enter index of the device to remove : " << endl;
            cin >> index;
            list.Del(index);

        } break;

        case '3':
        {
            int index;
            cout << "Enter index to change the device : " << endl;
            cin >> index;
            list.ChangeDevice(index);
        } break;

        case '4':
        {
            cout << "Enter criteria of the device to search : ";
            cout << "\n1) By Company\n2) By Model\n3) By Capacity\n4) List all USB\n5) List all HDD\n6) List all DVD\n ";
            char search = _getch();
            switch (search)
            {
            case '1':
                list.FindByCompany();
                break;

            case '2':
                list.FindByModel();
                break;

            case '3':
                list.FindByCapacity();
                break;

            case '4':
                list.FindAllUSB();
                break;

            case '5':
                list.FindAllHDD();
                break;

            case '6':
                list.FindAllDVD();
                break;

            default:
                cout << "\nERROR!!! Wrong button. Please try again.";
                system("pause");
                break;
            }
        }
        break;

        case '5':

            list.PrintDevices();
            break;

        case '0':

            list.Save(out);
            cout << "\nThank you!";
            system("exit");
            return 1;
            break;

        default:

            cout << "\nERROR!!! Wrong button. Please try again.";
            system("pause");
            break;

        }
    } return 0;
}





