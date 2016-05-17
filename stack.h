#ifndef STACK_H
#define STACK_H
#include <vector>
#include <iostream>
#include <cstddef>

using namespace std;

class EmptyStackException {
public:
    EmptyStackException(string);
    string getMessage();
private:
    string msg;
};

template<class T>
class Stack {
public:
    Stack();
    void push(T);
    T pop();
    T top();
    int size();
    bool isEmpty();
private:
    vector<T> vec;
};

template<class T>
Stack<T>::Stack() {}

template<class T>
void Stack<T>::push(T x) {
    vec.push_back(x);
}

template<class T>
T Stack<T>::pop() {
    T num = vec.back();
    vec.pop_back();
    return num;
}

template<class T>
T Stack<T>::top() {
    if (this->isEmpty()) (throw domain_error("Stack isEmpty"));
    T x = vec.back();
    return x;
}

template<class T>
int Stack<T>::size() {
    return vec.size();
}

template<class T>
bool Stack<T>::isEmpty() {
    return vec.size() == 0;
}

#endif
