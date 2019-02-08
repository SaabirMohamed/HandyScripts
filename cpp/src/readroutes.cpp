#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main(int argc, char** argv){
string targeta = argv[4];
string targetb = argv[5];
string ngDefRouteFile = argv[1];
string ngModFile = argv[2];

ifstream file (argv[1]); // the angular default app routing file
ifstream file2 (argv[2]); // the angular file to output (a temp file)
if (!file) {
cout << "unable to open file";
 return 0;
}
// some declarations params and strings needed

string searchA = "  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},"; //leading space is important neater output
string replaceA = "  {path: '" + targeta + "', loadChildren: './modules/" + targeta+  "/" + targeta + ".module#"+ targetb + "Module'}\n  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},\n";
string searchB = "import { Routes, RouterModule } from '@angular/router';";
string replaceB = "import { Routes, RouterModule } from '@angular/router';\nimport { " + targetb +"Component } from './"+ targeta + ".component';\n";
string searchC = "const routes: Routes = [";
string replaceC = "const routes: Routes = [\n{ path: '" + targeta + "', component: "+ targetb + "Component}\n];";

// LOOPING THROUGH THE DEFAULT app-routing.module.ts (file path passed in by user argv[2]) 
std::ofstream log(argv[2], std::ios_base::app | std::ios_base::out);
string temp;
while (getline (file, temp))
{       
        if(temp == searchA) {

        log << replaceA;
        
        }  else 
        {
            log << temp << "\n";
        } 
}
  
// LOOPING THROUGH THE CREATED modules default routing file and replacing with the new modules routes
std::ofstream log(argv[3], std::ios_base::app | std::ios_base::out);
string temp2;
while (getline(file2, temp2)) 
{
        if (temp2 == searchB) { // the first injection case
            log << replaceB;
        }
        else if(temp2 == searchC) { // the second injection case
        log << replaceC;
        }
        else {
        log << temp2 << "\n";
        }
}

}