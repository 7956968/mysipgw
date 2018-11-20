#ifndef __MYFIFO_H__
#define __MYFIFO_H__

#include <queue>
using namespace std;

template <class T>
class CMyFifo
{
public:
    T pop();
    int push(T data);
    int get_current_zise();
    int get_capacity();
    int set_capacity(int capacity);

    static CMyFifo<T>* m_instance;
    static CMyFifo<T>* get_instance()
    {
        if (NULL == m_instance)
        {
            m_instance = new CMyFifo();
            return m_instance;
        }
        else
        {
            return m_instance;
        }
    }

    static void release_instance()
    {
        if (NULL != m_instance)
        {
            delete m_instance;
        } 
    }

private:
    CMyFifo(int capacity = 200) :m_capacity(capacity) {}
    virtual ~CMyFifo()
    {

    }

    int m_capacity;
    std::queue<T> m_Fifo;
};

template <typename T>
CMyFifo<T>* CMyFifo<T>::m_instance = NULL;

template <class T>
T CMyFifo<T>::pop()
{
    if (!m_Fifo.empty())
    {
        T ret = m_Fifo.front();
        m_Fifo.pop();

        return ret;
    }
    else
    {
        return 0;
    }

}

template <class T>
int CMyFifo<T>::push(T data)
{
    if (m_Fifo.size() >= m_capacity)
    {
        //full
        return -1;
    }
    else
    {
        m_Fifo.push(data);
    }
}

template <class T>
int CMyFifo<T>::get_current_zise()
{
    return m_Fifo.size();
}

template <class T>
int CMyFifo<T>::get_capacity()
{
    return m_capacity;
}

template <class T>
int CMyFifo<T>::set_capacity(int capacity)
{
    m_capacity = capacity;
    return 0;
}

#endif
