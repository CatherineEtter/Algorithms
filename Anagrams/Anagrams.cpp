// ===============================
// = Catherine Etter
// = Chapter 1.4, Problem 10
// = Anagrams.cpp
// ===============================
// Checks if two inputs are anagrams

#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;

bool isAnagram(string str1, string str2);
string toLowerAlpha(string str);

int main()
{
    string str1,str2;
    bool strsAnagrams;
   
    cout << " This program requires two words of the same length and " << endl
         << " checks to see if they are anagrams of each other." << endl
         << " An anagram is a word that looks like another word when the" << endl
         << " individual letters are rearranged. Ex: \"eat\" and \"tea\"." << endl
         << " Press Ctrl+Z to quit." << endl;
         
    cout << endl << "Enter first string: ";
    while(getline(cin,str1))
    {
        cout << "Enter second string: ";
        getline(cin,str2);
        
        cout << "\"" << str1 << "\"" << " and " << "\"" << str2 << "\" are " 
             << (isAnagram(str1,str2) ? "anagrams." : "not anagrams.") << endl;
        cout << endl << "Enter first string: ";
    }
}
bool isAnagram(string str1, string str2)
{
    str1 = toLowerAlpha(str1);
    str2 = toLowerAlpha(str2);
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    
    return (str1.compare(str2) == 0);
}
string toLowerAlpha(string str) //Removes non-alpha characters and converts to lowercase
{
    string newStr;
    for(int i = 0; i < str.length(); i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
            newStr.append(str,i,1);
        }
    }
    return newStr;
}

