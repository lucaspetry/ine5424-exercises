// EPOS Mutex Abstraction Implementation

#include <mutex.h>

__BEGIN_SYS

Mutex::Mutex(): _locked(false)
{
    db<Synchronizer>(TRC) << "Mutex() => " << this << endl;
}


Mutex::~Mutex()
{
    db<Synchronizer>(TRC) << "~Mutex(this=" << this << ")" << endl;
}


void Mutex::lock()
{
    db<Synchronizer>(TRC) << "Mutex::lock(this=" << this << ")" << endl;

    begin_atomic();
    if(tsl(_locked)) {
        sleep(); // implic  it end_atomic()
    } else {
        end_atomic();
    }
}


void Mutex::unlock()
{
    db<Synchronizer>(TRC) << "Mutex::unlock(this=" << this << ")" << endl;

    begin_atomic();
    _locked = false;

    if(!_sleeping.empty()) {
        wakeup(); // implicit end_atomic()
    } else {
        end_atomic();
    }
}

__END_SYS
