#include <fstream>
#include <string>
#include <iostream>

using namespace std;



int main(int argc, char *argv[]) 
{
 if (argv[1] == NULL)  
 {
   cout<<"\nHi, for this to work I need a path to a file: ./readFile sourFile ...\n";
   cout<<"\nYour are much smarter now that you know this. [TRAINEE LEVEL]\n";
   return 0;
 } 

 if (argv[2] == NULL)
 {
   cout<<"\nYeah, about that, you need to tell me what to search for \nthat would be awesome thanks..../readFile sourceFile.txt \"apples\"\n";
   cout<<"You're getting so smart , good for you! [NOVICE LEVEL]\n";
   return 0;
 } 

 if (argv[3] == NULL)
 {
   cout<<"\nand finally I just need to know what to replace the searched text with, you can just pop it in there right next to the search text \n";
   cout<<"\nWELL DONE ! Your training is now complete \n you have aquired sacred knowledge about how to operate the famous\n ReplaceaLineOfTextInaFileAndMagicallyMakeTheNewModifiedFileWithTheLineOfTextInside appear on your hard drive \n I know right...BLOWS YOUR MIND! [EXPERT LEVEL]";
   cout<<"\n Syntax: ./readfile originalFile.txt \"apples\" \"oranges\" >> theModifiedVersion.txt [GRAND MASTER LEVEL] \n";
   return 0;
 } 
  string filename = argv[1];
  string search = argv[2];
  string injection = argv[3];
  ifstream file(filename);
  string line;
  while(getline(file, line)) 
  {
   if(line == search )
      {
      cout<<injection<<endl<<search<<endl;	
      }
   else
   {
      cout<<line<<endl;
   }
   }
  return 0;
}
