#include "OperationFile.h"

int OperationFile::getLastOperationId()
{
    int lastOperationId = 0;

    xmlDoc.Load(getFileName());
    xmlDoc.FindElem();
    xmlDoc.IntoElem();

    while ( xmlDoc.FindElem("Operation") )
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
    bool fileExists = xmlDoc.Load(getFileName());

    if (fileExists)
    {
        xmlDoc.FindElem();
        xmlDoc.IntoElem();

        while (xmlDoc.FindElem("Operation"))
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

            if (operation.userId == loggedUserId)
            {
                operations.push_back(operation);
            }

            xmlDoc.OutOfElem();
        }

        return operations;
    }
    else
    {
        return operations;
    }
}

bool OperationFile::addOperationToFile(const Operation &operation)
{
    bool fileExists = xmlDoc.Load(getFileName());

    if (!fileExists)
    {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("Root");
    }

    xmlDoc.FindElem();
    xmlDoc.IntoElem();
    xmlDoc.AddElem("Operation");
    xmlDoc.IntoElem();
    xmlDoc.AddElem("OperationId", operation.operationId);
    xmlDoc.AddElem("UserId", operation.userId);
    xmlDoc.AddElem("Date", operation.date);
    xmlDoc.AddElem("Item", operation.item);
    xmlDoc.AddElem("Amount", operation.amount);

    return xmlDoc.Save(getFileName());
}
