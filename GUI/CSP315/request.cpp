#include "request.h"
#include "utility.cpp"

Request::Request(){
}
void Request::init(uint16_t _type){
    type=_type;
}

string Request::toString(){
    return "?type="+to_string(type)+"&device="+to_string(device_id)+"&uid="+to_string(uid);
}

void AuthRequest::init(uint64_t _device_id, uint64_t _rfid){
    type = AUTH;
    device_id = _device_id;
    rfid = _rfid;
}
string AuthRequest::toString(){
    return "?type="+to_string(type)+"&device="+to_string(device_id)+"&rfid="+to_string(rfid);
}

void CreateCardRequest::init(uint64_t _device_id, uint64_t _uid,uint64_t _rfid,bool master){
    if(master)type = CREATE_MASTER_CARD;
    else type = CREATE_NEW_CARD;
    device_id = _device_id;
    uid = _uid;
    rfid = _rfid;
    isMasterCard = master;
}
string CreateCardRequest::toString(){
    return "?type="+to_string(type)+"&device="+to_string(device_id)+
            "&uid="+to_string(uid)+"&rfid="+to_string(rfid)+"&master="+to_string(isMasterCard);
}
void DeleteCardRequest::init(uint64_t _device_id,uint64_t _uid,uint64_t _rfid){
    type = DELETE_CARD;
    device_id = _device_id;
    uid = _uid;
    rfid = _rfid;
}
string DeleteCardRequest::toString(){
     return "?type="+to_string(type)+"&device="+to_string(device_id)+
             "&uid="+to_string(uid)+"&rfid="+to_string(rfid);
}
void AllowTempRequest::init(uint64_t _device,uint64_t _uid){
    type = ALLOW_TEMP;
    device_id = _device;
    uid = _uid;
}
string AllowTempRequest::toString(){
    return "?type="+to_string(type)+"&device="+to_string(device_id)+
            "&uid="+to_string(uid);
}
void MessingRequest::init(uint64_t _device,uint64_t _uid,uint32_t _amount){
    type = MESSING;
    device_id = _device;
    uid = _uid;
    amount = _amount;

}
string MessingRequest::toString(){
    return "?type="+to_string(type)+"&device="+to_string(device_id)+
            "&uid="+to_string(uid)+"&amount="+to_string(amount);
}

void RebateRequest::init(uint64_t device,uint64_t _uid,uint32_t _n_meal,string _start,string _end){
    type = REBATE;
    device_id = device;
    uid= _uid;
    n_meal = _n_meal;
    start = _start;
    end=_end;
}
string RebateRequest::toString(){
    return "?type="+to_string(type)+"&device="+to_string(device_id)+
            "&uid="+to_string(uid)+"&n_meals="+to_string(n_meal)+"&start="+start
            +"&end="+end;
}
