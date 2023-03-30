/*
Список носителей информации
Разработать программу, которая формирует список носителей информации, таких как, USB-флеш-накопитель, портативный жесткий диск, DVD–диск.
Каждый носитель информации является объектом соответствующего класса:
- класс «USB-флеш-накопитель»;
- класс «Портативный жесткий диск»;
- класс «DVD–диск».
Все три класса являются производными от абстрактного базового класса «Носитель информации».
В базовом классе хранится имя производителя, модель, наименование, ёмкость носителя, количество. Класс обладает всеми необходимыми методами-
аксессорами, а также методами печати, загрузки и сохранения. В производных классах переопределяются методы печати, загрузки и сохранения.
Кроме того, каждый из производных классов дополняется следующими полями:
- класс «USB-флеш-накопитель»: скорость USB;
- класс «Портативный жесткий диск»: скорость вращения шпинделя;
- класс «DVD–диск»: скорость записи.
Работа с объектами соответствующих классов производится через указатели на базовый класс, которые хранятся в динамическом массиве.
Программа должна предоставлять возможность добавления, удаления (по номеру), печати, изменения (по номеру) определённых параметров носителя,
поиска по
заданному критерию, а также возможность загрузки данных из файла и сохранения данных в файл.
Поле «Наименование носителя» следует применять для идентификации носителя информации только при загрузке данных из файла. В остальных случаях
для идентификации носителя информации необходимо применять механизм RTTI (динамическая идентификация типа) либо полиморфное приведение типов с использованием оператора dynamic_cast.
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





