#include "file_manager.h"


bool saveObject(char* file, void* Object, int SizeOfObject) {

	try
	{
		if (file == "")	throw "wrong path";
		std::ofstream outfile(file, std::ios::out | std::ios::app | std::ios::binary);
		if (!outfile)
		{
			std::cerr << "\a\n\nError while trying to open the file : " << *file <<"\n\n";
			return 0;
		}
		outfile.write((char*) Object, SizeOfObject);
		outfile.close();
	}
	catch (const char *exception)
	{
		std::cerr << "\n*** " << exception << " ***\n";
	}
	catch (...)
	{
		std::cerr << "\n*** Wild ERROR appeared ***\n";
		return 0;
	}
	return 1;
}


bool loadObject(char* file, void *Object, int SizeOfObject){

	try
	{
		if (file == "")	throw "wrong path";

		std::ifstream infile(file, std::ios::binary);
		if (!infile)
		{
			std::cerr << "\a\n\nError while trying to read the file : " << *file << "\n\n"; std::cerr << "\a\n\nErri\n\n";
			return 0;
		}
		infile.read((char*) Object, SizeOfObject);
		infile.close();
	}
	catch (const char *exception)
	{
		std::cerr << "\n*** " << exception << " ***\n";
	}
	catch (...)
	{
		std::cerr << "\n*** Wild ERROR appeared ***\n";
		return 0;
	}
	return 1;
}