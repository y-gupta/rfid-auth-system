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
#define MESSING 5
#define REBATE 6

class Request
{
public:
    Request();
    uint16_t type;
    uint64_t uid,device_id;
    void init(uint16_t _type);
    virtual string toString();
};
class AuthRequest : public Request{
public:
    uint64_t rfid;
    AuthRequest();
    void init(uint64_t _device_id, uint64_t _rfid);
    virtual string toString();
};
class CreateCardRequest : public Request{
public:
    uint64_t rfid;
    bool isMasterCard;
    CreateCardRequest();
    void init(uint64_t _device_id, uint64_t _uid,uint64_t rfid,bool master=false);
    virtual string toString();
};
class DeleteCardRequest : public Request{
public:
    uint64_t rfid;
    DeleteCardRequest();
    void init(uint64_t _device_id,uint64_t _uid,uint64_t _rfid);
    virtual string toString();
};
class AllowTempRequest : public Request{
public:
    AllowTempRequest();
    void init(uint64_t _device,uint64_t _uid);
    virtual string toString();
};
class MessingRequest : public Request{
public:
    uint32_t amount;
    MessingRequest();
    void init(uint64_t device,uint64_t uid,uint32_t amount);
    virtual string toString();
};
class RebateRequest : public Request{
public:
    string start,end;
    int n_meal;
    RebateRequest();
    void init(uint64_t device,uint64_t _uid,uint32_t nmeals,string _start="",string _end="" );
    virtual string toString();
};
#endif // REQUEST_H
