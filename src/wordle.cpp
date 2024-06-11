// wordle.cpp
// backend of WORDLE Game (guess a word)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> words;
bool isValid(string word);

// function main begins program execution
int main()
{
	string line = "";
	ifstream file("valids.txt");
	if(file.is_open()) {
		while(getline(file, line)) {
			words.push_back(line);
		}
		file.close();
	} else {
		cout << "[out-err]: Unable to open file ";
	}

	// get input from user
	string input_word = "Null";
	cout << "[in-str] Your Guess: ";
	cin >> input_word;
	
	if (isValid(input_word)) {
		cout << "Valid\n";
	} else {
		cout << "Invalid\n";
	}

	return 0;
} // end function main

bool isValid(string word)
{
	if (find(words.begin(), words.end(), word) != words.end())
		return true;
	else
		return false;
}
