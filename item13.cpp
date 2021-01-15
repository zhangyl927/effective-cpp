#include <iostream>
#include <memory>

class Investment 
{ 
public:
    Investment() : str(new std::string("hello")) { std::cout << "constructor\n"; }
    std::string* str;
};

Investment* createInvestment()
{
    return new Investment();
}

void fun_autoPtr()
{
    std::auto_ptr<Investment> pInv1(createInvestment());
    std::cout << "pInv1 = " << pInv1->str;

    std::auto_ptr<Investment> pInv2(pInv1);
    std::cout << "\nauto_ptr<Investment> pInv2(pInv1): ";
    // std::cout << "pInv1 = " << pInv1->str;  pInv1 is nullptr
    std::cout << "\npInv2 = " << pInv2->str;

    pInv1 = pInv2;
    std::cout << "\npInv1 = pInv2: ";
    std::cout << "\npInv1 = " << pInv1->str;
    // std::cout << "pInv2 = " << pInv2->str;  pInv2 is nullptr
}

void fun_sharedPtr()
{
    std::shared_ptr<Investment> pInv1(createInvestment());
    std::cout << "pInv1 = " << pInv1->str;

    std::shared_ptr<Investment> pInv2(pInv1);
    std::cout << "\nshared_ptr<Investment> pInv2(pInv1): ";
    std::cout << "\npInv1 = " << pInv1->str;
    std::cout << "\npInv2 = " << pInv2->str;

    pInv1 = pInv2;
    std::cout << "\npInv1 = pInv2: ";
    std::cout << "\npInv1 = " << pInv1->str;
    std::cout << "\npInv2 = " << pInv2->str << std::endl;
}

int main()
{
    std::cout << "auto ptr:\n";
    fun_autoPtr();

    std::cout << "\n--------------------------------------------------------------\n";

    std::cout << "shared ptr:\n";
    fun_sharedPtr();

    return 0;
}
