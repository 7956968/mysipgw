#include "dlock.h"

namespace utils {

dlock::dlock()
{
#ifndef _WIN32
    pthread_mutex_init(&m_mutex, NULL);
#else
    m_mutex = ::CreateMutex(NULL, false, NULL);
#endif
}

dlock::~dlock()
{
#ifndef _WIN32
    pthread_mutex_destroy(&m_mutex);
#else
    ::CloseHandle(m_mutex);
#endif
}

void dlock::lock() const
{
#ifndef _WIN32
    pthread_mutex_lock(&m_mutex);
#else
    DWORD dw = WaitForSingleObject(m_mutex, INFINITE);
#endif
}

void dlock::unlock() const
{
#ifndef _WIN32
    pthread_mutex_unlock(&m_mutex);
#else
    ::ReleaseMutex(m_mutex);
#endif
}

} //namespace utils
