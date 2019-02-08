#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main(int argc, char** argv){

ifstream file (argv[1]); //file just has some sentences
ifstream outFile (argv[2]); // modified
if (!file) {
cout << "unable to open file";
// return false;
}
std::ofstream log(argv[2], std::ios_base::app | std::ios_base::out);
string temp;
string targeta = argv[4];
string targetb = argv[5];
while (getline (file, temp))
{
  //this is the string  I look for and append 
  if(temp == "  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},") {

      log << "  {path: '" + targeta + "', loadChildren: './modules/" + targeta+  "/" + targeta + ".module#"+ targetb + "Module'}\n  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},\n";
      
  }  else {
        log << temp << "\n";
  }
  
  }
  
    std::ofstream log(argv[3], std::ios_base::app | std::ios_base::out);
    string temp2;
    while (getline(file2, temp2)) {
            if(temp2 == "const routes: Routes = [") {
            log << "const routes: Routes = [\n{ path: '" + targeta + "', component: "+ targetb + "Component}\n]";
            }  else {
            log << temp << "\n";
  }
    }
}