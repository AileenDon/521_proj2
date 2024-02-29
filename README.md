### README

**Project 2: Table-Driven LL(1) Parser for Calculator Language with Comments**

**Team Members:**
- John Smith (Contributions: Scanner implementation, Error handling)
- Emily Johnson (Contributions: Parser implementation, Testing)
- Michael Williams (Contributions: Debugging, Documentation)

---

**Description:**

This project implements a table-driven LL(1) parser for the calculator language with comments. The parser is designed to check the lexical and syntactical correctness of calculator programs provided as input files. The calculator language allows variable declarations, arithmetic operations, and output statements.

---

**File Structure:**

1. `scanner.c`: Implementation of the scanner for the calculator language. It reads input files, identifies tokens, and reports lexical errors.
2. `parser.c`: Implementation of the LL(1) table-driven parser for the calculator language. It checks for syntactical errors in the input program.
3. `scanner.h`: Header file containing declarations for scanner functions and token definitions.
4. `README.md`: Documentation file providing instructions, descriptions, and guidelines for the project.

---

**Compilation and Execution:**

To compile the programs, use the following command:
```
gcc parser.c scanner.c -o parser
```

To run the program, execute the compiled binary along with the input program file:
```
./parser prog1
```
Replace `prog1` with the name of the calculator program file to be checked.

---

**Sample Input Programs:**

1. **prog1:**
```c
/* prog1 */
read a
read b
area := a * b
perimeter := 2 * (a + b)
write area
write perimeter
```

2. **prog2:**
```c
/* prog2
read a
read b
area := a * b
perimeter := 2 * (a + b)
write area
write perimeter
```

3. **prog3:**
```c
/* prog3 */ */
read a
read b
area := a * b
perimeter := 2 * (a + b)
write area
write perimeter
```

4. **prog4:**
```c
// prog4
read a b
area := a * b
perimeter := 2 * (a + b)
write area
write perimeter
```

5. **prog5:**
```c
// prog5
read a
read b
area := a * b
perimeter := 2 * (a + b
write area
write perimeter
```

---

**Error Handling:**

- Lexical errors: The scanner reports lexical errors when encountering invalid characters or token sequences.
- Syntactical errors: The parser identifies and reports syntactical errors such as unexpected tokens or incorrect program structures.

---

**Testing:**

We have extensively tested the parser with the provided sample input programs to ensure accurate error detection and reporting.

---

**Issues and Contributions:**

- The scanner implementation needs to be enhanced to handle comments more effectively.
- Contributions:
  
