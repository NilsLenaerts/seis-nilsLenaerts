#pragma once
#include "bytestream.h"
#include "constants.h"
#include <stack>
#include <string>

class Vm
{
public:
	Vm();
	void loadFile(std::string path);
	std::stack<u_int32_t> uInt32Stack;
private:
	ByteStream byteStream;

	void readTypeSection();
	void readFuncSection();
	void readCodeSection();
	void readExportSection();
	void readMemorySection();
	void readDataSection();
	void readDataCountSection();
	void readImportSection();
};

