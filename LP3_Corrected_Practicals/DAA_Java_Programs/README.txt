SPPU LP3 - DAA Java Programs

Files:
A1_Fibonacci.java
A2_JobSequencing.java
A3_FractionalKnapsack.java
A4_ZeroOneKnapsack.java
A5_BinomialCoefficient.java
A6_EightQueens.java

Compile and run each program:
    javac A1_Fibonacci.java
    java A1_Fibonacci

Change the class name for the other practicals.

Sample inputs:
A1: 5

A2 (4 jobs; each line is deadline profit):
4
4 20
1 10
1 40
1 30
Expected maximum profit: 60

A3 (each item: value weight):
3
60 10
100 20
120 30
50
Expected maximum value: 240

A4 (each item: weight value):
3
10 60
20 100
30 120
50
Expected maximum value: 220

A5:
5
2
Expected result: 10

A6:
0
0
Prints a valid solution with a fixed queen at row 0, column 0.

Notes:
- A3 allows taking a fraction of an item; A4 does not.
- A6 uses zero-based row and column numbers (0 to 7).
- A1 limits input to 30 terms to keep recursion practical.
- A5 uses long and accepts n up to 67.
- The manual does not specify a programming language, but confirm that your
  examiner/department accepts Java for the practical evaluation.
