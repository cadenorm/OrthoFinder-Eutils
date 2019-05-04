#include "OrthOut.h"
#include <string>
#include <algorithm>
#include "ids.h"

using namespace std;

line::line(string l){
    this->curr = l;
    this->next = 0;
}
OrthOut::OrthOut()
{
    this->firstLine = 0;
    this->lastLine = 0;

}


void OrthOut::addLine(string l){
    line* newLine = new line(l);
    if(this->firstLine == 0){
        this->firstLine = newLine;
        this->lastLine = newLine;
    }
    else{
        this->lastLine->next = newLine;
        this->lastLine = newLine;
    }
}

void OrthOut::isoIds(ids* isos){
    line* i = this->firstLine;
    while(i != 0){
        string l = i->curr;
        string groupNum = l.substr(0,9);
        ids* thisID = new ids(groupNum);
        //int n = std::count(l.begin(),l.end(),'|');
        //int numofIDs = n/4;
        int j = 11;
        while(j != l.size()){
            if(l.at(j) == ' '){
                j++;
                continue;
            }
            else if(l.at(j)=='g'){
                int k = j;
                j++;
                if(l.at(j)=='i'){
                    j++;
                    if(l.at(j)=='|'){
                        j++;
                        while(l.at(j)!='|'){
                            j++;
                        }
                        std::string idStr = l.substr(k,j);
                        j++;
                        isos->addIsoIds(idStr);
                    }else{
                        j++;
                        continue;
                    }
                }else if(l.at(j)=='b'){
                    j++;
                    if(l.at(j)=='|'){
                        j++;
                        while(l.at(j)!='|'){
                            j++;
                        }
                        std::string idStr = l.substr(k,j);
                        j++;
                        isos->addIsoIds(idStr);
                    }
                }else{
                    j++;
                    continue;
                }
            }else if(l.at(j) == 'e'){
                int k = j;
                j++;
                if(l.at(j)=='m'){
                    j++;
                    if(l.at(j)=='b'){
                        j++;
                        if(l.at(j)=='|'){
                            j++;
                            while(l.at(j)!='|'){
                                j++;
                            }
                            std::string idStr = l.substr(k,j);
                            isos->addIsoIds(idStr);
                            j++;
                        }else{
                            j++;
                            continue;
                        }
                    }else{
                        j++;
                        continue;
                    }
                }else{
                    j++;
                    continue;
                }
            }else{
                j++;
                continue;
            }


        }
    }
}
