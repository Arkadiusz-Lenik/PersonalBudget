#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include "Utils.h"
#include "OperationFile.h"
#include "Operation.h"
#include "DateMethods.h"
#include "Type.h"
#include "CashMethods.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_USER_ID;

    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const Type &type);

public:
    BudgetManager(int loggedUserId, string incomeFileName, string expenseFileName) : LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName)
    {
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
    }

    void addIncome();
    void addExpense();

};

#endif
