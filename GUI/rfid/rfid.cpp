#include "rfid.h"
#include <cstdio>
#include <cstdlib>

void RFID::init(){
    mkfifo("../rfid/rfid_pipe",0666);
    srand(0);
}
int64_t RFID::readCard(){
    if(rand()%10000 < 9999)
        return -1;
    else
        return 1;
//    char buff[20];
//    int fd = open("../rfid/rfid_pipe",O_WRONLY);
//    assert(fd != -1 && "error opening");
//    int bytes = write(fd,"GET",sizeof("GET"));
//    close(fd);
//    assert(bytes != -1 && "write successful");


//    fd = open("../rfid/rfid_pipe",O_RDONLY);
//    assert(fd != -1 && "error opening");
//    bytes = read(fd,buff,12);
//    assert(bytes != -1 && "read successful");
//    buff[12]=0;
//    if(buff[0]=='F')return -1;
//    return atoll(buff);
//    close(fd);
}
