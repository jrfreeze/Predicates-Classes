// This is the specification file for the Fraction class and the related functor, LessFract.
//
//  Fraction.h
//  Fraction
//
//  Created by Joshua on 1/21/18.
//  Copyright © 2018 Joshua. All rights reserved.
//

#ifndef Fraction_h
#define Fraction_h

#include <stdio.h>
using namespace std;


class Fraction {
public:
    // Constructor: default values allows one to handle both default and overloaded construction
    Fraction(int = 0, int = 1);
    
    // Prints fraction in numerator/denominator format
    void print();
    
    // True if fraction can be reduced, False otherwise
    bool reducible();
    
    // Reduces the fraction to lowest terms
    void reduceme();
    
    // Returns reduced fraction. Does not alter original fraction
    Fraction reduce();
    
    // Getter functions for numerator & denominator
    int getNumer();
    int getDenom();
    
    // Friend overloaded extraction operator to allow cout << Fraction object
    friend ostream& operator<< (ostream& output, Fraction fract);
    
    
private:
    // Numerator & denominator of the the fraction
    int numer,
        denom;
};

// Returns greatest common divisor
int GCD(int a, int b);

// Returns least common multiple
int LCM(int a,int b);

// Adds two members of the Fraction class using standard fraction rules
Fraction add(Fraction, Fraction);

// Returns true if the first Fraction is less than the second
bool lessthan(Fraction, Fraction);

//Class to create functor for ordering Fraction class instances
class LessFract
{
public:
    bool operator() (Fraction fract1, Fraction fract2)
    { return (lessthan(fract1, fract2)); }
};

#endif /* Fraction_h */

