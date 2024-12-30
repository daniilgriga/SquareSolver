![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

# SquareSolver

This project is the first task of the programming course by [Ilya Dedinsky](https://github.com/ded32).

## General information

**SquareSolver** can solve a quadratic equation in real numbers. For convenience, input is carried out from the command line, an input filter is implemented: for each coefficient input there are 5 lives, only real numbers are accepted.

## Usage example

The start of the program looks like this:
```
# Solver of quadratic equations!
# Author: dan

# Enter a:
```

If the **correct** coefficient is entered:
```
...

# Enter a: 1
# Enter b:
```

Let's get to the answer of example:
```
...

# Enter a: 1
# Enter b: -7
# Enter c: 10
Two roots: x1 = 2 and x2 = 5
```

If the **incorrect** coefficient is entered:
```
...

# Enter a: linux

You didn't enter a number!
You have 4 lifes left
# Enter a:
```

If your lives is over:
```
You didn't enter a number!
You have 0 lifes left
Goodbye!
```
