#include <iostream>
#include <memory>

class Mutex { };

class Uncopyable
{
public:
    Uncopyable() { }
    ~Uncopyable() { }
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

class Lock : private Uncopyable
{
public: 
    Lock(Mutex* pm) : mutexPtr(pm) 
    {
        std::cout << "Lock construct\n";
        lock(mutexPtr);
    }
    ~Lock() { unlock(mutexPtr); }
private:
    static void lock(Mutex* pm) { std::cout << "Lock lock\n"; }
    static void unlock(Mutex* pm) { pm = nullptr; std::cout << "Lock unlock\n"; }
    Mutex* mutexPtr;
};

class Lock_SHA
{
public:
    explicit Lock_SHA(Mutex* pm) : mutexPtr(pm, unlock)
    {
        std::cout << "Lock_SHA constructor\n";
        lock(mutexPtr.get());
    }
    
private:
    static void lock(Mutex* pm) { std::cout << "Lock_SHA lock\n"; }
    static void unlock(Mutex* pm) { pm = nullptr; std::cout << "Lock_SHA unlock\n"; }
    std::shared_ptr<Mutex> mutexPtr;
};

int main()
{
    Mutex m1;

    Lock ml1(&m1);

    // Lock ml2(ml1);  forbit copy

    Lock_SHA ls1(&m1);
    Lock_SHA ls2(ls1);
    return 0;
}
