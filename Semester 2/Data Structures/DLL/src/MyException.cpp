#include<iostream>
#include<cstring>
#include "MyException.h"

MyException::MyException(char* str)
{
        msg = new char[strlen(str)];
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
