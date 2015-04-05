#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include <stdint.h>
using namespace std;

class user
{
public:
    string user_name,entry_no,hostel_name;
    uint64_t user_id;

    user();
    void init(uint64_t id = -1,string _u = "",string _e = "",string _h="");
    void clear();
};

#endif // USER_H
