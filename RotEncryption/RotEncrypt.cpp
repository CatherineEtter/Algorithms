/*
============================================================
=   Catherine Etter
=   C++ Program 
============================================================
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string codify(int shift,string str);

int main(void){
    
    string inputS;
    string str;
    string result;
    int shift=-1;
    int input;
    
    cout << "This program encrypts and decrypts messages using a Rot of your choice." << endl;
    cout << "Select one:\n 1) ENCRYPT\n 2) DECRYPT" << endl;
    
    while(input!=1&&input!=2){
        getline(cin,inputS);
        input=stoi(inputS);
        switch(input){
            case 1:
                cout << "Enter the string to encrypt: ";
                break;
            case 2:
                cout << "Enter the string to decrypt: ";
                break;
            default:
                cout << "Error: " << inputS << " is not a valid answer." << endl;
                break;
        }
    }
    getline(cin,str);
    
    while(shift<0 || shift>26){ //shift must be between 1-26 with respect to the alphabet
        cout << "Enter the shift (0-26): ";
        getline(cin,inputS);
        shift=stoi(inputS);
    }
    
    input==1 ? cout << codify(shift,str) << endl : cout << codify(26-shift,str) << endl;
    
    return 0;
}
string codify(int shift,string str){ //converts string to ascii to apply shift and converts it back
    
    int i,j;
    int temp;
    
    for(i=0;i<str.length();i++){ //for each letter in string
        temp=(int)str[i];
        for(j=0;j<shift;j++){ 
            if(temp<=90 && temp>=65){ //if uppercase
            temp==90 ? temp=65 : temp++;
            }
            if(temp<=122 && temp>=97){ //if lowercase
                temp==122 ? temp=97 : temp++;
            }
        }
        str[i]=(char)temp;
    }
    return str;
}
