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
    uint64_t uid,device_id;
    void init(uint16_t _type=0,uint64_t _device_id=0,uint64_t _uid=0);
    virtual string toString();
};
class AuthRequest : public Request{
public:
    uint64_t rfid;
    AuthRequest();
    virtual string toString();
};
class CreateCardRequest : public Request{
public:
    uint64_t rfid;
    bool isMasterCard;
    CreateCardRequest();
    virtual string toString();
};
class DeleteCardRequest : public Request{
public:
    uint64_t rfid;
    DeleteCardRequest();
    virtual string toString();
};
class AllowTempRequest : public Request{
public:
    AllowTempRequest();
    virtual string toString();
};
class MessingRequest : public Request{
public:
    uint32_t amount;
    MessingRequest();
    virtual string toString();
};
class RebateRequest : public Request{
public:
    string start,end;
    int n_meal;
    RebateRequest();
    virtual string toString();
};
#endif // REQUEST_H
