#include "request.h"
#include "utility.cpp"

Request::Request(){
}
void Request::init(uint16_t _type){
    type=_type;
}

string Request::toString(){
    return "";
}

void AuthRequest::init(string _mac, uint64_t _rfid){
    type = AUTH;
    mac = _mac;
    rfid = _rfid;
}
string AuthRequest::toString(){
    return "/user/login/?&mac="+mac+"&rfid="+to_string(rfid);
}

void CreateCardRequest::init(string _mac,string _pin,uint64_t _rfid,bool master){
    if(master)type = CREATE_MASTER_CARD;
    else type = CREATE_NEW_CARD;
    mac = _mac;
    rfid = _rfid;
    pin = _pin;
    isMasterCard = master;
}
string CreateCardRequest::toString(){
    string res="/device/add/?&mac="+mac
            +"&rfid="+to_string(rfid)+"&pin="+pin+"&master=";
    if(isMasterCard)res+="true";
    else res+="false";
    return res;
}
void DeleteCardRequest::init(string _mac,string _pin,uint64_t _rfid){
    type = DELETE_CARD;
    mac = _mac;
    pin = _pin;
    rfid = _rfid;
}
string DeleteCardRequest::toString(){
     return "/device/delete/?mac="+mac+"&rfid="+to_string(rfid)
             +"&pin="+pin;
}
void AllowTempRequest::init(string _mac,string _pin){
    type = ALLOW_TEMP;
    mac = _mac;
    pin=_pin;
}
string AllowTempRequest::toString(){
    return "/device/allow/?mac="+mac+"&rfid="+to_string(rfid)
            +"&pin="+pin;
}
void MessingRequest::init(string _mac,uint64_t _rfid,uint32_t _amount){
    type = MESSING;
    mac = _mac;
    rfid = _rfid;
    amount = _amount;

}
string MessingRequest::toString(){
    return "user/transact/?mac="+mac+"&rfid="+to_string(rfid)
            +"&amount="+to_string(amount);
}

void RebateRequest::init(string _mac,uint64_t _rfid,uint32_t _n_meal,string _start,string _end){
    type = REBATE;
    mac = _mac;
    rfid = _rfid;
    n_meal = _n_meal;
    start = _start;
    end=_end;
}
string RebateRequest::toString(){
    return "/user/rebate/?mac="+mac+"&n_meals="+to_string(n_meal)
            +"&start="+start+"&end="+end;
}
void StaffLoginRequest::init(string _mac, string _pin){
    type = STAFF_LOGIN_REQ;
    mac = _mac;
    pin = _pin;
}
string StaffLoginRequest::toString(){
    return "/device/login/?mac="+mac+"&password="+pin;
}
void InitRequest::init(string _mac){
    type = INIT;
    mac =_mac;
}
string InitRequest::toString(){
    return "/ /?mac="+mac;
}
