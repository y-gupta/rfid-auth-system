#include "rfid.h"

void RFID::init(){
	cout<<"Creating pipe ";
    mkfifo("../rfid/rfid_pipe",0666);
//	if(success !=0){
//		cout<<"Error in creating pipe!"<<endl;
//		exit(1);
//	}
	cout<<"pipe created ..."<<endl;
}
int64_t RFID::readCard(){
    return 1;
//    char buff[20];

//	int fd = open("../rfid/rfid_pipe",O_WRONLY);
//	assert(fd != -1 && "error opening");
//	cout<<"writing..."<<endl;
//	int bytes = write(fd,"GET",sizeof("GET"));
//	close(fd);
//	assert(bytes != -1 && "write successful");
//	cout<<"writing complete"<<endl;


//    fd = open("../rfid/rfid_pipe",O_RDONLY);
//	assert(fd != -1 && "error opening");
//	cout<<"reading..."<<endl;
//	bytes = read(fd,buff,12);
//	assert(bytes != -1 && "read successful");
//	buff[12]=0;
//	if(buff[0]=='F')return -1;
//	return atoll(buff);
//	close(fd);
}
