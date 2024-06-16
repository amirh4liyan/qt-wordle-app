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


bool isValid(string word);
int find_index(char letter);
void read_words_from_file(string file_name);
void word_status(string word);

string selected = "ASCII";
string result = "uuuuu";
vector <string> words;

// function main begins program execution
int main()
{
	// reading data from txt file and store them into words vector
	read_words_from_file("valids.txt");

	// choose random word 
	srand(time(0));
	int index = rand() % 6223;
	selected = words[index];

	
	while (true) {
		// get input from user
		string input_word = "Null";
		cout << "[in-str] Your Guess: ";
		cin >> input_word;
		
		if (isValid(input_word)) {
			if (input_word == selected) {
				cout << "YOU WON!\n";
				return 0;
			} else {
				// determine word status
				word_status(input_word);
				cout << result << endl;
			}
		} else {
			cout << "Invalid\n";
		}
	}
	cout << "[out-str]: The word was: " << selected << endl;
	return 0;
} // end function main

int find_index(char letter)
{
	for (int i = 0; i < 5; i++)
		if (letter == selected[i])
			return i;
	return -1;
}

void word_status(string word)
{
	int index = -1;
	for (int i = 0; i < 5; i++) {
		index = find_index(word[i]);
		if (index == i)
			result[i] = 'g';
		else if (index > -1 && index != i && result[index] != 'g')
			result[i] = 'y';
		else
			result[i] = 'b';
	}
}

bool isValid(string word)
{
	if (find(words.begin(), words.end(), word) != words.end())
		return true;
	else
		return false;
}

void read_words_from_file(string file_name)
{
	string line = "";
	ifstream file(file_name);
	if(file.is_open()) {
		while(getline(file, line))
			words.push_back(line);
		file.close();
	} else {
		cout << "[out-err]: Unable to open file ";
	}
}
