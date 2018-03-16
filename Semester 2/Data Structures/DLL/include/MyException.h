#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    private:
        char* msg;
    public:
        MyException(char*);
        ~MyException();
        void print();

};

#endif // MYEXCEPTION_H
