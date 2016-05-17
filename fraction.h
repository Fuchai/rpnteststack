#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

class fraction {
public:
    fraction(int numerator = 0, int denominator = 1);
    int getNum();
    void setNum(int numerator);
    int getDenominator();
    void setDenominator(int denominator);
    friend std::ostream& operator<<(std::ostream& os, const fraction &fraction);
    fraction operator+(fraction &pSummand);
    fraction operator-(fraction &pSubtrahend);
    fraction operator*(fraction &pMultiplicator);
    fraction operator/(fraction &pDivisor);



private:
    int top;
    int bottom;
    int gcd(int x, int y);
    void reduce();



};

#endif