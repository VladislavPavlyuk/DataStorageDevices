#pragma once
#include <iostream>
using namespace std;


template <typename T> class Vector
{
    T* vect;                                    //  ������
    int size;                                   //  ����������� �������

public:
    Vector()
    {                                           //  ����������� �� ���������

        vect = nullptr;
        size = 0;
    }

    explicit Vector(int size) {                   //  �����������, ����������� �������� ����������� �������

        vect = new T[size];

        this->size = size;
    }

    Vector(const T* ptr, int size)
    {                                               //  �����������, �����������  ������������������� ������  � ������� ������������� �������

        vect = new T[size];

        this->size = size;

        for (size_t i = 0; i < size; i++)
        {
            vect[i] = ptr[i];
        }
    }

    Vector(const Vector<T>& v)                         // ����������� �����������
    {
        this->size = v.size;

        this->vect = new T[size];

        for (size_t i = 0; i < size; i++)
        {
            vect[i] = v.vect[i];
        }
    }

    Vector(Vector<T>&& v)                               // ����������� ��������
    {
        vect = v.vect;
        size = v.size;
        v.vect = nullptr;
        v.size = 0;
    }

    ~Vector()                                           // ����������
    {
        delete[]vect;
    }

    int GetSize() const
    {                                           //  ������� ���������� ����������� �������

        return size;

    }

    void Print();                        // ����� �� �����

    void Input();                        // ���������� �������

    void Clear();                        //  ������� �������

    bool IsEmpty() const;               // ���������� ������, ���� ������ �����

    void Add(const T& item);          // ���������� �������� � ������

    void Insert(int index, const T& item); // ������� ��������� � ������ �� ��������� �������

    void Remove(int index);                 //  �������� �������� �� ������� �� ��������� �������

    Vector& operator ++ ();                 // ���������� ���� ��������� ������� �� ������� (�������)

    Vector operator ++ (int k);             // ���������� ���� ��������� ������� �� ������� (��������)

    Vector& operator -- ();                 // ���������� ���� ��������� ������� �� ������� (�������)

    Vector operator -- (int k);             // ���������� ���� ��������� ������� �� ������� (��������)

    Vector<T>& operator = (const Vector<T>& v);   // ������������� �������� ������������ � ������������

    Vector<T>& operator = (Vector<T>&& v);        // ������������� �������� ������������ � ���������

    T& operator [] (int index);           // ������������� �������� ����������

    Vector operator + (const Vector<T>& v);    // �������� ���� ��������

    Vector operator + (T n);              // �������� ������� � ������ (������ ��������� ������� ������������ � ������)

    Vector& operator += (const Vector<T>& v);  // ������������� �������� += ��� �������� ���� ��������

    Vector operator - (const Vector<T>& v);    // ��������� ���� ��������

    Vector operator - (T n);              // ��������� ����� �� �������

    Vector& operator -= (const Vector<T>& v);  // ������������� �������� -= ��� ��������� ���� ��������

    Vector operator * (const Vector<T>& v);    // ��������� ��������

    Vector operator * (T n);              // ��������� ������� �� �����

    Vector& operator *= (T n);            // ������������� �������� *= ��� ��������� ������� �� �����

    template <typename T> friend istream& operator >> (istream& cin, Vector<T>& v);  // ���� ������� � ����������

    template <typename T> friend ostream& operator << (ostream& cout, Vector<T>& v);  // ����� ������� �� �����
};

template <typename T> void Vector<T>::Print() {                              // ����� �� �����

    cout << endl;

    for (size_t i = 0; i < size; i++)
    {
        cout << "\t" << vect[i];
    }

    cout << "\tsize = " << size;

    cout << endl;
}


template <typename T> void Vector<T>::Input() {                       // ���������� �������

    cout << "\nPlease enter " << GetSize() << " numbers\n";;

    for (size_t i = 0; i < GetSize(); i++)

    {
        cin >> vect[i];
    }
}

template <typename T> void Vector<T>::Clear() {                       //  ������� �������

    for (size_t i = 0; i < size; i++)

    {
        vect[i] = 0;
    }
}

template <typename T> bool Vector<T>::IsEmpty() const {               // ���������� ������, ���� ������ ������

    if (vect == nullptr)

        return true;

    else return false;
}

template <typename T> void Vector<T>::Add(const T& item) {          // ���������� �������� � ������

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

template <typename T> void Vector<T>::Insert(int index, const T& item) { // ������� ��������� � ������ �� ��������� �������

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

template <typename T> void Vector<T>::Remove(int index) {             //  �������� �������� �� ������� �� ��������� �������

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

template <typename T> Vector<T>& Vector<T>::operator ++ ()                 // ���������� ���� ��������� ������� �� ������� (�������)
{
    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]++;
    }
    return *this;
}

template <typename T> Vector<T> Vector<T>::operator ++ (int)             // ���������� ���� ��������� ������� �� ������� (��������)
{
    Vector tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]++;
    }
    return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator -- ()                 // ���������� ���� ��������� ������� �� ������� (�������)
{
    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]--;
    }
    return *this;
}

template <typename T> Vector<T> Vector<T>::operator -- (int)             // ���������� ���� ��������� ������� �� ������� (��������)
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        this->vect[i]--;
    }
    return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator = (const Vector<T>& v)   // ������������� �������� ������������ � ������������
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

template <typename T> Vector<T>& Vector<T>::operator = (Vector<T>&& v)        // ������������� �������� ������������ � ���������
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

template <typename T> T& Vector<T>::operator [] (int index)           // ������������� �������� ����������
{
    if (index < 0 || index >= size)

        return vect[0];

    return vect[index];
}

template <typename T> Vector<T> Vector<T>::operator + (const Vector<T>& v)    // �������� ���� ��������
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
template <typename T> Vector<T> Vector<T>::operator + (T n)          // �������� ������� � ������ (������ ��������� ������� ������������ � ������)
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = this->vect[i] + n;
    }
    return tmp;
}
template <typename T> Vector<T>& Vector<T>::operator += (const Vector<T>& v)  // ������������� �������� += ��� �������� ���� ��������
{
    *this = *this + v;

    return *this;
}
template <typename T> Vector<T> Vector<T>::operator - (const Vector<T>& v)    // ��������� ���� ��������
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
template <typename T> Vector<T> Vector<T>::operator - (T n)              // ��������� ����� �� �������
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = this->vect[i] - n;
    }
    return tmp;
}
template <typename T> Vector<T>& Vector<T>::operator -= (const Vector<T>& v)  // ������������� �������� -= ��� ��������� ���� ��������
{
    *this = *this - v;

    return *this;
}
template <typename T> Vector<T> Vector<T>::operator * (const Vector<T>& v)    // ��������� ��������
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
template <typename T> Vector<T> Vector<T>::operator * (T n)              // ��������� ������� �� �����
{
    Vector<T> tmp = *this;

    for (size_t i = 0; i < size; i++)
    {
        tmp[i] = this->vect[i] * n;
    }
    return tmp;
}
template <typename T> Vector<T>& Vector<T>::operator *= (T n)            // ������������� �������� *= ��� ��������� ������� �� �����
{
    *this = *this * (n);

    return *this;
}

template <typename T> istream& operator >> (istream& cin, Vector<T>& v)  // ���� ������� � ����������
{

    for (int i = 0; i < v.GetSize(); i++)
    {
        cin >> v.vect[i];
    }

    return cin;
}

template <typename T> ostream& operator << (ostream& cout, Vector<T>& v)  // ����� ������� �� �����
{
    for (int i = 0; i < v.GetSize(); i++)
    {
        cout << "\t" << v.vect[i];
    }

    return cout;
}








