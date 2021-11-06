# https://www.hackerrank.com/challenges/incorrect-regex/problem

# Enter your code here.
# --------------------------------------------------------- # 


import re
T = int(input())

if (T > 0 and T < 100):
    for _ in range(T):
        try:
            pattern = re.compile(input())
            result = True
        except re.error:
            result = False
        print(result)

# exampple of re.compile.command 
# https://pynative.com/python-regex-compile/

# patternt = re.compile(r"\b\w{5}\b") # pattern is 5 letter keyword
# result = patternt.findall("Hello fuc*ing world")
# print(result)

# --------------------------------------------------------- # 