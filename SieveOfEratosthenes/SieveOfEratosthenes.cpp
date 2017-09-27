// ===============================
// = Catherine Etter
// = SieveOfEratosthenes.cpp
// ===============================
// Contains a function that creates a vector of primes from Lowerbase to Upperbase
// Will make into a header file later

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#define WALKTHROUGH

using namespace std;

vector<int> getPrimes(int LB, int UB);

int main()
{
    int LB,UB;
    vector<int> primes;
    
    cout << "Enter Lowerbase and Upperbase: " << endl;
    cin >> LB >> UB;
    primes = getPrimes(LB,UB);
    for(int i; i < primes.size(); i++)
    {
        cout << primes[i] << endl;
    }
}
vector<int> getPrimes(int LB, int UB)
{
    bool sieve[UB+1]; //Only care about LB to UB indexes
    vector<int> primes;
    
    for(int i = 0; i < sizeof(sieve); i++) //Initialize all values to true
    {
        sieve[i] = true;
    }
    for(int i = 2; i < sqrt(UB); i++)
    {
        if(sieve[i])
        {
            int m = 0;
            for(int j = pow(i,2); j < UB; j = pow(i,2) + (i * m))
            {
                sieve[j] = false;
                m++;
            }
        }
    }
    for(int i = 2; i <= UB; i++) //Put value of indexies resulting to true into vector
    {
        if(sieve[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
/*
Based on Wikipedia's Sourcecode on page https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Pseudocode
 Input: an integer n > 1.
 
 Let A be an array of Boolean values, indexed by integers 2 to n,
 initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding sqrt(n):
   if A[i] is true:
     for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n:
       A[j] := false.
 
 Output: all i such that A[i] is true.
*/
