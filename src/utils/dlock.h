#ifndef __DLOCK_H__
#define __DLOCK_H__

#ifndef _WIN32
#include <pthread.h>
#else
#include <windows.h>
#endif

namespace utils {

    class bsm_i_lock
    {
    public:
        virtual ~bsm_i_lock() {};
        virtual void lock() const = 0;
        virtual void unlock() const = 0;
    };

    class dlock : public bsm_i_lock
    {
    public:
        dlock();
        ~dlock();

        virtual void lock() const;
        virtual void unlock() const;

    private:
#ifndef _WIN32
        mutable pthread_mutex_t m_mutex;
#else
        HANDLE m_mutex;
#endif
    };
} //namespace utils

#endif // !__DLOCK_H__
