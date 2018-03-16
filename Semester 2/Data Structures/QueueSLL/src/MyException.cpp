#include<iostream>
#include<cstring>
#include "MyException.h"

MyException::MyException(char* str)
{
        msg = new char[30];
        strcpy(msg,str);
}

MyException::~MyException()
{
    delete []msg;
}


void MyException:: print()
{
    std::cout.write(msg,strlen(msg));
}
