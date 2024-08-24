#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation operation;
    string operationType = "";

    switch(type)
    {
        case INCOME:
            operation.operationId = incomeFile.getLastOperationId() + 1;
            operationType = "income";
            break;
        case EXPENSE:
            operation.operationId = expenseFile.getLastOperationId() + 1;
            operationType = "expense";
            break;
    }

    operation.userId = LOGGED_USER_ID;

    cout << "Date of " << operationType << ": ";
    operation.date = stoi(DateMethods::getCurrentDate());

    cout << "Enter type of " << operationType << ": ";
    operation.item = Utils::readLine();

    cout << "Enter amount of : " << operationType << ": ";
    operation.amount = Utils::getDecimalNumber();

    return operation;
}



