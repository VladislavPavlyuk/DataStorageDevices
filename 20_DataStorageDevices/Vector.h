#pragma once
#include <iostream>
using namespace std;


template <typename T> class Vector
{
    T* vect;                                    //  Вектор
    int size;                                   //  Размерность вектора

public:
    Vector()
    {                                           //  Конструктор по умолчанию

        vect = nullptr;
        size = 0;
    }

    explicit Vector(int size) {                   //  Конструктор, позволяющий задавать размерность вектора

        vect = new T[size];

        this->size = size;
    }

    Vector(const T* ptr, int size)
    {                                               //  Конструктор, позволяющий  проинициализировать вектор  с помощью существующего массива

        vect = new T[size];

        this->size = size;

        for (size_t i = 0; i < size; i++)
        {
            vect[i] = ptr[i];
        }
    }

    Vector(const Vector<T>& v)                         // Конструктор копирования
    {
        this->size = v.size;

        this->vect = new T[size];

        for (size_t i = 0; i < size; i++)
        {
            vect[i] = v.vect[i];
        }
    }

    Vector(Vector<T>&& v)                               // Конструктор переноса
    {
        vect = v.vect;
        size = v.size;
        v.vect = nullptr;
        v.size = 0;
    }

    ~Vector()                                           // Деструктор
    {
        delete[]vect;
    }

    int GetSize() const
    {                                           //  Функция возвращает размерность вектора

        return size;

    }

    void Print();                        // Вывод на экран

    void Input();                        // Заполнение вектора

    void Clear();                        //  Очистка вектора

    bool IsEmpty() const;               // Возвращает истину, если вектор пусто

    void Add(const T& item);          // Добавление элемента в вектор

    void Insert(int index, const T& item); // Вставка элементов в вектор по заданному индексу

    void Remove(int index);                 //  Удаление элемента из вектора по заданному индексу

    Vector& operator ++ ();                 // Увеличение всех компонент вектора на единицу (префикс)

    Vector operator ++ (int k);             // Увеличение всех компонент вектора на единицу (постфикс)

    Vector& operator -- ();                 // Уменьшение всех компонент вектора на единицу (префикс)

    Vector operator -- (int k);             // Уменьшение всех компонент вектора на единицу (постфикс)

    Vector<T>& operator = (const Vector<T>& v);   // Перегруженный оператор присваивания с копированием

    Vector<T>& operator = (Vector<T>&& v);        // Перегруженный оператор присваивания с переносом

    T& operator [] (int index);           // Перегруженный оператор индексации

    Vector operator + (const Vector<T>& v);    // Сложение двух векторов

    Vector operator + (T n);              // Сложение вектора с числом (каждый компонент вектора складывается с числом)

    Vector& operator += (const Vector<T>& v);  // Перегруженный оператор += для сложения двух векторов

    Vector operator - (const Vector<T>& v);    // Вычитание двух векторов

    Vector operator - (T n);              // Вычитание числа из вектора

    Vector& operator -= (const Vector<T>& v);  // Перегруженный оператор -= для вычитания двух векторов

    Vector operator * (const Vector<T>& v);    // Умножение векторов

    Vector operator * (T n);              // Умножение вектора на число

    Vector& operator *= (T n);            // Перегруженный оператор *= для умножения вектора на число

    template <typename T> friend istream& operator >> (istream& cin, Vector<T>& v);  // Ввод вектора с клавиатуры

    template <typename T> friend ostream& operator << (ostream& cout, Vector<T>& v);  // Вывод вектора на экран
};

template <typename T> void Vector<T>::Print() {                              // Вывод на экран

    cout << endl;

    for (size_t i = 0; i < size; i++)
    {
        cout << "\t" << vect[i];
    }

    cout << "\tsize = " << size;

    cout << endl;
}


template <typename T> void Vector<T>::Input() {                       // Заполнение вектора

    cout << "\nPlease enter " << GetSize() << " numbers\n";;

    for (size_t i = 0; i < GetSize(); i++)

    {
        cin >> vect[i];
    }
}

template <typename T> void Vector<T>::Clear() {                       //  Очистка вектора

    for (size_t i = 0; i < size; i++)

    {
        vect[i] = 0;
    }
}

template <typename T> bool Vector<T>::IsEmpty() const {               // Возвращает истину, если вектор пустой

    if (vect == nullptr)

        return true;

    else return false;
}

template <typename T> void Vector<T>::Add(const T& item) {          // Добавление элемента в вектор

    size = GetSize();
    size++;

    T* tmp;

    tmp = new T[size];

    for (size_t i = 0; i < size - 1; i++)
    {
        tmp[i] = vect[i];
    }
    tmp[size - 1] = item;

    delete[]vect;

    vect = tmp;

}

template <typename T> void Vector<T>::Insert(int index, const T& item) { // Вставка элементов в вектор по заданному индексу

    size++;

    if ((index < 0) || (index > size))
    {
        cout << "\nError! Index is out of the Vector\n";
        exit(0);
    }

    T* tmp;

    tmp = new T[size];

    for (size_t i = 0; i < index; i++)
    {
        tmp[i] = vect[i];
    }

    tmp[index - 1] = item;

    for (size_t i = index; i < size; i++)
    {
        tmp[i] = vect[i - 1];
    }

    delete[]vect;

    vect = tmp;

}

template <typename T> void Vector<T>::Remove(int index) {             //  Удаление элемента из вектора по заданному индексу

    index--;

    if ((index < 0) || (index > size))
    {
        cout << "\nError! Index is out of the Vector\n";

        exit(0);
    }

    T* tmp;

    tmp = new T[size - 1];

    for (size_t i = 0; i < index; i++)
    {
        tmp[i] = vect[i];
    }
    for (size_t i = index; i < size; i++)
    {
        tmp[i] = vect[i + 1];
    }

    size--;

    delete[]vect;

    vect = tmp;
}

template <typename T> Vector<T>& Vector<T>::operator ++ ()                 // Увеличение всех компонент вектора на единицу (префикс)
{
    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]++;
    }
    return *this;
}

template <typename T> Vector<T> Vector<T>::operator ++ (int)             // Увеличение всех компонент вектора на единицу (постфикс)
{
    Vector tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]++;
    }
    return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator -- ()                 // Уменьшение всех компонент вектора на единицу (префикс)
{
    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]--;
    }
    return *this;
}

template <typename T> Vector<T> Vector<T>::operator -- (int)             // Уменьшение всех компонент вектора на единицу (постфикс)
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]--;
    }
    return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator = (const Vector<T>& v)   // Перегруженный оператор присваивания с копированием
{
    if (this == &v)

        return *this;

    delete[] this->vect;

    this->vect = new T[v.size];

    this->size = v.size;

    for (int i = 0; i < this->size; ++i)
    {
        this->vect[i] = v.vect[i];
    }
    return *this;
}

template <typename T> Vector<T>& Vector<T>::operator = (Vector<T>&& v)        // Перегруженный оператор присваивания с переносом
{
    if (this == &v)

        return *this;

    delete[] vect;

    vect = v.vect;

    size = v.size;

    v.vect = nullptr;

    v.size = 0;

    return *this;
}

template <typename T> T& Vector<T>::operator [] (int index)           // Перегруженный оператор индексации
{
    if (index < 0 || index >= size)

        return vect[0];

    return vect[index];
}

template <typename T> Vector<T> Vector<T>::operator + (const Vector<T>& v)    // Сложение двух векторов
{
    int max_size;

    if (this->size > v.size)

        max_size = this->size;

    else max_size = v.size;

    Vector<T> tmp(max_size);

    for (size_t i = 0; i < max_size; i++)
    {
        if (i < this->size && i < v.size)
        {
            tmp.vect[i] = this->vect[i] + v.vect[i];
        }
        else if (i >= this->size)
        {
            tmp.vect[i] = v.vect[i];
        }
        else
        {
            tmp.vect[i] = this->vect[i];
        }
    }
    return tmp;
}
template <typename T> Vector<T> Vector<T>::operator + (T n)          // Сложение вектора с числом (каждый компонент вектора складывается с числом)
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = this->vect[i] + n;
    }
    return tmp;
}
template <typename T> Vector<T>& Vector<T>::operator += (const Vector<T>& v)  // Перегруженный оператор += для сложения двух векторов
{
    *this = *this + v;

    return *this;
}
template <typename T> Vector<T> Vector<T>::operator - (const Vector<T>& v)    // Вычитание двух векторов
{
    int max_size;

    if (this->size > v.size)

        max_size = this->size;

    else max_size = v.size;

    Vector<T> tmp(max_size);

    for (size_t i = 0; i < max_size; i++)
    {
        if (i < this->size && i < v.size)
        {
            tmp.vect[i] = this->vect[i] - v.vect[i];
        }
        else if (i >= this->size)
        {
            tmp.vect[i] = v.vect[i];
        }
        else
        {
            tmp.vect[i] = this->vect[i];
        }
    }
    return tmp;
}
template <typename T> Vector<T> Vector<T>::operator - (T n)              // Вычитание числа из вектора
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = this->vect[i] - n;
    }
    return tmp;
}
template <typename T> Vector<T>& Vector<T>::operator -= (const Vector<T>& v)  // Перегруженный оператор -= для вычитания двух векторов
{
    *this = *this - v;

    return *this;
}
template <typename T> Vector<T> Vector<T>::operator * (const Vector<T>& v)    // Умножение векторов
{
    int max_size;

    if (this->size > v.size)

        max_size = this->size;

    else max_size = v.size;

    Vector <T> tmp(max_size);

    for (size_t i = 0; i < max_size; i++)
    {
        if (i < this->size && i < v.size)
        {
            tmp.vect[i] = this->vect[i] * v.vect[i];
        }
        else if (i >= this->size)
        {
            tmp.vect[i] = v.vect[i];
        }
        else
        {
            tmp.vect[i] = this->vect[i];
        }
    }
    return tmp;
}
template <typename T> Vector<T> Vector<T>::operator * (T n)              // Умножение вектора на число
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = this->vect[i] * n;
    }
    return tmp;
}
template <typename T> Vector<T>& Vector<T>::operator *= (T n)            // Перегруженный оператор *= для умножения вектора на число
{
    *this = *this * (n);

    return *this;
}

template <typename T> istream& operator >> (istream& cin, Vector<T>& v)  // Ввод вектора с клавиатуры
{

    for (int i = 0; i < v.GetSize(); i++)
    {
        cin >> v.vect[i];
    }

    return cin;
}

template <typename T> ostream& operator << (ostream& cout, Vector<T>& v)  // Вывод вектора на экран
{
    for (int i = 0; i < v.GetSize(); i++)
    {
        cout << "\t" << v.vect[i];
    }

    return cout;
}








