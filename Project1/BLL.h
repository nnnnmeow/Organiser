#pragma once
#include"DAL.h"
//------------------------------------Show cases------------------------------------//
//show all cases
void ShowCases(vector<Case> cases)
{
	if (cases.size() <= 0) return;
	cout << "-------------------Cases-------------------" << endl;
	for (int i = 0; i < cases.size(); i++)
	{
		cout << "----Case #" << i << "----" << endl;
		cout << "Name: " << cases[i].CaseName << endl;
		cout << "Priority: " << cases[i].Priorities << endl;
		cout << "Description: " << cases[i].Description << endl;
		cout << "Date: " << cases[i].Date << endl;
		cout << "Deadline: " << cases[i].Deadline << endl;
		cout << "---------------" << endl;
	}
	cout << "-------------------------------------------" << endl;
}
//show certain case 
void ShowCase(vector<Case> cases, int casenum)
{
	bool found = false;
	if (cases.size() <= 0) return;
	for (int i = 0; i < cases.size(); i++)
	{
		if (i == casenum)
		{
			found = true;
			cout << "----Case #" << i << "----" << endl;
			cout << "Name: " << cases[i].CaseName << endl;
			cout << "Priority: " << cases[i].Priorities << endl;
			cout << "Description: " << cases[i].Description << endl;
			cout << "Date: " << cases[i].Date << endl;
			cout << "Deadline: " << cases[i].Deadline << endl;
			cout << "---------------" << endl;
		}

	}
	if (found == false)
	{
		cout << "Nothing found!" << endl;
		return;
	}
}
//--------------------------------------------------------------------------------//

//------------------------------------Remove cases------------------------------------//
//remove all cases
void RemoveCases(vector<Case> cases)
{
	if (cases.size() <= 0) return;
	cout << "Clean!" << endl;
	clear("Path.txt");
}
//----------------------------------------------------------------------------------//

//------------------------------------Find cases------------------------------------//
//show cases by name
void FindName(vector<Case> cases, string name)
{
	if (cases.size() <= 0) return;
	bool found = false;
	cout << "-------------------Cases-------------------" << endl;
	for (int i = 0; i < cases.size(); i++)
	{
		if (cases[i].CaseName == name)
		{
			found = true;
			cout << "----Case #" << i << "----" << endl;
			cout << "Name: " << cases[i].CaseName << endl;
			cout << "Priority: " << cases[i].Priorities << endl;
			cout << "Description: " << cases[i].Description << endl;
			cout << "Date: " << cases[i].Date << endl;
			cout << "Deadline: " << cases[i].Deadline << endl;
			cout << "---------------" << endl;
		}
	}
	if (found == false)
	{
		cout << "Nothing found!" << endl;
		cout << "-------------------------------------------" << endl;
		return;
	}

	cout << "-------------------------------------------" << endl;
}
//show cases by priority
void FindPriority(vector<Case> cases, string priority)
{
	if (cases.size() <= 0) return;
	bool found = false;
	cout << "-------------------Cases-------------------" << endl;
	for (int i = 0; i < cases.size(); i++)
	{
		if (cases[i].Priorities == priority)
		{
			found = true;
			cout << "----Case #" << i << "----" << endl;
			cout << "Name: " << cases[i].CaseName << endl;
			cout << "Priority: " << cases[i].Priorities << endl;
			cout << "Description: " << cases[i].Description << endl;
			cout << "Date: " << cases[i].Date << endl;
			cout << "Deadline: " << cases[i].Deadline << endl;
			cout << "---------------" << endl;
		}
	}
	if (found == false)
	{
		cout << "Nothing found!" << endl;
		cout << "-------------------------------------------" << endl;
		return;
	}
	cout << "-------------------------------------------" << endl;
}
//--------------------------------------------------------------------------------//

//Change case
void ChangeCase(vector<Case> cases, int casenum)
{
	int choice = 0;
	bool found = false;
	if (cases.size() <= 0) return;
	for (int i = 0; i < cases.size(); i++)
	{
		if (i == casenum)
		{
			found = true;
			cout << "Enter name: ";
			cin >> cases[i].CaseName;
			cout << "Enter priority:" << endl << "1. High" << endl << "2. Medium" << endl << "3. Low" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cases[i].Priorities = "High";
				break;
			case 2:
				cases[i].Priorities = "Medium";
				break;
			case 3:
				cases[i].Priorities = "Low";
				break;
			default:
				break;
			}
			cout << "Enter description: ";
			cin >> cases[i].Description;
			cout << "Enter date: ";
			cin >> cases[i].Date;
			cout << "Enter deadline: ";
			cin >> cases[i].Deadline;
		}
	}
	if (found == false)
	{
		cout << "Nothing found!" << endl;
		return;
	}
	RewriteCase(cases, "Path.txt");
}

//enter case
Case EnterCase()
{
	Case cases;
	int choice = 0;
	cout << "Enter name: ";
	cin >> cases.CaseName;
	cout << "Enter priority:" << endl << "1. High" << endl << "2. Medium" << endl << "3. Low" << endl;
	cin >> choice;
	switch (choice)
	{
		case 1:
			cases.Priorities = "High";
			break;
		case 2:
			cases.Priorities = "Medium";
			break;
		case 3:
			cases.Priorities = "Low";
			break;
		default:
			break;
	}
	cout << "Enter description: ";
	cin >> cases.Description;
	cout << "Enter date: ";
	cin >> cases.Date;
	cout << "Enter deadline: ";
	cin >> cases.Deadline;
	return cases;
}
