#pragma once
#include <fstream>
#include <iostream>
#include <string>

bool saveObject(char* file, void* Object, int SizeOfObject);
bool loadObject(char* file, void* Object, int SizeOfObject);