#pragma once
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
	static void init();
	static int64_t readCard();
};