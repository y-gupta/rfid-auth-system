#ifndef PRINTER_H
#define PRINTER_H

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "user.h"

using namespace std;

#define print_len 30

class printer{
private: 
	string line;
	char buf[1024];
	int fd;
    string print_user(User usr);
public:
	printer();
	~printer();
    int rebate(User The_user,string start, string end);
    int extra_messing(User The_user,string amount);
};

#endif 
