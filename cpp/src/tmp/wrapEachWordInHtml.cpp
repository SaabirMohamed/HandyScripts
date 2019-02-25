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
	if ((paramCount == 0) && (paramCount < 3))  {
		
		return true;
	} else {
		std::cout << " HELP : \nYou must pass in 3 arguments to this program:\n\n The source file \n The Parent tag \n The Child tag\n";
		cout << "Check README.md for the syntax\n\n";
		// std::cout << "\nExample: $./wrapEachlineInHtml myfile.txt <div> <p>\n [escape sequences are needed on the tags]\n\n\n "; // [escape sequeunce needed]
		// std::cout << "\nExample: $./wrapEachLineInHtml myfile.txt <div> <p>\n\n";
		return false;
	}
}
 
/*
std::string split implementation by using delimeter as a character.
*/
std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
	std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
    }
	return splittedStrings;
}
 
/*
std::string split implementation by using delimeter as an another string
*/
std::vector<std::string> split(std::string stringToBeSplitted, std::string delimeter)
{
	std::vector<std::string> splittedString;
	int startIndex = 0;
	int  endIndex = 0;
	while( (endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size() )
	{
 
		std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
		splittedString.push_back(val);
		startIndex = endIndex + delimeter.size();
 
	}
	if(startIndex < stringToBeSplitted.size())
	{
		std::string val = stringToBeSplitted.substr(startIndex);
		splittedString.push_back(val);
	}
	return splittedString;
 
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
 
	// Spliting the string by ''
	std::vector<std::string> splittedStrings = split(str, ' ');
	for(int i = 0; i < splittedStrings.size() ; i++)
	std::cout << "\n<div class=\"wordBox\">\n<p class=\"word\">" << splittedStrings[i] << "\n</p>\n</div>\n";
 }
 
	return 0; 
}}
