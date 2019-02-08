#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main(int argc, char** argv){

ifstream file (argv[1]); // the angular default app routing file
ifstream outFile (argv[2]); // the angular file to output (a temp file)
if (!file) {
cout << "unable to open file";
// return 0;
}
std::ofstream log(argv[2], std::ios_base::app | std::ios_base::out);
string temp;
string targeta = argv[4];
string targetb = argv[5];

// LOOPING THROUGH THE DEFAULT app-routing.module.ts file and replacing with the new modules routes
while (getline (file, temp))
{       
        if(temp == "  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},") {

        log << "  {path: '" + targeta + "', loadChildren: './modules/" + targeta+  "/" + targeta + ".module#"+ targetb + "Module'}\n  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},\n";
        
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
        if (temp2 == "import { Routes, RouterModule } from '@angular/router';") { // the first injection case
            log << "import { Routes, RouterModule } from '@angular/router';\nimport { " + targetb +"Component } from './"+ targeta + ".component';\n";
        }
        else if(temp2 == "const routes: Routes = [") { // the second injection case
        log << "const routes: Routes = [\n{ path: '" + targeta + "', component: "+ targetb + "Component}\n];";
        }
        else {
        log << temp2 << "\n";
        }
}

}