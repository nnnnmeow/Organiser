#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;
//Structure
struct Case
{
	string CaseName;
	string Priorities;
	string Description;
	string Date;
	string Deadline;
};
//clear file
void clear(string name)
{
	ofstream file(name);
	file << "";
}

//Get cases from file
vector<Case> GetCase(string name)
{
	vector<Case> Cases; Case cases;
	ifstream file(name);
	string br;
	while (!file.eof())
	{
		file >> cases.CaseName;
		file >> cases.Priorities;
		file >> cases.Description;
		file >> cases.Date;
		file >> cases.Deadline;
		Cases.push_back(cases);
	}
	file.close();
	Cases.pop_back();
	return Cases;
}
//Write cases to file
void WriteCase(vector<Case> cases, string filename)
{ 
	vector<Case> casing;
	casing = GetCase(filename);
	clear("Path.txt");
	for (size_t i = 0; i < cases.size(); i++)
	{
		casing.push_back(cases[i]);
	}
	ofstream out(filename);
	for (int i = 0; i < casing.size(); i++)
	{
		out << casing[i].CaseName << endl;
		out << casing[i].Priorities << endl;
		out << casing[i].Description << endl;
		out << casing[i].Date << endl;
		out << casing[i].Deadline << endl;
	}
	out.close();
}

//Rewrite case
void RewriteCase(vector<Case> cases, string filename)
{
	ofstream out(filename);
	for (int i = 0; i < cases.size(); i++)
	{
		out << cases[i].CaseName << endl;
		out << cases[i].Priorities << endl;
		out << cases[i].Description << endl;
		out << cases[i].Date << endl;
		out << cases[i].Deadline << endl;
	}
	out.close();
}