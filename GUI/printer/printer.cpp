#include "printer.h"

printer::printer(){
    mkfifo("../printer/printer_pipe", 0666);
}

printer::~printer(){
	// unlink("printer_pipe");
}

string printer::print_user(user usr){
	line="******************************************************";
	string s;
	s=s+"user ID :-";
	int j=print_len-10-usr.user_name.length();
	for(int i=0; i!=j&&j>0; i++) s=s+" ";
	s=s+usr.user_name+"\nEntry No :-";
	j=print_len-11-usr.entry_no.length();
	for(int i=0; i!=j&&j>0; i++) s=s+" ";
	s=s+usr.entry_no+"\nHostel Name :-";
	j=print_len-14-usr.hostel_name.length();
	for(int i=0; i!=j&&j>0; i++) s=s+" ";
	s=s+usr.hostel_name+"\n";
	return s;
}

int rebate(user The_user,string start, string end){
	string s = line+"\n"+print_user(The_user)+"\n----Rebate Period----\n"+start+"\nTo\n"+end+"\n"+line+"\nTHANK YOU!!!\n.....";
    fd = open("../printer/printer_pipe", O_WRONLY);
	
	if(fd<0){
		cout<<"Cannot open pipe"<<endl;
		return -1;
	}

	bzero(buf,1024);
	memcpy(buf,s.c_str(),s.size());
	write(fd,buf,1024); 
	
	
	close(fd);
	return 1;
}
	int extra_messing(user The_user,string amount){
	
	string s = line+"\n"+print_user(The_user)+"\nThis Coupon is worth\n"+amount+"\n"+line+"\nTHANK YOU!!!\n.....";
	
	
    fd = open("../printer/printer_pipe", O_WRONLY);
	
	if(fd<0){
		cout<<"Cannot open pipe"<<endl;
		return -1;
	}
	
	bzero(buf,1024);
	memcpy(buf,s.c_str(),s.size());
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
