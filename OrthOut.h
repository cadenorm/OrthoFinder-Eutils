#ifndef ORTHOUT_H
#define ORTHOUT_H
#include <string>
#include "ids.h"

using namespace std;

class line{
public:

    line(string l);
    string curr;
    line* prev;
    line* next;
};

class OrthOut
{
public:

    line* firstLine;
    line* lastLine;
    void addLine(string l);
    void isoIds(ids* isos); //main function to pair and create the pair files
    OrthOut();
};

#endif // ORTHOUT_H
