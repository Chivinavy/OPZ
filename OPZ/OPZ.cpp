#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#define BUF_SIZE 1024

double eval(char* str);
double number(char*, unsigned*);
double expr(char*, unsigned*);
double term(char*, unsigned*);
double factor(char*, unsigned*);

int main() {
    setlocale(LC_ALL, "");
    char str[BUF_SIZE];
    printf("Введите выражение: ");
    fgets(str, BUF_SIZE, stdin);
    printf("Результат вычисления: %lf\n", eval(str));
    return 0;
}
double eval(char* str) {
    unsigned i = 0;
    return expr(str, &i);
}
double number(char* str, unsigned* idx) {
    double result = 0.0;
    double div = 10.0;
    int sign = 1;
    if (str[*idx] == '-') {
        sign = -1;
        ++* idx;
    }
    while (str[*idx] >= '0' && str[*idx] <= '9') {
        result = result * 10.0 + (str[*idx] - '0');
        ++* idx;
    }
    if (str[*idx] == '.') {
        ++* idx;
        while (str[*idx] >= '0' && str[*idx] <= '9') {
            result = result + (str[*idx] - '0') / div;
            div *= 10.0;
            ++* idx;
        }
    }
    return sign * result;
}
double expr(char* str, unsigned* idx) {
    double result = term(str, idx);
    while (str[*idx] == '+' || str[*idx] == '-') {
        switch (str[*idx]) {
        case '+':
            ++ * idx;
            result += term(str, idx);
            break;
        case '-':
            ++ * idx;
            result -= term(str, idx);
            break;
        }
    }
    return result;
}
double term(char* str, unsigned* idx) {
    double result = factor(str, idx);
    double div;
    while (str[*idx] == '*' || str[*idx] == '/') {
        switch (str[*idx]) {
        case '*':
            ++ * idx;
            result *= factor(str, idx);
            break;
        case '/':
            ++ * idx;
            div = factor(str, idx);
            if (div != 0.0) {
                result /= div;
            }
            else {
                printf("Division by zero!\n");
                exit(-1);
            }
            break;
        }
    }
    return result;
}
double factor(char* str, unsigned* idx) {
    double result;
    int sign = 1;
    if (str[*idx] == '-') {
        sign = -1;
        ++* idx;
    }
    if (str[*idx] == '(') {
        ++* idx;
        result = expr(str, idx);
        if (str[*idx] != ')') {
            printf("Скобки введены не верно\n");
            exit(-2);
        }
        ++* idx;
    }
    else
        result = number(str, idx);
    if (str[*idx] == '^') {
        ++* idx;
        result = pow(result, factor(str, idx));
    }
    return sign * result;
}
