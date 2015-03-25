#include <iostream>
#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
using namespace std;
class RFID{
	public:
	static char named_pipe[20];
	static void init(const char* name){
		assert(name != 0);
		strncpy(named_pipe,name,sizeof(named_pipe));
		cout<<"Creating pipe "<<named_pipe;
		int success=mkfifo(named_pipe,0666);
		if(success !=0){
			cout<<"Error in creating pipe!"<<endl;
			exit(1);
		}
		cout<<"pipe created ..."<<endl;
	}
	static int64_t readCard(){
		char buff[20];

		int fd = open(named_pipe,O_WRONLY);
		assert(fd != -1 && "error opening");
		cout<<"writing..."<<endl;
		int bytes = write(fd,"GET",sizeof("GET"));
		close(fd);
		
		assert(bytes != -1 && "write successful");
		cout<<"writing complete"<<endl;
		fd = open(named_pipe,O_RDONLY);
		assert(fd != -1 && "error opening");
		cout<<"reading..."<<endl;
		bytes = read(fd,buff,12);
		assert(bytes != -1 && "read successful");
		buff[12]=0;
		if(buff[0]=='F')return -1;
		return atoll(buff);
		close(fd);
	}
};
char RFID::named_pipe[] = {'\0'};