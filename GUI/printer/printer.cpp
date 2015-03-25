#include "printer.h"

printer::printer(){
    mkfifo("../printer/printer_pipe", 0666);
}
printer::~printer(){
	// unlink("printer_pipe");
}
int printer::printit(string message)
{
	bzero(buf,1024);
	memcpy(buf,message.c_str(),message.size());
	
    fd = open("../printer/printer_pipe", O_WRONLY);
	
	if(fd<0){
		cout<<"Cannot open pipe"<<endl;
		return -1;
	}
	write(fd,buf,1024); 
	close(fd);
	return 1;
}
//int main(int argc,char** argv){
//printer tmt81;

//tmt81.printit("manav chutiya hai");
/*
 while(true){
     string s;
     cin>>s;
     tmt81.printit(s);
}
*/
//}
