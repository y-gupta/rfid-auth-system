#include <iostream>
#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include "rfid.h"
using namespace std;


int main(){
	cout<<"Testing named pipe...\n";
	RFID::init("myfifo");
	while(1){
		cout<<"Press enter to get the card"<<endl;
		int i;
		cin>>i;	
		cout<<"received uid: "<<RFID::readCard()<<endl;
	}
}
