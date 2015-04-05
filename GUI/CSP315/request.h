#ifndef REQUEST_H
#define REQUEST_H
#include <stdint.h>
#include <iostream>
using namespace std;
#define AUTH 0
class Request
{
public:
    Request();
    uint16_t type;
    virtual string toString();
};

#endif // REQUEST_H
