#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation operation;
    string operationType = "", dateAssociatedValue = "", temporaryAmount = "";

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

    do
    {
        cout << "Enter date of " << operationType <<" in format YYYY-MM-DD. Press 't' to use today's date. ";
        dateAssociatedValue = Utils::readLine();
    }
    while (!DateMethods::validateDate(dateAssociatedValue));

    operation.date = (dateAssociatedValue.length() == 1) ? DateMethods::getTodaysDate() : DateMethods::covertStringDateToInt(dateAssociatedValue);

    cout << "Enter name of " << operationType << ": ";
    operation.item = Utils::readLine();

    do
    {
        cout << "Enter amount of " << operationType << " with up to two decimal places: ";
        temporaryAmount = Utils::readLine();
    }
    while (!CashMethods::validateAmount(temporaryAmount));

    operation.amount = stod(CashMethods::changeCommaToDot(temporaryAmount));

    return operation;
}

void BudgetManager::addIncome()
{
    Operation operation;
    operation = addOperationDetails(INCOME);
    incomes.push_back(operation);

    if (incomeFile.addOperationToFile(operation))
    {
        cout << "Your income has been added to file." << endl;
    }

    system("pause");
}

void BudgetManager::addExpense()
{
    Operation operation;
    operation = addOperationDetails(EXPENSE);
    expenses.push_back(operation);

    if (expenseFile.addOperationToFile(operation))
    {
        cout << "Your expense has been added to file." << endl;
    }

    system("pause");
}



