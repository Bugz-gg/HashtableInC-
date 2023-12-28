#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

template <typename T>
class Hashtable
{
private:
    int size;
    T *table;

public:
    void insert(T &);
    void remove(T &);
    T search(T &);
    Hashtable();
    Hashtable(int sz);
    ~Hashtable();
};

template <typename T>
Hashtable<T>::Hashtable() : size(0), table(nullptr) {}

template <typename T>
Hashtable<T>::Hashtable(int sz) : size(sz), table(new T[sz]) {}

template <typename T>
Hashtable<T>::~Hashtable()
{
    if (table != nullptr)
    {
        delete[] table;
    }
}

template <typename T>
void Hashtable<T>::insert(T &data)
{
    int index = data % size;
    if (table == nullptr)
    {
        cerr << "Table is not initialized" << endl;
    }
    else
    {
        if (table[index] == T())
        {
            table[index] = data;
        }
        else
        {
            int i = 1;
            while (index + i < this->size && table[index + i] != T())
            {
                i++;
            }
            if (index + i >= this->size)
            {
                cerr << "Can't insert data." << endl;
            }
            else
            {
                table[index + i] = data;
                cout << "Data inserted at index " << index + i << table[index + i] << endl;
            }
        }
    }
}

template <typename T>
T Hashtable<T>::search(T &data)
{
    int index = data % size;
    if (table == nullptr)
    {
        cerr << "Table is not initialized" << endl;
        return T();
    }
    else
    {
        if (table[index] != T())
        {
            return table[index];
        }
        else
        {
            int i = 1;
            while (index + i < this->size && table[index + i] != T())
            {
                i++;
            }
            if (index + i >= this->size)
            {
                cerr << "Data not found." << endl;
                return T();
            }
            else
            {
                return table[index + i];
            }
        }
    }
}

template <>
string Hashtable<string>::search(string &data)
{
    int index = data.length() % size;
    if (table == nullptr)
    {
        cerr << "Table is not initialized" << endl;
        return string("EXIT_FAILURE");
    }
    else
    {
        if (table[index] != string())
        {
            return table[index];
        }
        else
        {
            int i = 1;
            while (index + i < this->size && table[index + i] != string())
            {
                i++;
            }
            if (index + i >= this->size)
            {
                cerr << "Data not found." << endl;
                return string("EXIT_FAILURE");
            }
            else
            {
                return table[index + i];
            }
        }
    }
}

template <>
void Hashtable<string>::remove(string &data)
{
    int index = data.length() % size;
    if (table == nullptr)
    {
        cerr << "Table is not initialized" << endl;
    }
    else
    {
        if (table[index] == string())
        {
            cerr << "Data not found." << endl;
        }
        else
        {
            int i = 1;
            while (index + i < this->size && table[index + i] != string())
            {
                i++;
            }
            if (index + i >= this->size)
            {
                cerr << "Data not found." << endl;
            }
            else
            {
                table[index + i] = string();
            }
        }
    }
}

template <>
void Hashtable<string>::insert(string &data)
{
    int index = data.length() % size;
    if (table == nullptr)
    {
        cerr << "Table is not initialized" << endl;
    }
    else
    {
        if (table[index] == string())
        {
            table[index] = data;
        }
        else
        {
            int i = 1;
            while (index + i < this->size && table[index + i] != string())
            {
                i++;
            }
            if (index + i >= this->size)
            {
                cerr << "Can't insert data." << endl;
            }
            else
            {
                table[index + i] = data;
                cout << "Data inserted at index " << index + i << table[index + i] << endl;
            }
        }
    }
}

template <typename T>
void Hashtable<T>::remove(T &data)
{
    int index = data % size;
    if (table == nullptr)
    {
        cerr << "Table is not initialized" << endl;
    }
    else
    {
        if (table[index] == T())
        {
            cerr << "Data not found." << endl;
        }
        else
        {
            int i = 1;
            while (index + i < this->size && table[index + i] != T())
            {
                i++;
            }
            if (index + i >= this->size)
            {
                cerr << "Data not found." << endl;
            }
            else
            {
                table[index + i] = T(); 
            }
        }
    }
}