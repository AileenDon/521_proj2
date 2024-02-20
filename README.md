# README for Part 1: Enhanced Scanner

## Overview

This document outlines the functionality of the enhanced scanner for a calculator language, designed as part of the CSC521 project. The scanner is implemented in C and is responsible for lexical analysis, converting sequences of characters into a series of tokens.

## Features

- Recognizes and skips line (`//`) and block (`/* ... */`) comments.
- Identifies and returns tokens for keywords, identifiers, numeric literals, and symbols.
- Skips whitespace and handles end-of-statement semicolons (`;`).
- Provides informative error messages for unrecognized characters.

## Compilation and Execution

To compile the scanner, use the following command:

```bash
gcc scanner.c -o scanner
```

To run the scanner with an input file, use:

```bash
./scanner < input_file.txt
```
