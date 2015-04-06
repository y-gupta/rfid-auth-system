#include "request.h"

Request::Request(){
    init();
}
void Request::init(uint16_t _type){
    type=_type;
}

string Request::toString(){
    return "?type=shubh&&uid=123";
}
