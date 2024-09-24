#pragma once
#include"BLL.h"
void WriteUi()
{
	cout << endl;
	cout << "0. Find by name" << endl;
	cout << "1. Find by priority" << endl;
	cout << "2. Show certain case" << endl;
	cout << "3. Show all cases" << endl;
	cout << "4. Change case" << endl;
	cout << "5. Write cases" << endl;
	cout << "6. Clear cases" << endl;
	cout << "7. Exit" << endl;
	cout << "Enter command(0-7): ";
}

void Start(string cases)
{
	bool cycle = true;
	int command = 0, amount = 0, choice = 0;
	string name, priority; int casenum;
	vector<Case> casesnames;
	while (cycle)
	{
		WriteUi();
		cin >> command;
		switch (command)
		{
		case 0:
			cout << "Enter case name: "; cin >> name;
			FindName(GetCase(cases), name);
			break;
		case 1:
			cout << "Enter priority:" << endl << "1. High" << endl << "2. Medium" << endl << "3. Low" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				priority = "High";
				break;
			case 2:
				priority = "Medium";
				break;
			case 3:
				priority = "Low";
				break;
			default:
				break;
			}
			FindPriority(GetCase(cases), priority);
			break;
		case 2:
			cout << "Enter case number: "; cin >> casenum;
			ShowCase(GetCase(cases), casenum);
			break;
		case 3:
			ShowCases(GetCase(cases));
			break;
		case 4:
			cout << "Enter case number: "; cin >> casenum;
			ChangeCase(GetCase(cases), casenum);
			break;
		case 5:
			cout << "Case amount: "; cin >> amount;

			for (int i = 0; i < amount; i++)
			{
				casesnames.push_back(EnterCase());
			}
			if (casesnames.size() > 0)
			{
				WriteCase(casesnames, cases);
			}
			break;
		case 6:
			RemoveCases(GetCase(cases));
			break;
		case 7:
			cycle = false;
			break;
		default:
			cycle = false;
			break;
		}
	}
}