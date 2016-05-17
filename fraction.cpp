#include "fraction.h"

fraction::fraction(int numerator, int denominator)
: top(numerator) {
    bottom = denominator;
}

int fraction::getNum() {
    return top;
}

void fraction::setNum(int numerator) {
    top = numerator;
}

int fraction::getDenominator() {
    return bottom;
}

void fraction::setDenominator(int denominator) {
    bottom = denominator;
}

std::ostream& operator<<(std::ostream& os, const fraction &fraction) {
    os << "(" << fraction.top << "/" << fraction.bottom << ")";
    return os;
}

fraction fraction::operator+(fraction &pSummand) {
    fraction result;
    result.top = (top * pSummand.bottom) + (pSummand.top * bottom);
    result.bottom = bottom * pSummand.bottom;
    result.reduce();
    return result;
}

fraction fraction::operator-(fraction &pSubtrahend) {
    fraction result;
    result.top = (top * pSubtrahend.bottom) - (pSubtrahend.top * bottom);
    result.bottom = bottom * pSubtrahend.bottom;
    result.reduce();
    return result;
}

fraction fraction::operator*(fraction &pMultiplicator) {
    fraction result;
    result.top = top * pMultiplicator.top;
    result.bottom = bottom * pMultiplicator.bottom;
    result.reduce();
    return result;
}

fraction fraction::operator/(fraction &pDivisor) {
    fraction result;
    result.top = top * pDivisor.bottom;
    result.bottom = bottom * pDivisor.top;
    result.reduce();
    return result;
}

int fraction::gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

void fraction::reduce() {
    int i = top;
    if (i < 0) {
        i *= -1;
    }
    int j = bottom;
    if (j < 0) {
        j *= -1;
    }
    int result = gcd(i, j);
    top = top / result;
    bottom = bottom / result;
}
