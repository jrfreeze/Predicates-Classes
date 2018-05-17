// This implements the Fraction class with a single constructor with default values for denominator and numerator so it permits a default and an initialized instantiation. Additional functions print the fraction, determine if it is reducible, reduce it, returns a reduced fraction, return the numerator, return the denominator. Necessary non-member functions return the least common multiple, greatest common divisor, and whether one fraction is less than another.

//
//  Fraction.cpp
//  Fraction
//
//  Created by Joshua on 1/21/18.
//  Copyright © 2018 Joshua. All rights reserved.
//

#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction::Fraction(int numer, int denom) {
    if (denom >= 1)  {  // Ensure denominator is positive
        this->denom = denom;
        this->numer = numer;
    }
    else {  // If denominator entered is zero or negative, throw an exception
        throw invalid_argument("Denominator must be positive");
    }
}

void Fraction::print() {
    cout << numer << '/' << denom;
}

bool Fraction::reducible() {
    return (GCD(numer, denom) > 1);
}

void Fraction::reduceme() {
    if (this->reducible()) {  // Check if the fraction is reducible
        int gcd = GCD(numer, denom);
        denom /= gcd;
        numer /= gcd;
    }
}

Fraction Fraction::reduce() {
    Fraction newfract;  // Create variable to hold fraction to reduce
    newfract = *this;   // Dereference original fraction and assign to newfract
    newfract.reduceme();    // Reduce newfract
    return newfract;
}

int Fraction::getNumer() {
    return numer;
}

int Fraction::getDenom() {
    return denom;
}

int GCD(int a, int b)
{
    a = abs(a); // to avoid issues with negative numbers in tests with GCD > 1
    b = abs(b);
    while(true)
    {
        a = a % b;
        if (a==0) return b;
        b = b % a;
        if (b == 0) return a;
    }
}

int LCM(int a,int b)
{
    return (a*b)/GCD(a,b);
}

// Adds fractions by finding the common denominator
Fraction add(Fraction a, Fraction b) {
    // New denominator is least common multiple of original denominators
    int newDenom = LCM(a.getDenom(), b.getDenom());
    // New numerator is the sum of:
    // contribute from the first fraction after finding the common denominator
    int newNumer = a.getNumer() * newDenom / a.getDenom() +
    // the contribution from the second after finding the common denominator
    b.getNumer() * newDenom / b.getDenom();
    return Fraction(newNumer, newDenom);
}

bool lessthan(Fraction a, Fraction b) {
    return (a.getNumer() * b.getDenom() < b.getNumer() * a.getDenom());
}

// Overloaded extraction operator to allow cout << Fraction object
ostream& operator<< (ostream& output, Fraction fract) {
    output << fract.getNumer() << '/' << fract.getDenom();
    return output;
}
