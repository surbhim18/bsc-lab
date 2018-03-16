#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    private:
        char* msg;
    public:
        MyException(const char*);
        ~MyException();
        void print();

};

#endif // MYEXCEPTION_H
