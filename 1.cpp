#include <iostream>
#include <cassert>
using namespace std;
class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr) {}
    ArrayInt(int length) : m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
        {
            m_data = new int[length];
        }
        else
        {
            m_data = nullptr;
        }
    }
    ~ArrayInt()
    {
        delete[] m_data;
    }
    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    int &operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    int getLength()
    {
        return m_length;
    }
    void resize(int newLength)
    {
        if (newLength == m_length)
        {
            return;
        }
        if (newLength <= 0)
        {
            erase();
            return;
        }
        int *data = new int[newLength];
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index = 0; index < elementsToCopy; ++index)
            {
                data[index] = m_data[index];
            }
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }
    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length + 1];
        for (int before = 0; before < index; ++before)
        {
            data[before] = m_data[before];
        }
        data[index] = value;
        for (int after = index; after < m_length; ++after)
        {
            data[after + 1] = m_data[after];
        }
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value)
    {
        insertBefore(value, m_length);
    }
    void Remove(int index)
    {
        assert(index >= 0 && index < m_length);
        if (m_length == 1)
        {
            erase();
            return;
        }
        int *data = new int[m_length - 1];
        for (int before = 0; before < index; ++before)
        {
            data[before] = m_data[before];
        }
        for (int after = index + 1; after < m_length; ++after)
        {
            data[after - 1] = m_data[after];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }
    void Sort() const
    {
        for (int i = 0; i < m_length; i++)
        {
            bool flag = true;
            for (int j = 0; j < m_length - (i + 1); j++)
            {
                if (m_data[j] > m_data[j + 1])
                {
                    flag = false;
                    swap(m_data[j], m_data[j + 1]);
                }
            }
            if (flag)
            {
                break;
            }
        }
    }
    void Print() const
    {
        for (int j = 0; j < m_length; j++)
        {
            cout << m_data[j] << " ";
        }
    }
};
int main()
{
    ArrayInt array(10);
    for (int i = 0; i < (array.getLength()); i++)
    {
        array[i] = rand();
    }
    array.Remove(9); // Удаление последнего элемента
    array.Remove(0); // Удаление первого элемента
    array.Sort(); // Сортировка массива по возрастанию
    array.Print(); // Вывод массива на экран
    return 0;
}