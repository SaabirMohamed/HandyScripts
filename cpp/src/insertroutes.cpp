#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    string module = argv[1];
    string moduleCap = argv[2];
    string strReplace = "{path: '**', redirectTo: '', loadChildren: './modules/pnf/pnf.module#PnfModule'},";
    string strNew = "{path: '" + module + "', redirectTo: '', loadChildren: './modules/" + module + "/" + module + ".module#" + moduleCap + "Module'},\n" + strReplace;
    ifstream filein("app-routing.module.ts"); //File to read from
    ofstream fileout("mod-app-routing.module.ts"); //Temporary file
    if(!filein || !fileout)
    {
        cout << "Error opening files!" << endl;
        return 1;
    }

    string strTemp;
    //bool found = false;
    while(filein >> strTemp)
    {
        if(strTemp == strReplace){
            strTemp = strNew;
            //found = true;
        }
        // strTemp += " ";
        fileout << strTemp;
        //if(found) break;
    }
    return 0;
}