#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <string.h>
#include "stack.h"
#include "fraction.h"

using namespace std;

int main() {
    cout << "RPN Calculator" << endl;
    Stack<fraction> mystack;
    fraction memory = 0;
    string s;
    cout << "Enter an Expression: ";
    getline(cin, s);
    while (s != "") {
        istringstream sin(s);
        string t;
        try {
            while (!sin.eof()) {
                sin >> t;
                string commandline = t;
                if (isdigit(commandline[0])) {
                    int numerator = stof(commandline.c_str());
                    fraction frac(numerator, 1);
                    mystack.push(frac);
                } else {
                    fraction a = 0;
                    fraction b = 0;
                    fraction result = 0;
                    char * pch;
                    Stack<int> intstack;
                    switch (commandline[0]) {
                        case '+': try {
                                if (mystack.isEmpty()) {
                                    throw domain_error("queue empty");
                                }
                                a = mystack.top();
                                mystack.pop();
                                b = mystack.top();
                                mystack.pop();
                                if (!mystack.isEmpty()) {
                                    throw domain_error("queue not empty");
                                }
                                result = a + b;
                                mystack.push(result);
                            } catch (...) {
                                cout << "The expression is malformed" << endl;
                                break;
                            }
                            break;
                        case '-': try {
                                if (mystack.isEmpty()) {
                                    throw domain_error("queue empty");
                                }
                                a = mystack.top();
                                mystack.pop();
                                b = mystack.top();
                                mystack.pop();
                                if (!mystack.isEmpty()) {
                                    throw domain_error("queue not empty");
                                }
                                result = b - a;
                                mystack.push(result);
                            } catch (...) {
                                cout << "The expression is malformed" << endl;
                                break;
                            }
                            break;
                        case '/': try {
                                if (mystack.isEmpty()) {
                                    throw domain_error("queue empty");
                                }
                                a = mystack.top();
                                mystack.pop();
                                b = mystack.top();
                                mystack.pop();
                                if (!mystack.isEmpty()) {
                                    throw domain_error("queue not empty");
                                }
                                result = b / a;
                                mystack.push(result);
                            } catch (...) {
                                cout << "The expression is malformed" << endl;
                                break;
                            }
                            break;
                        case '*': try {
                                if (mystack.isEmpty()) {
                                    throw domain_error("queue empty");
                                }
                                a = mystack.top();
                                mystack.pop();
                                b = mystack.top();
                                mystack.pop();
                                if (!mystack.isEmpty()) {
                                    throw domain_error("queue not empty");
                                }
                                result = a * b;
                                mystack.push(result);
                            } catch (...) {
                                cout << "The expression is malformed" << endl;
                                break;
                            }
                            break;
                        case 'S': try {
                                if (mystack.isEmpty()) {
                                    throw domain_error("queue empty");
                                }
                                memory = mystack.top();
                            } catch (...) {
                                cout << "The expression is malformed" << endl;
                                break;
                            }
                            break;
                        case 'R': mystack.push(memory);
                            break;
                        case '(':{
                            cout << commandline[1] << endl;
                            int top=stoi(commandline.substr(1,commandline.find('/')));
                            int bottom=stoi(commandline.substr(commandline.find('/')+1,commandline.length()-1));
                            mystack.push(fraction(top,bottom));
                        }
                            break;
                        default: cout << "Malformed Number" << endl;
                            break;
                    }
                }
            }
            if (mystack.size() == 2) {
                while (!mystack.isEmpty()) {
                    mystack.pop();
                }
                throw domain_error("bad");
            }
        } catch (...) {

            while (!mystack.isEmpty()) {
                mystack.pop();
            }
            cout << "The expression is malformed" << endl;

        }
        try {
            if (mystack.top().getDenominator() == 1) {
                cout << mystack.top().getNum() << endl;
            }
            if (mystack.top().getDenominator() != 1) {
                cout << mystack.top() << endl;
            }
        } catch (domain_error) {
            ;
        }
        while (!mystack.isEmpty()) {
            mystack.pop();
        }
        cout << "Enter an Expression: ";
        getline(cin, s);

    }
    return 0;
}