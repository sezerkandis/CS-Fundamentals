# https://www.hackerrank.com/challenges/python-power-mod-power/problem

# Enter your code here.
# --------------------------------------------------------- #  
import math

a = int(input())
b = int(input())
m = int(input())

if (a >= 1 and a <= 10):
    if (b >= 1 and b <= 10):
        p = pow(a, b)
        print(p)
        print(p % m)

# --------------------------------------------------------- #  