#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

void ProcessFile(string path) {
	ifstream ifs;
	ifs.open(path);
	std::string text((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();
	int pos;
	pos = text.find("/MD");
	while (pos != -1) {
		text.replace(pos, 3, "/MT");
		pos = text.find("/MD");
	}
	ofstream ofs;
	ofs.open(path, ios::out);
	ofs << text;
	ofs.flush();
	ofs.close();
}