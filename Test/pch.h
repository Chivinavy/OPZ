//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
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
