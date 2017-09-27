// ===============================
// = Catherine Etter
// = Chapter #, Problem #
// = Problem.cpp
// ===============================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;

void anagramify(string word, int start);
void swap(string str, int p1, int p2);

int main()
{
    string input;
    
    cout << "This program outputs all permutations of the entered string.\n" 
         << "Repeats are possible if the string has identical letters" << endl;
    cout << "Enter word: ";
    while(cin >> input)
    {
        cout << "Anagrams for " << input << ":" << endl;
        anagramify(input,0);
        cout << "Enter word: ";
    }
    
}
/*
Get's permutations by putting the element in the place start (initially 0)
 in the front of the array string, then it recursively calls itself
 to find all the combinations.
*/
void anagramify(string str, int start)
{
    if(start == str.size())
    {
        cout << str << endl;
    }
    if(start < str.size())
    {
        for(int i = start; i < str.size(); i++) //Traverse array from place "from"
        {
            swap(str[start],str[i]);
            anagramify(str,start + 1);
        }
    }
}
