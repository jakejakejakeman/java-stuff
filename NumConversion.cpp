#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Color.h"
using namespace std;

void ReadFile(const char *filename, vector<Color> &outVector);
void SortColors(vector<Color> &colors);
void PrintColors(const vector<Color> &colors);
bool NameSort(const Color &left, const Color &right);

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	vector<Color> colors;
	// Load the selected files
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}
	}

   // Sort and print the loaded data
	SortColors(colors);
	PrintColors(colors);

	return 0;
}

void ReadFile(const char *filename, vector<Color> &outVector)
{
	// TODO: Load the file and store the resulting colors in outVector.
	fstream file(filename, ios_base::in);
	while (!file.eof())
	{
	   int meep;
	   string meeps;
   	Color c;
   	file>>meeps;
   	file>>meep;
   	c.SetName(meeps.c_str());
   	c.SetValue(meep); // This should also convert the values, internally
   	outVector.push_back(c);
	}
	file.close();
}

void SortColors(vector<Color> &colors)
{
   sort(colors.begin(),colors.end(),NameSort);
}

void PrintColors(const vector<Color> &colors)
{
	for (unsigned int i = 0; i < colors.size(); i++)
	{
		cout << colors[i].GetName();
		for (unsigned int j = 0; j < 3 - colors[i].GetName().size() / 8; j++)
			cout << "\t";
		cout << colors[i].GetHexValue() << '\t' << (int)colors[i].GetR() << "," << (int)colors[i].GetG() << "," << (int)colors[i].GetB() << endl;
	}
	cout << "Number of colors: " << colors.size() << endl;
}
bool NameSort(const Color &left, const Color &right)
{
   return (left.names<right.names);
}