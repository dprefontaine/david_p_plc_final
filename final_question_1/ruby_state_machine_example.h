#ifndef RUBY_STATE_MACHINE_EXAMPLE_H_INCLUDED
#define RUBY_STATE_MACHINE_EXAMPLE_H_INCLUDED

#include "stdio.h"
#include "ctype.h"

//DAVID PREFONTAINE
//

//PROBLEM 1 OF FINAL

/*
For this, it's solely looking at the state of a machine when characters are read, and not considering anything else

It is not a complete state machine, but it's purpose is recognizing floating points, integers, strings, variables, and variable declarations
*/

//LITERAL AND NAME STATES
#define START 0
#define VARIABLE 1
#define INTEGER 2
#define FLOATING 3

#define SINGLE_QUOTE_STRING 11
#define DOUBLE_QUOTE_STRING 12

#define GLOBAL_DECLARATION 21
#define INSTANCE_DECLARATION 22
#define CLASS_DECLARATION 23

void ruby_get_char();
bool get_reading();
int get_error();

void ruby_check_alpha();
void ruby_check_digit();
void ruby_space();
void ruby_lookup();
void error();

//THIS IS FOR THE STATE DIAGRAM OF RUBY
bool reading;                        //THIS IS TO SIGNIFY WHETHER OR NOT TO KEEP INTERPRETING
int error_concerning;
int state;
int input;

#endif // RUBY_STATE_MACHINE_EXAMPLE_H_INCLUDED
