#include "vm.h"

Vm::Vm()
{
	
}

void Vm::loadFile(std::string path)
{
	byteStream = ByteStream{ path };
	byteStream.seek(8); //skip webassembly magic number and version number
	uint8_t section;
	while (!byteStream.atEnd()) {
		section = byteStream.readByte();
		switch (section)
		{
		case constants::CUSTOM_SECTION:
			//custom section
            std::cout << "Custom section, do nothing" << std::endl;
			break;
		case constants::TYPE_SECTION:
			readTypeSection();
			break;
		case constants::IMPORT_SECTION:
			readImportSection();
			break;
		case constants::FUNCTION_SECTION:
			readFuncSection();
			break;
		case constants::TABLE_SECTION:
			//table section not neccessary
			break;
		case constants::MEMORY_SECTION:
			readMemorySection();
			break;
		case constants::GLOBAL_SECTION:
			//global section
			break;
		case constants::CODE_SECTION:
			readCodeSection();
			break;
		case constants::DATA_SECTION:
			readDataSection();
			break;
		case constants::DATACOUNT_SECTION:
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
