#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Add a global variable for the current line number
int current_line = 1;

typedef enum {
    read, write, id, literal, becomes,
    add, sub, mul, div_op, lparen, rparen, eof,semicolon
} token;

char token_image[100];

char* token_names[] = {
    "read", "write", "id", "literal", "becomes",
    "add", "sub", "mul", "div_op", "lparen", "rparen", "eof", "semicolon"
};

token scan() {
    static int c = ' ';
    // Clear token image buffer
    memset(token_image, 0, sizeof(token_image));
    int i = 0;

    //Skip white space 
    while (isspace(c)) {
        if (c == '\n') {
            current_line++;
        }
        c = getchar();
    }

    // Handle end of file
    if (c == EOF) return eof;

    // Handle comments or division operator
    if (c == '/') {
        c = getchar();
        if (c == '*') { // Block comment
            int prev = 0;
            do {
                prev = c;
                c = getchar();
                if (c == '/' && prev == '*') break;
                if (c == EOF) {
                    fprintf(stderr, "Lexical error on line %d: unterminated comment.\n", current_line);
                    exit(1);
                }

            } while (1);
            // Move past comment
            c = getchar(); 
            return scan(); 

            // Line comment
        } else if (c == '/') { 
            while (c != '\n' && c != EOF) c = getchar();
            return scan(); 

            // Division operator
        } else { 
            return div_op;
        }
    }

    // Handle numbers
    if (isdigit(c)) {
        do {
            token_image[i++] = c;
            c = getchar();
        } while (isdigit(c));
        // Null terminate string
        token_image[i] = '\0'; 
        return literal;
    }

    // Handle identifiers and reserved words
    if (isalpha(c)) {
        do {
            token_image[i++] = c;
            c = getchar();
        } while (isalnum(c));
        token_image[i] = '\0'; // Null-terminate string
        // Check for reserved words
        if (strcmp(token_image, "read") == 0) return read;
        if (strcmp(token_image, "write") == 0) return write;
        return id;
    }

    // Handle single character tokens
    switch (c) {
        case ':':
            if ((c = getchar()) == '=') {
                c = getchar();
                return becomes;
            }
            fprintf(stderr, "Error: unrecognized character: ':'.\n");
            exit(1);
        case '+': c = getchar(); return add;
        case '-': c = getchar(); return sub;
        case '*': c = getchar(); return mul;
        case '(': c = getchar(); return lparen;
        case ')': c = getchar(); return rparen;
        case ';': c = getchar(); return semicolon; 
        default:
            fprintf(stderr, "Error: unrecognized character: '%c'.\n", c);
            exit(1);
    }
}

// int main() {
//     token t;
//     while ((t = scan()) != eof) {
//         printf("Token: %s, Image: [%s]\n", token_names[t], token_image);
//     }
//     return 0;
// }
