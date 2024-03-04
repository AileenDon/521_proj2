#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

token current_token;

void program();
void statement();
void expr();
void term();
void factor();
extern int current_line;

void next_token() {
    current_token = scan();
}

void syntax_error(char *msg) {
    fprintf(stderr, "Syntax error on line %d: %s\n", current_line, msg);
    exit(1);
}

void match(token expected) {
    if (current_token == expected) {
        next_token();
    }
}

void program() {
    while (current_token != eof) {
        statement();
    }
}

void statement() {
    switch (current_token) {
        case read:
        case write:
        case id:
            next_token();
            match(becomes);
            expr();
            match(semicolon);
            break;
        default:
            syntax_error("Invalid statement");
    }
}

void expr() {
    term();
    while (current_token == add || current_token == sub) {
        next_token();
        term();
    }
}

void term() {
    factor();
    while (current_token == mul || current_token == div_op) {
        next_token();
        factor();
    }
}

void factor() {
    switch (current_token) {
        case id:
        case literal:
            next_token();
            break;
        case lparen:
            next_token();
            expr();
            if (current_token != rparen) {
                syntax_error("Missing closing parenthesis");
            } else {
                next_token(); 
            }
            break;
        default:
            syntax_error("Invalid factor");
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    if (freopen(argv[1], "r", stdin) == NULL) {
        fprintf(stderr, "Error redirecting stdin to file: %s\n", argv[1]);
        return 1;
    }

    next_token();
    program();

    printf("No lexical and syntax errors.\n");

    fclose(fp);

    return 0;
}
