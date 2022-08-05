#include "vm.h"

Vm::Vm()
{
	
}

void Vm::loadFile(std::string path)
{
	byteStream = ByteStream{ path };
	byteStream.seek(8); //skip webassembly magic number and version number
	Instructions section;
	while (!byteStream.atEnd()) {
		section = (Instructions)byteStream.readByte();
		switch (section)
		{
		case Instructions::custom:
			//custom section
            std::cout << "Custom section, do nothing" << std::endl;
			break;
		case Instructions::type:
			readTypeSection();
			break;
		case Instructions::import:
			readImportSection();
			break;
		case Instructions::function:
			readFuncSection();
			break;
		case Instructions::table:
			//table section not neccessary
			break;
		case Instructions::memory:
			readMemorySection();
			break;
		case Instructions::global:
			//global section
			break;
		case Instructions::code:
			readCodeSection();
			break;
		case Instructions::data:
			readDataSection();
			break;
		case Instructions::datacount:
			readDataCountSection();
			break;
		default:
			break;
		}
	}
}

void Vm::readTypeSection() 
{
	int length = byteStream.readUInt32(); //section size
	int typeCount = byteStream.readUInt32();
	for (int i = 0; i < typeCount; i++) {

	}
}

void Vm::readFuncSection()
{
}

void Vm::readCodeSection()
{
}

void Vm::readExportSection()
{
}

void Vm::readMemorySection()
{
}

void Vm::readDataSection()
{
}

void Vm::readDataCountSection()
{
}

void Vm::readImportSection()
{
}
