#include "ids.h"
#include <fstream>

id::id(std::string idNum){
    this->idNum = idNum;
    this->next = 0;
}
idPair::idPair(std::string id1,std::string id2){
    this->idNum1 = id1;
    this->idNum2 = id2;
    this->next = 0;
}
ids::ids(std::string groupNum)
{
    this->firstPair = 0;
    this->lastPair = 0;
    this->firstIso = 0;
    this->lastIso = 0;
    this->groupNum = groupNum;
}
void ids::addIsoIds(std::string id){
    id* p = new id(id);
    if(this->firstIso == 0){
        this->firstIso = p;
        this->lastIso = p;
    }else{
        this->lastIso->next = p;
        this->lastIso = p;
    }
}
