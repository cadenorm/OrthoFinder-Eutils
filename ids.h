#ifndef IDS_H
#define IDS_H
#include <fstream>


class id{
public:
    id(std::string idNum);
    id* next;
    std::string idNum;
};
class idPair{  //object to represent an actual pair of ids
public:
    idPair(std::string id1, std::string id2);
    std::string idNum1;
    std::string idNum2;
    idPair* next;
};

class ids //object to store the group number as well as a list of all
{         // the pairs of ids in the group
public:
    ids(std::string groupNum);
    std::string groupNum;
    idPair* firstPair;
    idPair* lastPair;
    id* firstIso;
    id* lastIso;
    void makePairs();
    printPairs(std::ofstream &outfile);
};

#endif // IDS_H
