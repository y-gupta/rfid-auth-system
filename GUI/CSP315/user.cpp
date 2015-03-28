#include "user.h"

user::user(){
    init();
}
void user::init(uint64_t _id,string _u,string _e,string _h){
    user_name = _u;
    entry_no = _e;
    hostel_name = _h;
    user_id = _id;
}
void user::clear(){
    init();
}
