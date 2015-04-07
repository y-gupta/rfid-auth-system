#include "response.h"

Response::Response()
{   resp = "";
    isset = false;
    type = 100;
}
void Response::set(string res,uint16_t _type){
    resp = res;
    type = _type;
    isset = true;
}
void Response::unset(){
    resp = "";
    type = 100;
    isset = false;
}
