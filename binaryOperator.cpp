
// File: binaryOperator
// Created by Jaxon Greenwood on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>
using namespace std;

// Constants
class Distance{
private:
    int feet;
    float inches;
public:
    Distance():feet(0), inches(0.0){}

    Distance(int f, float i){
        feet = f;
        inches = i;
    }



    void getDist(){
        cout << "Enter feet: ";
        cin >> feet;

        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDist(){
        cout << feet << "\' - " << inches << "\"";
    }

    Distance operator + (Distance) const;
    void operator += (Distance);
};

// Return the sum
Distance Distance::operator + (Distance d2) const {
    int f = feet + d2.feet;
    int i = inches + d2.inches;

    while (i >= 12.0){
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}

void Distance::operator += (Distance d2) {      // adding 1 distance to existing one

    feet += d2.feet;
    inches = inches + d2.inches;

    if (inches >= 12.0){
        inches -= 12.0;
        feet++;
    }

}

// Prototypes

// Main Program Program

int main(void) {

    Distance d1, d3;
    Distance d2(11, 6.25);

    d1.getDist();

    cout << "\nDistance d1 = ";
    d1.showDist();
    cout << endl;

    cout << "Distance d2 = ";
    d2.showDist();
    cout << endl;
    // Add binary operator support;

    d3 = d1 + d2;
    cout << "Distance d3 =";
    d3.showDist();
    cout << endl;

    d2 += d3;
    cout << "Distance d2 =";
    d2.showDist();
    cout << endl;


    return 0;
}

// Function Definitions
