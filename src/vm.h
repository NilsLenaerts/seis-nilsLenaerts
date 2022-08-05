#pragma once
#include "bytestream.h"
#include "instructions.h"
#include <string>

class Vm
{
public:
	Vm();
	void loadFile(std::string path);
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

