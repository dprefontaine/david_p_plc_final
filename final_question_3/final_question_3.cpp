#include "final_question_3.h"

void assignment(){
    std::cout << "Entering <assignment>" << std::endl;

    //id = or += or -= or *= or /= or %= or <assignment> or <equality>

    if (nextToken == IDENTIFIER){
        lex();

        if (nextToken == ASSIGN_TO || nextToken == ASSIGN_ADD || nextToken == ASSIGN_DEC ||
            nextToken == ASSIGN_MUL || nextToken == ASSIGN_DIV || nextToken == ASSIGN_MOD){
            lex();

            while (nextToken == ASSIGN_TO){
                lex();
                assignment();
            }
        }
    }

    equality();
}

void equality(){
    std::cout << "Entering <equality>" << std::endl;

    //<relation> > or < or >= or <= or == or != <equality> or <relation>

    relation();

    while (nextToken == EQUAL_TO || nextToken == NOT_EQUAL_TO){
        lex();
        equality();
    }
}

void relation(){
    std::cout << "Entering <relation>" << std::endl;

    //<expr> > or < or >= or <= or == or != <relation> or <expr>

    expr();

    while (nextToken == GREATER_THAN || nextToken == LESSER_THAN ||
           nextToken == GREATER_EQUAL || nextToken == LESSER_EQUAL ||
           nextToken == INSTANCE_OF){
        lex();
        relation();
    }
}

void expr(){
    std::cout << "Entering <expr>" << std::endl;

    //<term> + or - <expr> or <term>

    term();

    while (nextToken == ADDITION_OP || nextToken == SUBTRACTION_OP){
        lex();
        expr();
    }
}

void term(){
    std::cout << "Entering <term>" << std::endl;

    //<unary> * or / or % <term> or <unary>

    unary();

    while (nextToken == MULTIPLY_OP || nextToken == DIVISION_OP || nextToken == MODULO_OP){
        lex();
        term();
    }
}

void unary(){
    std::cout << "Entering <unary>" << std::endl;

    //++<unary> or --<unary> or +<unary> or -<unary> or ~<unary> or !<unary> or <postfix>

    while (nextToken == PREFIX_ADDITION_OP || nextToken == PREFIX_SUBTRACT_OP|
           nextToken == UNARY_PLUS || nextToken == UNARY_NEGATION ||
           nextToken == UNARY_COMPLEMENT || nextToken == UNARY_NOT){
        lex();
        unary();
    }

    postfix();
}

void postfix(){
    std::cout << "Entering <postfix>" << std::endl;

    //<factor>++ or <factor>-- or <factor>

    while (nextToken == POSTFIX_ADDITION_OP || nextToken == POSTFIX_SUBTRACT_OP){
        factor();
        lex();
    }
}

void factor(){
    std::cout << "Entering <factor>" << std::endl;

    //(<expr>) or id or int literal or float literal or double literal or boolean literal

    if (nextToken == IDENTIFIER ||
        nextToken == INTEGER_LIT ||
        nextToken == FLOAT_LIT || nextToken == DOUBLE_LIT ||
        nextToken == BOOLEAN_LIT){
            lex();
    } else {
        //SEARCH FOR PARENTHESIS
        if (nextToken == LEFT_PARENTHESIS){
            lex();
            assignment();

            if (nextToken == RIGHT_PARENTHESIS){
                lex();
            } else {
                std::cout << "Error found: ";
                error();
            }
        } else {
            std::cout << "Error found: ";
            error();
        }
    }

    std::cout << "Exiting <factor>" << std::endl;
}
