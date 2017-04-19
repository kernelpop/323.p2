#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> txt_to_strings(string txt_file) {	//	Convert an input txt file to a string with newline characters
	vector<string> strings;		// This is what our function will return
	ifstream reader;
	reader.open(txt_file);
	while (!reader.eof()) {
		string new_string;
		getline(reader, new_string);
		strings.push_back(new_string);
	}
	return strings;
}