// wordle.cpp
// backend of WORDLE Game (guess a word)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

string selected = "ASCII";
string result = "uuuuu";
vector <string> words;
bool isValid(string word);
int find_index(char letter);

// function main begins program execution
int main()
{
	srand(time(0));
	
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

	// choose random word 
	int i = rand() % 6223;
	selected = words[i];

	while (true) {
		// get input from user
		string input_word = "Null";
		cout << "[in-str] Your Guess: ";
		cin >> input_word;
		
		if (isValid(input_word)) {
			if (input_word == selected) {
				cout << "YOU WON!\n";
				return 1;
			} else {
				int index = -1;
				for (int i = 0; i < 5; i++) {
					index = find_index(input_word[i]);
					if (index == i)
						result[i] = 'g';
					else if (index > -1 && index != i && result[index] != 'g')
						result[i] = 'y';
					else
						result[i] = 'b';
				}
				cout << result << endl;
			}
		} else {
			cout << "Invalid\n";
		}
	}
	return 0;
} // end function main

int find_index(char letter)
{
	for (int i = 0; i < 5; i++)
		if (letter == selected[i])
			return i;
	return -1;
}

bool isValid(string word)
{
	if (find(words.begin(), words.end(), word) != words.end())
		return true;
	else
		return false;
}
