#include "response.h"

Response::Response()
{   resp = "";
    isset = false;
    type = 100;
}
Response::set(string res,uint16_t _type){
    resp = res;
    type = _type;
    isset = true;
}
Response::unset(){
    resp = "";
    type = 100;
    isset = false;
}
