#include <stdio.h>
#include <iostream>
#include <string.h>

/*
            �ص�����ѧϰ
1.void (*)���ֱ�ʾ����һ��ָ������ָ�����������������void���Ը���ʵ�������޸�Ϊ�κ������Ϸ��ķ������ͣ�����int��double��char*�ȵ�
2.�ַ������������� "gogo"���������� const char[]������������Ϊ���� char* ʱ����ͼ��һ�������ַ���ת��Ϊ�ǳ������ַ�ָ�룬���ǲ���ȫ����Ϊ�����ܵ���������ڴ���ʴ���
*/
void someFunction(const char *(*any_function)(int, double), int arg1, double arg2)
{
    std::string hehe = any_function(arg1, arg2);
    std::cout << "Receive the return value of the callback function:" << hehe << std::endl;
}

const char *Callback(int arg1, double arg2)
{
    std::cout << "Callback function called with arg1 = " << arg1 << " and arg2 = " << arg2 << std::endl;
    // ע������ĸ�ֵ
    return "��������ǻص������ķ���ֵ";
}

int main()
{
    someFunction(Callback, 19, 8.89);
    return 0;
}