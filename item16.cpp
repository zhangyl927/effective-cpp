#include <iostream>

// 存储结构上，new[] 对象在储存起始处，记录了对象个数 n 。
// delete[] 调用 n 次析构函数，然后回收内存。

// 不要使用 typedef 
typedef std::string AddressLines[4];

// 类中有多个构造函数进行动态内存分配，需统一形式，否则析构函数中 delete 不知道用哪种形式。

int main()
{
    std::string* str1 = new std::string;
    std::string* str2 = new std::string[100];
    
    delete str1;
    delete[] str2;
    
    std::string* pa = new AddressLine;
    // delete pa;		# error
    
    return 0;
}
