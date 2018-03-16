#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    public:
        MyException(char* str);
        ~MyException();
        void print();

    private:
    char* msg;
};

#endif // MYEXCEPTION_H
