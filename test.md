# C Programming Examination

## Instructions

- Attempt Question ONE and any other TWO (2) Questions. Each Question carries equal marks
- Submit neat work, avoid cancellation, adhere to indentation of your codes
- Do rough work at the back of the answer booklet
- Submit question paper upon submission of answer booklet

Student ID: ……………………… Booklet ID: …………………………….

---

## QUESTION 1

A program allows users to enter two integers. The program compares the values and determines which is larger or if the values are equal. The program must handle invalid inputs and display appropriate messages.

### (i)

Draw a flowchart to represent the process of comparing two integers and handling errors.

### (ii)

Write a C program that:

- Prompts the user to enter two integers
- Uses scanf() to read inputs
- Compares using if-else statements
- Displays:
  - "First number is larger" if first > second
  - "Second number is larger" if second > first
  - "Both numbers are equal" if equal

### (iii)

Modify program to validate input using scanf() return value. If invalid, show error and re-enter.

### (iv)

Add loop with menu:

1. Compare two numbers
2. Exit  
   After each comparison ask user if they want to continue.

### (v)

Create function:
int compareNumbers(int a, int b)

- return 1 if a > b
- return -1 if b > a
- return 0 if equal

---

## QUESTION 2

A student grading system stores names and scores for 3 subjects.

### (i)

Draw a flowchart for input, calculation, and output of results.

### (ii) Theory

a) Structure vs Array  
b) Local vs Global variables  
c) Function prototype and importance

### (iii)

Define structure Student:

- name[50]
- scores[3]
- total
- average
- grade

Write program to:

- Input up to 20 students
- Calculate total, average, grade
- Display report

### (iv)

Grade rules:
A ≥ 80  
B ≥ 70  
C ≥ 60  
D ≥ 50  
E ≥ 40  
F < 40

Function:
char calculateGrade(float average)

### (v)

Add:

- Class average
- Highest scoring student
- Lowest scoring student

---

## QUESTION 3

Employee management system using file handling.

### (i)

Draw flowchart for Add, View, Search, Update, Delete.

### (ii) Theory

a) File handling and modes  
b) Text vs Binary files  
c) fopen, fclose, fwrite

### (iii)

Structure Employee:

- id
- name
- position
- salary

Menu:

1. Add Employee
2. View All
3. Search
4. Update
5. Delete
6. Exit

### (iv)

Use:

- fopen("rb","wb","ab")
- fwrite, fread

### (v)

Add:

- File existence check
- "Employee not found" message
- Prevent duplicate IDs

---

## QUESTION 4

Banking system.

### (i)

Flowchart for banking menu operations.

### (ii) Theory

a) Arrays  
b) \*ptr vs &var  
c) while vs do-while

### (iii)

Structure Account:

- accountNumber
- accountHolderName
- balance

Menu:

1. Deposit
2. Withdraw
3. Check Balance
4. Exit

### (iv)

Functions:

- deposit(Account \*acc, float amount)
- withdraw(Account \*acc, float amount)
- checkBalance(Account acc)

Rules:

- Positive deposit only
- No overdraft

### (v)

Add:

- Change account holder name
- Validate non-empty name

---

## QUESTION 5

Functions and recursion.

### (i)

Flowchart for factorial recursion.

### (ii) Theory

a) Functions and parameters  
b) Recursion concept  
c) Call by value vs reference

### (iii)

Functions:

- factorial(int n)
- swap(int *a, int *b)
- reverseString(char str[])

### (iv)

Implement all functions.

### (v)

Add:
int isPalindrome(char str[])
