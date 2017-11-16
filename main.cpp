/*
 NAME: Harish Palani
 CRN: 41600
 ASSIGNMENT: Lab 4
 SOURCES: stackoverflow.com
 */
 
#include <iostream>
#include <string>

using namespace std;

// Functions
long long euclidean(long long x, long long y);
void division(long long dividend, long long divisor);
void reset();

// Variables
long long gcd = 0;
long long quotient = 0;
long long remainder = 0;

int main() {
    long long x, y;
    string in;
    
    for (int i = 0; i < 4; i++) {
        /* Accept first integer input */
        cout << "Enter FIRST integer below." 
             << endl;
        cin >> in;
        
        try { // Check if x is numeric
            x = stoll(in);
        } catch (exception &e) {
            cout << "\n"
                 << "Make sure you're entering a positive integer!" 
                 << endl;
            cin >> x;
        }
        
        while (x < 1) { // Check if x is negative or zero
            cout << "\n"
                 << "Make sure you're entering a positive integer!" 
                 << endl;
            cin >> x;
        }
        
        /* Accept second integer input */
        cout << "Enter SECOND integer below."
             << endl;
        cin >> in;
        
        try { // Check if y is numeric
            y = stoll(in);
        } catch (exception &e) {
            cout << "\n"
                 << "Make sure you're entering a positive integer!" 
                 << endl;
            cin >> y;
        }
        
        while (y < 1 || y > x) { // Check if y is negative or zero
            cout << "\n"
                 << "Make sure your input is positive"
                 << " "
                 << "and less than the first integer you entered!" 
                 << endl;
            cin >> y;
        } 
        
        /* GCD (Euclidean algorithm) */
        gcd = euclidean(x, y);
        
        /* Quotient, remainder (Division algorithm) */
        division(x, y);
        
        /* Results */
        cout << "\n"
             << "GCD: "
             << gcd
             << "\n"
             << "Quotient: "
             << quotient
             << "\n"
             << "Remainder: "
             << remainder
             << "\n"
             << endl;
        
        /* Reset variables */
        reset();
    }
}

// Recursive implementation of Euclid's algorithm
long long euclidean(long long x, long long y) {
    if (x == 0) { return y; }
    return euclidean(y%x, x);
}

// Iterative implementation of division algorithm
void division(long long x, long long y) {
    long long temp = x;
    
    while (temp >= y) {
        temp = temp - y;
        quotient++; // Total number of y's subtracted is the quotient
    }
    
    // x - yq is equal to the remainder
    remainder = (x) - (y*quotient);
}

// Reset all variables
void reset() {
    gcd = 0;
    quotient = 0;
    remainder = 0;
}