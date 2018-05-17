/* This program sorts an array. It creates and tests the mechanisms for a function pointer,
   a functor (function object) and a lambda expression. It also incorporates a template into
   the sort function so it can be used with all three. */

//
//  main.cpp
//  PredicateDemo
//
//  Created by Joshua on 2/25/18.
//  Copyright © 2018 Joshua. All rights reserved.
//

#include <iostream>
#include "Fraction.h"

using namespace std;

//Create template predicate to use for various ways of defining order among the fraction class
template<typename predicate>

//Sort function for arrays
void sort(Fraction arr[], int size, predicate OutOfOrder)
{
    bool Swaps;
    Fraction temp;
    do
    {
        Swaps = false;
        for (int i = 0; i < size - 1; ++i)
            if (OutOfOrder(arr[i+1], arr[i]))
            {
                temp = arr[i]; arr[i] = arr[i + 1];
                arr[i + 1] = temp; Swaps = true;
            }
    } while (Swaps);
}

//Instantiate functor to order Fraction class instances
LessFract fractless;

int main()
{
    // Define three arrays of Fractions to sort using a function pointer, functor and lambda expression
    Fraction arr[] = { Fraction(1, 3), Fraction(2, 4), Fraction(1, 7), Fraction(3, 4), Fraction(2, 5), Fraction(6, 4), Fraction(3, 7) };
    Fraction arr2[] = { Fraction(1, 3), Fraction(2, 4), Fraction(1, 7), Fraction(3, 4), Fraction(2, 5), Fraction(6, 4), Fraction(3, 7), Fraction(5, 3) };
    Fraction arr3[] = { Fraction(1, 3), Fraction(2, 4), Fraction(1, 7), Fraction(3, 4), Fraction(2, 5), Fraction(6, 4), Fraction(3, 7), Fraction(5, 3), Fraction(7, 9) };
    // Sort first Fraction array using function pointer
    sort(arr, 7, lessthan);
    cout << "Sort with function pointer: \n";
    for (int i = 0; i < 7; ++i) cout << arr[i] << endl;
    // Sort second Fraction array using functor
    sort(arr2, 8, fractless);
    cout << "\nSort with functor: \n";
    for (int i = 0; i < 8; ++i) cout << arr2[i] << endl;
    // Sort third Fraction array using lambda expression
    sort(arr3, 9, [] (Fraction fract1, Fraction fract2) -> bool { return lessthan(fract1, fract2); });
    cout << "\nSort with lambda expression: \n";
    for (int i = 0; i < 9; ++i) cout << arr3[i] << endl;
    

    return 0;
}

