#include "rfid.h"
#include <cstdio>
#include <cstdlib>
#include <string>
void RFID::init(){
    mkfifo("../rfid/rfid_pipe1",0666);
    srand(0);
}
string RFID::readCard(){
     if(rand()%10000 < 9999)
         return "";
     else
         return "1";
//   char buff[20];
//   int fd = open("../rfid/rfid_pipe1",O_WRONLY);
//   assert(fd != -1 && "error opening");
//   int bytes = write(fd,"GET",sizeof("GET"));
//   close(fd);
//   assert(bytes != -1 && "write successful");
//   close(fd);

//   fd = open("../rfid/rfid_pipe2",O_RDONLY);
//   assert(fd != -1 && "error opening");
//   bytes = read(fd,buff,20);
//   assert(bytes != -1 && "read successful");
//   //buff[12]=0;
//   cout<<"read:"<<bytes<<" bytes"<<endl;
//   if(buff[0]=='F')return "";
//   return string(buff,bytes);
   
}
