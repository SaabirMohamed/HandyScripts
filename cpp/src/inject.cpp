#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<iostream>

using namespace std;

// how: $./inject about About app-routing.module.ts  
int main(int argc, char **argv)
{
    string targeta = argv[1]; // The name of the module in lower case eg: about
    string targetb = argv[2]; // The name of the module Capitalised eg: About
    string angularFile = argv[3]; // name of the angular routing file to inject to;
    ifstream file(angularFile); 
    int fileLineCount = atoi(argv[4]);
    

    if (!file)
    {
        return 0;
    }

    // some declarations params and strings needed
    if (angularFile == "app-routing.module.ts")
    cout << angularFile;
    {
        string searchA = "  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},"; //leading space is important neater output
        string replaceA = "  {path: '" + targeta + "', loadChildren: './modules/" + targeta + "/" + targeta + ".module#" + targetb + "Module'}\n  {path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},\n";
        std::ofstream log(angularFile, std::ios_base::app | std::ios_base::out);
        string temp;
        // ofstream newFile;
        // newFile.open ("appModuleOut");

                    while (getline(file, temp))
                    log << "\n";
                    {
                        if (temp == searchA) // The first injection case to inset the lazy loaded route
                        {
                           // log << searchA;
                           
                                                        
                             log << replaceA;
                            
                        }
                        else
                        {
                             log << temp;
                            
                            
                            
                        }

                    }
                    
                    
                    return 0;
    }

    if (angularFile == targeta + "-routing.module.ts")
    {

        string searchB = "import { Routes, RouterModule } from '@angular/router';";
        string replaceB = searchB + "\nimport { " + targetb + "Component } from './" + targeta + ".component';\n";
        string searchC = "const routes: Routes = [";
        string replaceC = searchC + "\n{ path: '" + targeta + "', component: " + targetb + "Component},\n];";
        std::ofstream log(angularFile, std::ios_base::app | std::ios_base::out);
        string temp;
                    while (getline(file, temp))
                    {
                            if (temp == searchB) { // the first injection case for the import statement at the top
                                log << replaceB;
                            }
                            else if(temp == searchC) { // the second injection case for the route to its component
                            log << replaceC;
                            }
                            else {
                            log << temp << "\n";
                            }
                    }
                    system("tail -n 16 app-routing.module.ts >> test2.txt");
                    return 0;
    }

    
}