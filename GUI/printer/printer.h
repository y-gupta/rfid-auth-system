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
	string print_user(user usr);
public:
	printer();
	~printer();
	int rebate(user The_user,string start, string end);
	int extra_messing(user The_user,string amount);
};

#endif 