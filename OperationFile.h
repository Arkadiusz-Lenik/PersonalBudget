#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "File.h"
#include "Operation.h"

using namespace std;

class OperationFile : public File
{
    int lastOperationId;

public:
    OperationFile(string fileName) : File(fileName) {};

    int getLastOperationId();
    vector <Operation> loadOperationsFromFile(const int loggedUserId);
    bool addOperationToFile(const Operation &operation);


};

#endif
