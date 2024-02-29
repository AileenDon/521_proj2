#ifndef SCANNER_H
#define SCANNER_H

typedef enum {
    read, write, id, literal, becomes,
    add, sub, mul, div_op, lparen, rparen, eof, semicolon
} token;

extern char token_image[100];

token scan();

#endif /* SCANNER_H */
