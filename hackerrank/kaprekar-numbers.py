#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'kaprekarNumbers' function below.
#
# The function accepts following parameters:
#  1. INTEGER p
#  2. INTEGER q
#
def check(x):
    y = x*x
    s = str(y)
    r = len(s)//2
    if r == 0:
        return x == int(s)
    return x == (int(s[:r]) + int(s[r:]))
    
def kaprekarNumbers(p, q):
    ans = []
    for i in range(p, q+1):
        if check(i):
            ans.append(str(i))
    if len(ans) > 0:
        print(' '.join(ans))
    else:
        print('INVALID RANGE')

if __name__ == '__main__':
    p = int(input().strip())

    q = int(input().strip())

    kaprekarNumbers(p, q)
