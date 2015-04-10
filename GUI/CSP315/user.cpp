#include "user.h"

User::User(){
    init();
}
void User::init(uint64_t _id,string _u,string _e,string _h,bool _isAdmin,string _pin){
    user_name = _u;
    entry_no = _e;
    hostel_name = _h;
    rfid = _id;
    pin = _pin;
    isAdmin = _isAdmin;
}
void User::clear(){
    init();
}
