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
using namespace std;

class printer{
private: 
	char buf[1024];
	int fd;
public:
	printer();
	~printer();
	int printit(string message);
};

// declare printer object before starting python module

#endif 