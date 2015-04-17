#include <iostream>
#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include <fstream>

using namespace std;
int main(){
	string s;
	cout<<"write open"<<endl;
	int ofd = open("pipe",O_WRONLY);
	cout<<"read open"<<endl;
	int ifd = open("pipe1",O_RDONLY);
	cout<<"hey there"<<endl;
	
	char* buff = new char[10];
	
	cout<<"hey re"<<endl;
	size_t n;
	n=10;
	FILE *dummy = fdopen(ifd,"r");
	
	while(1){

		//int bytes = read(fd,buff,20);
		write(ofd,"shubham\n",9);
		cout<<"asd\n";
		getline(&buff,&n,dummy);
		cout<<"done"<<endl;
		// while(read(ifd,buff,1)){
		// 	if(*buff=='\n')
		// 		break;
		// 	cout<<"in"<<endl;
		// }
		// cout<<"hey"<<endl;
		//int b=read(ifd,buff,12);
		//cout<<b<<endl;
		// fout<<"shubham\n";
		// cout<<"written"<<endl;
		// //usleep(100000);
		// string str;
		// getline(fin,str);
		// cout<<str<<endl;

		//cout<<s.size()<<endl;
		//string str(buff,bytes);
		//cout<<str<<endl;
		//cout<<s<<endl;
	}
	close(ofd);
	close(ifd);
	return 0;
}