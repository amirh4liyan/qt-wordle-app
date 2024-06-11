// valids.cpp
// code for removing non valid words (those not A-Z or a-z) from words.txt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function isValid prototype
bool isValid(string word);
string toLower(string word);

// function main begins program execution
int main()
{
	ofstream myfile;
	myfile.open("valids.txt");
	string line;
	ifstream file("words.txt");
	if(file.is_open()) {
		while(getline(file, line)) {
			if (isValid(line)) {
				myfile << toLower(line) << "\n";
			}
		}
		file.close();
		myfile.close();
	} else {
		cout << " unable to open file ";
	}
	return 0;
} // end function main

// isValid implementation
// return false if word contain letter which is not A-Z or a-z, otherwise, return true
bool isValid(string word)
{
	for (int i = 0; i < 5; i++) {
		if ((word[i] < 65) || (word[i] > 90 && word[i] < 97) || (word[i] > 122)) {
			return false;
		}
	}
	return true;
} // end isValid code block

string toLower(string word)
{
	for (int i = 0; i < 5; i++) {
		if (65 <= word[i] && word[i] <= 90) {
			word[i] += 32;
		}
	}
	return word;
}
