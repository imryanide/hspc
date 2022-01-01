/*
Develop a program that, given an Egyptian fraction (i.e., a set of distinct positive unit fractions), calculates the sum and expresses it in simplest (i.e., reduced) form.
Input: The first line contains a positive integer n indicating how many instances of the problem
are subsequently described. Each such instance is described on two lines, the first of which
contains a single positive integer m indicating how many unit fractions are to be summed. On
the second line appears a sequence of m distinct positive integers k1, k2, . . . , km, which is to be
interpreted as representing the Egyptian fraction 1


Output: For each Egyptian fraction given as input, your program should generate a single line
of output indicating the unit fractions that were summed (separated by plus signs), followed
by an equals sign, followed by the sum, in simplest form.
Sample input Resultant output
------------ ----------------
3 1/2 + 1/10 = 3/5
2 1/35 = 1/35
2 10 1/98 + 1/1 + 1/2 + 1/12 = 937/588
1
35
4
98 1 2 12
*/

#include <stdio.h>
#include <math.h>
