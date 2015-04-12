#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include <stdint.h>
using namespace std;

class User
{
public:
    string user_name,entry_no,hostel_name;
    uint64_t rfid;
    bool isAdmin;
    User();
    void init(uint64_t id = 0,string _u = "",string _e = "",string _h="",bool isAdmin=false);
    void clear();
};

#endif // USER_H
