#include <iostream>

class FontHandle{};

class Font
{
public:
    explicit Font(FontHandle fh) : f(fh) { }
    FontHandle get() const { return f; }		// 显式转换
    ~Font() { releaseFont(f); }
private:
    static void releaseFont(FontHandle fh) { std::cout << "release font\n"; }
    FontHandle f;
};

void changeFontSize(FontHandle f, int newSize)
{
    std::cout << "change Font size\n";
}

FontHandle getFont()
{
    std::cout << "return a FontHandle\n";
    return FontHandle();
}


// operator 实现隐式类型转换
template <class T>
class OpImEp
{
public:
    OpImEp(T d) : data(d) { }
    operator T() { return data; }
private:
    T data;
};



int main()
{
    Font f(getFont());
    int newFontSize;

    changeFontSize(f.get(), newFontSize);


    OpImEp<int> obj(2);
    obj = obj+1;
    std::cout << "obj = " << obj << std::endl;

    return 0;
}
