// wordle.cpp
// backend of WORDLE Game (guess a word)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> words;

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
	return 0;
} // end function main
