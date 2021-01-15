#include <iostream>

class Widget
{
public: 
    void swap(Widget& rhs);
    Widget(std::string str) : pb(new std::string(str)) {
        std::cout << "constructor\n";
    }

    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs);

    std::string* pb;
};

Widget::Widget(const Widget& rhs) : pb(new std::string(*rhs.pb)) 
{
    std::cout << "copy construct\n";
}

void Widget::swap(Widget& rhs)
{
    pb = rhs.pb;
}

Widget& Widget::operator=(const Widget& rhs)
{
    Widget temp(rhs);
    swap(temp);
    return *this;
}

int main()
{
    Widget w1("hello world\n");
    Widget w2("effective\n");

    std::cout << "&w1: " << w1.pb << "w1: " << *w1.pb << std::endl;
    std::cout << "&w2: " << w2.pb << "w2: " << *w2.pb << std::endl;

    w1 = w2;
    
    std::cout << "&w1: " << w1.pb << "w1: " << *w1.pb << std::endl;
    std::cout << "&w2: " << w2.pb << "w2: " << *w2.pb << std::endl;
    
    w2 = w2;

    std::cout << "&w1: " << w1.pb << "w1: " << *w1.pb << std::endl;
    std::cout << "&w2: " << w2.pb << "w2: " << *w2.pb << std::endl;

    return 0;
}

