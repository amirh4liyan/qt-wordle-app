#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int abundance[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    ifstream file("valids.txt");
    
    string word;
    if (file.is_open())
    {
        while (getline(file, word))
        {
            for (int i = 0; i <= 4; i++)
            {
                int index = word[i] - 97;
                abundance[index]++;
            }
        }
        
    }
    else
    {
        cout << "file invalid!";
    }
    char alphabet;
    
    for (int j = 97 ; j <= 122 ; j++)
    {
        alphabet = j;
        cout << "The number of {" << alphabet << "} is " << abundance[j - 97] << endl ; 
    }
    return 0;
}

