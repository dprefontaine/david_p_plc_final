#include "ruby_state_machine_example.h"

void error(){
    reading = false;
    error_concerning = state;               //TELL WHICH STATE THE SYNTACTICAL ERROR WAS IN
}

void ruby_check_alpha(){
    switch (state){
        case START:
            //GO INTO VARIABLE ID AND PUT THAT CHARACTER IN THE VARIABLE
            state = VARIABLE;
        break;
        case VARIABLE:
            //KEEP PUTTING CHARACTERS IN THAT VARIABLE
        break;
        case FLOATING:
            if (input != 'e'){
                error();
            } else {
                //PUT INTO THAT FLOATING LITERAL
            }
        break;
        //STRINGS
        case SINGLE_QUOTE_STRING:
            //ADD TO THAT SINGLE QUOTE STRING
        break;
        case DOUBLE_QUOTE_STRING:
            //ADD TO THAT DOUBLE QUOTE STRING
        break;
        case GLOBAL_DECLARATION:
            //ADD TO THAT GLOBAL VARIABLE DECLARATION
        break;
        case INSTANCE_DECLARATION:
            //ADD TO THAT INSTANCE VARIABLE DECLARATION
        break;
        case CLASS_DECLARATION:
            //ADD TO THAT CLASS VARIABLE DECLARATION
        break;
        default:
            error();
        break;
    }
}

void ruby_check_digit(){
    switch (state){
        case START:
            //GO TO INTEGER AND ADD THAT DIGIT TO THE INTEGER
            state = INTEGER;
        break;
        case INTEGER:
            //KEEP PUTTING DIGITS INTO THAT INTEGER
        break;
        case FLOATING:
            //PUT DIGITS INTO THAT FLOATING
        break;
        default:
            error();
        break;
    }
}

void ruby_space(){
    //check if the current literal can be closed
    switch (state){
        case START:
            //GREY SPACE TO NEXT
        break;
        case INTEGER:
            //SPACE TO NEXT
        break;
        case FLOATING:
            //SPACE TO NEXT
        break;
        case GLOBAL_DECLARATION:
        case INSTANCE_DECLARATION:
        case CLASS_DECLARATION:
        break;
        default:
            error();
        break;
    }
}

void ruby_lookup(){
    //LOOKING UP IF A VARIABLE DECLARATION OR A FLOAT
    switch (input){
        //FLOAT
        case '.':
            //GO INTO FLOAT  FROM INT ELSE ERROR
            if (state == INTEGER){
                state = FLOATING;
            } else {
                error();
            }
        break;
        //STRINGS
        case '\'':
            if (state == START){
                //GO INTO SINGLE QUOTE STRINGS
                state = SINGLE_QUOTE_STRING;
            } else if (state == SINGLE_QUOTE_STRING){
                //FINISH THAT STRING
                state = START;
            } else {
                error();
            }
        break;
        case '\"':
            if (state == START){
                //GO INTO DOUBLE QUOTE STRINGS
                state = DOUBLE_QUOTE_STRING;
            } else if (state == DOUBLE_QUOTE_STRING){
                //FINISH THAT STRING
                state = START;
            } else {
                error();
            }
        break;
        //VARIABLE DECLARATIONS
        case '$':
            if (state == START){
                //ADD TO GLOBAL DECLARATION
                state = GLOBAL_DECLARATION;
            }
        break;
        case '@':
            if (state == INSTANCE_DECLARATION){
                //ADD TO DECLARATION AND SET TO CLASS DECLARATION
                state = CLASS_DECLARATION;
            } else if (state == START){
                //ADD TO INSTANCE DECLARATION
                state = INSTANCE_DECLARATION;
            } else {
                error();
            }
        break;
        case '_':
            ruby_check_alpha(); //TREAT AS AN ALPHA
        break;
        default:
            error();
        break;
    }
}

///WHILE THE MACHINE CAN READ
void ruby_get_char(){
    input = getchar();

    //SEE IF A CHARACTER
    if (isalpha(input)){
        ruby_check_alpha();

    //SEE IF A NUMBER
    } else if (isdigit(input)){
        ruby_check_digit();

    //SEE IF A SPACE
    } else if (isspace(input)){
        ruby_space();{

    }
    //IF MISCELLANEOUS (LOOK UP IF FLOATING, STRING, OR A VARIABLE DECLARATION)
    } else {
        ruby_lookup();
    }
}

bool get_reading(){
    return reading;
}

int get_error(){
    return error_concerning;
}
