#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
/*
checking the arguents returns a bool
*/
bool checkArgs(int paramCount){
	if (paramCount != 0 )  {
		
		return true;
	} else {
		std::cout << " HELP : \nYou must pass in 3 arguments to this program:\n\n The source file \n The Parent tag \n The Child tag\n";
		cout << "Check README.md for the syntax\n\n";
		// std::cout << "\nExample: $./wrapEachlineInHtml myfile.txt <div> <p>\n [escape sequences are needed on the tags]\n\n\n "; // [escape sequeunce needed]
		// std::cout << "\nExample: $./wrapEachLineInHtml myfile.txt <div> <p>\n\n";
		return false;
	}
}
 
 
int main(int argc, char** argv)

{
  if (!checkArgs(argc)) return 0;
  
  string filename = argv[1];
  string parentTag = argv[2];
  string childTag =  argv[3];
  string line;
  ifstream sourceFile (filename);
  int count = 0;

  if (sourceFile.is_open())
  {
    while ( getline (sourceFile,line) )
    {
     
         //cout << count++ << " : " << line.length() << "\n";
	std::string str = line;
	std::cout << "\n<div class=\"wordBox\">\n<p class=\"word\">" << str << "\n</p>\n</div>\n";
 }
 
	return 0; 
}}
