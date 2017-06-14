// EPOS Synchronizer Abstractions Common Package

#ifndef __synchronizer_h
#define __synchronizer_h

#include <cpu.h>
#include <thread.h>

__BEGIN_SYS

class Synchronizer_Common
{
protected:
    Thread::Queue _sleeping;
    Synchronizer_Common() {}

    ~Synchronizer_Common() {
        wakeup_all();
    }
    // Atomic operations
    bool tsl(volatile bool & lock) { return CPU::tsl(lock); }
    int finc(volatile int & number) { return CPU::finc(number); }
    int fdec(volatile int & number) { return CPU::fdec(number); }

    // Thread operations
    void begin_atomic() { Thread::lock(); }
    void end_atomic() { Thread::unlock(); }

    void sleep() {
        Thread::sleep(&_sleeping);
    } // implicit unlock()
    void wakeup() {
        Thread::wakeup(&_sleeping);
    } // implicit unlock()
    void wakeup_all() {
        Thread::wakeup_all(&_sleeping);
    } // implicit unlock()
};

__END_SYS

#endif

