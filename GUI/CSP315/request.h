#ifndef REQUEST_H
#define REQUEST_H
#include <stdint.h>
#include <iostream>

using namespace std;

#define AUTH 0
#define CREATE_MASTER_CARD 1
#define CREATE_NEW_CARD 2
#define DELETE_CARD 3
#define ALLOW_TEMP 4


class Request
{
public:
    Request();
    uint16_t type;
    void init(uint16_t _type=0);
    virtual string toString();
};

#endif // REQUEST_H
