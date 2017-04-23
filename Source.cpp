#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


int main(int argc, char * argv[])
{
	string STRING;
	vector<string> friendNames;
	vector<string> friendNames2;
	smatch name;
	ifstream infile;
	regex pattern{R"(aria-label=\"Add ([\s\S]+) as a friend\")"};


	//Parse first html file for friends
	infile.open("Jonathan Arauco.html");
	while (!infile.eof())
	{

		getline(infile, STRING);

		//Find names of friends
		if (regex_search(STRING, name, pattern))
		{
			friendNames.push_back(name[1]);
		}
	}
	infile.close();


	//Parse second html file for friends
	infile.open("Jonathan Arauco 4_16_17.html");
	while (!infile.eof())
	{
		getline(infile, STRING);

		//Find names of friends
		if (regex_search(STRING, name, pattern))
		{
			friendNames2.push_back(name[1]);
		}

	}
	infile.close();

	//Sort both vectors of friends.
	sort(friendNames2.begin(), friendNames2.end());
	sort(friendNames.begin(), friendNames.end());

	cout << "Fiends1: " << setw(18) << left << friendNames.size();
	cout << "  |  ";
	cout << "Friends2: " << setw(18) << left << friendNames2.size() << endl;


	//Print two column output of all friends in both lists
	for (int i = 0; i < friendNames2.size(); i++)
	{
		if (i < friendNames.size())
		{
			cout << setw(27) << left << friendNames.at(i);
			cout << "  |  ";
			cout << setw(27) << left << friendNames2.at(i) << endl;
		}
		else
		{
			cout << setw(27) << left << "" << "  |  " << friendNames2.at(i) << endl;
		}
	}
	cout << endl << endl << endl;


	bool found = false;
	int iter = 0;

	//print all names in first that are no loner in second
	cout << "These people unfriended you: " << endl;
	for (int i = 0; i < friendNames.size(); i++)
	{
		found = false;

		for (int j = 0; j < friendNames2.size(); j++)
		{
			if (friendNames.at(i) == friendNames2.at(j))
			{
				found = true;
			}
		}
		if (found == false)
		{
			iter++;
			cout << iter << ": " << friendNames.at(i) << endl;
		}
	}

	//reverse process to find  people in second list who are not in first
	iter = 0;
	cout << endl << endl << "These are new friends: " << endl;
	for (int i = 0; i < friendNames2.size(); i++)
	{
		found = false;

		for (int j = 0; j < friendNames.size(); j++)
		{
			if (friendNames2.at(i) == friendNames.at(j))
			{
				found = true;
			}
		}
		if (found == false)
		{
			iter++;
			cout << iter << ": " << friendNames2.at(i) << endl;
		}
	}


	system("pause");
	return 0;
}