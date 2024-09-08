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
        cout << "Enter date of " << operationType <<" in format YYYY-MM-DD. Press 't' to use today's date: ";
        dateAssociatedValue = Utils::readLine();
    }
    while (!DateMethods::validateDate(dateAssociatedValue));

    operation.date = (dateAssociatedValue.length() == 1) ? DateMethods::getTodaysDate() : DateMethods::convertStringDateToInt(dateAssociatedValue);

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
        incomeFile.setLastOperationId(incomeFile.getLastOperationId() + 1);
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
        expenseFile.setLastOperationId(expenseFile.getLastOperationId() + 1);
    }

    system("pause");
}

void BudgetManager::showCurrentMonthBalance()
{
    showBalance(DateMethods::getCurrentMonthStartDate(), DateMethods::getCurrentMonthEndDate());
}

void BudgetManager::showPreviousMonthBalance()
{
    showBalance(DateMethods::getPreviousMonthStartDate(), DateMethods::getPreviousMonthEndDate());
}

void BudgetManager::showCustomPeriodBalance()
{
    string tempUserStartDate = "", tempUserEndDate = "";
    int userStartDate = 0, userEndDate = 0;

    do
    {
        cout << "Enter starting date of balance in format YYYY-MM-DD. Press 't' to use today's date: ";
        tempUserStartDate = Utils::readLine();
    }
    while (!DateMethods::validateDate(tempUserStartDate));

    userStartDate = (tempUserStartDate.length() == 1) ? DateMethods::getTodaysDate() : DateMethods::convertStringDateToInt(tempUserStartDate);

    do
    {
        cout << "Enter ending date of balance in format YYYY-MM-DD. Press 't' to use today's date: ";
        tempUserEndDate = Utils::readLine();
    }
    while (!DateMethods::validateDate(tempUserEndDate));

    userEndDate = (tempUserEndDate.length() == 1) ? DateMethods::getTodaysDate() : DateMethods::convertStringDateToInt(tempUserEndDate);

    showBalance(userStartDate, userEndDate);
}

bool BudgetManager::sortByDate(const Operation &a, const Operation &b)
{
    return a.date < b.date;
}

void BudgetManager::showBalance(int startDate, int endDate)
{
    Menus::showSubtitle("INCOMES");
    int operationNumber = 1;
    double incomesSum = 0, expensesSum = 0;

    sort(incomes.begin(), incomes.end(), sortByDate);

    for (size_t i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].date >= startDate && incomes[i].date <= endDate)
        {
            cout << operationNumber << ". Date: " << DateMethods::convertDateToStringWithDashes(incomes[i].date) << ", Name: " << incomes[i].item << ", Amount: " << incomes[i].amount << endl;
            incomesSum += incomes[i].amount;
            operationNumber++;
        }
    }

    if (incomesSum == 0)
    {
        cout << "There are no data concerning incomes" << endl << endl;
    }

    Menus::showSubtitle("EXPENSES");
    operationNumber = 1;

    sort(expenses.begin(), expenses.end(), sortByDate);

    for (size_t i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].date >= startDate && expenses[i].date <= endDate)
        {
            cout << operationNumber << ". Date: " << DateMethods::convertDateToStringWithDashes(expenses[i].date) << ", Name: " << expenses[i].item << ", Amount: " << expenses[i].amount << endl;
            expensesSum += expenses[i].amount;
            operationNumber++;
        }
    }

    if (expensesSum == 0)
    {
        cout << "There are no data concerning expenses" << endl;
    }

    Menus::showSubtitle("SUMMARY");
    cout << "Incomes sum: " << fixed << setprecision(2) << incomesSum << endl;
    cout << "Expenses sum: " << expensesSum << endl;
    cout << "Overall balance: " <<  incomesSum - expensesSum << endl << endl;

    system("pause");
}






