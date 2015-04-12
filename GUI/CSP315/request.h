#ifndef REQUEST_H
#define REQUEST_H
#include <stdint.h>
#include <iostream>

using namespace std;


//Request and Response
#define AUTH 0
#define CREATE_MASTER_CARD 1
#define CREATE_NEW_CARD 2
#define DELETE_CARD 3
#define ALLOW_TEMP 4
#define MESSING_REQ 5
#define REBATE_REQ 6
#define STAFF_LOGIN_REQ 7
#define INIT 8

class Request
{
public:
    Request();
    uint16_t type;
    uint64_t rfid;
    string mac;
    void init(uint16_t _type);
    virtual string toString();
};
class AuthRequest : public Request{
public:

    void init(string _mac, uint64_t _rfid);
    virtual string toString();
};
class CreateCardRequest : public Request{
public:
    string pin;
    bool isMasterCard;
    void init(string _mac,string _pin,uint64_t rfid,bool master=false);
    virtual string toString();
};
class DeleteCardRequest : public Request{
public:
    string pin;
    void init(string _mac,string _pin,uint64_t _rfid);
    virtual string toString();
};
class AllowTempRequest : public Request{
public:
    string pin;
    void init(string _mac,string _pin);
    virtual string toString();
};
class MessingRequest : public Request{
public:
    uint32_t amount;
    void init(string _mac,uint64_t _rfid,uint32_t _amount);
    virtual string toString();
};
class RebateRequest : public Request{
public:
    string start,end;
    int n_meal;
    void init(string _mac,uint64_t _rfid,uint32_t _n_meal,string _start,string _end);
    virtual string toString();
};
class StaffLoginRequest : public Request{
public:
    string pin;
    void init(string _mac,string _pin);
    virtual string toString();
};
class InitRequest:public Request{
public:
    void init(string _mac);
    virtual string toString();
};

#endif // REQUEST_H
