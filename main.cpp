#include <iostream>
#include <fstream>
#include <string>
#include "OrthOut.h"
#include "ids.h"
using namespace std;

int main()
{
    ifstream orthout;
    orthout.open("Orthogroups.txt", ios::in);
    OrthOut* oStruct = new OrthOut();
    if(orthout.is_open()){
        string l;
        while(getline(orthout,l)){
            oStruct->addLine(l);
        }
        orthout.close();
    }

    line* j = oStruct->firstLine;
    while(j->next != 0){
        cout<<j->curr<<endl;
    }

    orthout.close();
    return 0;
}
