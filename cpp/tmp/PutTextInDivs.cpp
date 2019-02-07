#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
 
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
 
int main()
{
  using namespace std;
  string line;
  ifstream sourceFile ("qsource.txt");
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
	std::cout << "<div class=\"wordBox\"><p class=\"word\">" << splittedStrings[i] << "</p></div>";
 }
 
	return 0; 
}}
