#include <iostream>

void logCall(const std::string& funcName)
{
    std::cout << funcName << std::endl;
}

class Customer
{
public:
    Customer(std::string strName) : name(strName) { }
    Customer(const Customer&);
    Customer& operator=(const Customer&);

private:
    std::string name;
};

Customer::Customer(const Customer& rhs)
    : name(rhs.name)
{
    logCall("copy constructor");
}

Customer& Customer::operator=(const Customer& rhs)
{
    logCall("copy assign");
    name = rhs.name;
    return *this;
}

int main()
{
    Customer c1("hello world");
    Customer c2("effective");

    return 0;
}
