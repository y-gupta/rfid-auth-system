#ifndef RESPONSE_H
#define RESPONSE_H
#include "thread.h"
#include <stdint.h>
class Response : public ThreadedEntity{
    string resp;
    bool isset;
    uint16_t type;
    Response();
    void set(string res,uint16_t type);
    void unset();

};
#endif // RESPONSE_H
