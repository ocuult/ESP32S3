#include <stdio.h>
#include <iostream>
#include <string.h>

/*
            回调函数学习
1.void (*)部分表示这是一个指向函数的指针类型声明。这里的void可以根据实际需求修改为任何其他合法的返回类型，比如int、double、char*等等
2.字符串字面量（如 "gogo"）的类型是 const char[]，而函数定义为返回 char* 时，试图将一个常量字符串转换为非常量的字符指针，这是不安全的行为，可能导致意外的内存访问错误。
*/
void someFunction(const char *(*any_function)(int, double), int arg1, double arg2)
{
    std::string hehe = any_function(arg1, arg2);
    std::cout << "Receive the return value of the callback function:" << hehe << std::endl;
}

const char *Callback(int arg1, double arg2)
{
    std::cout << "Callback function called with arg1 = " << arg1 << " and arg2 = " << arg2 << std::endl;
    // 注意这里的赋值
    return "我他妈的是回调函数的返回值";
}

int main()
{
    someFunction(Callback, 19, 8.89);
    return 0;
}