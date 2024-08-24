#include "OperationFile.h"

int OperationFile::getLastOperationId()
{
    int lastOperationId = 0;

    xmlDoc.Load(getFileName());
    xmlDoc.FindElem();
    xmlDoc.IntoElem();

    while ( xmlDoc.FindElem("Income") )
    {
        xmlDoc.IntoElem();
        xmlDoc.FindElem( "OperationId" );
        lastOperationId = stoi(xmlDoc.GetData());
        xmlDoc.OutOfElem();
    }

    return lastOperationId;
}

vector <Operation> OperationFile::loadOperationsFromFile(const int loggedUserId)
{
    vector <Operation> operations;
    Operation operation;
    xmlDoc.Load(getFileName());
    xmlDoc.FindElem();
    xmlDoc.IntoElem();

    while (xmlDoc.FindElem("Income"))
    {
        xmlDoc.FindElem( "UserId" );

        if (stoi(xmlDoc.GetChildData()) == loggedUserId)
        {
            xmlDoc.IntoElem();
            xmlDoc.FindElem( "OperationId" );
            operation.operationId = stoi(xmlDoc.GetData());
            xmlDoc.FindElem( "UserId" );
            operation.userId = stoi(xmlDoc.GetData());
            xmlDoc.FindElem( "Date" );
            operation.date = stoi(xmlDoc.GetData());
            xmlDoc.FindElem( "Item" );
            operation.item = xmlDoc.GetData();
            xmlDoc.FindElem( "Amount" );
            operation.amount = stod(xmlDoc.GetData());
        }
        operations.push_back(operation);
        xmlDoc.OutOfElem();
    }

    return operations;
}
