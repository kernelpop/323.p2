#include "Tokenizer.cpp"
#include "token.h"
#include "Parser.cpp"
#include "resources.h"
#include "txt_to_strings.cpp"
#include "token_printer.cpp"


using namespace std;


//	========  Global Variables  ========
string _Language = "A3";
string Test_File = "test_X.txt";
vector<Token> _Tokens;
vector<string> _Strings;


//	========  Function Prototypes  ========
void runParser(vector<Token>);


int main() {
	
	int x = 0;

	while (true) {
		
		cout << "Please input a test number (1-6) or any negative number to exit: ";
		
		cin >> x;
		
		if (x < 0) {	
			break;
		}

		Test_File = "test_" + to_string(x) + ".txt";
		

		if (!cin.fail()) {	

			ifstream f(Test_File.c_str());                       
			
			if (f.good()) {
				
				cout << "========  Start Test - " << Test_File << " ========" << endl;

				_Strings = txt_to_strings(Test_File);

				_Tokens = tokenize(_Strings);

				token_printer(_Language, _Tokens);

				runParser(_Tokens);

				_Strings.clear();

				_Tokens.clear();

				cout << "========  End Test  ========" << endl;
				
			}                                                    
			
			else {
				
				cout << "No such file found in current directory!" << endl;
			
			}
		
		}
		
		else {
			
			cout << "Bad input detected." << endl;
			
			cin.clear();
			
			cin.ignore(INT_MAX, '\n');
		
		}
	
	}
	
	return 0;

}