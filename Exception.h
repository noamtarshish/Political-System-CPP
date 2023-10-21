#ifndef ASSIGNMENT5_EXCEPTION_H
#define ASSIGNMENT5_EXCEPTION_H //compilation guard
#include <exception>
using namespace std;

class idInvalidException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Please enter valid id";
    }
};

class nameInvalidException: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Please enter valid name";
    }
};

class detailsInvalidException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Please enter valid details";
    }
};

//class badAlloc : public exception {
//public:
//    virtual const char *what() const throw()
//    {
//        return
//    }
//
//};

#endif //ASSIGNMENT5_EXCEPTION_H
