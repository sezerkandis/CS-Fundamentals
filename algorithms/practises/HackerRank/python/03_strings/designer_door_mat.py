# https://www.hackerrank.com/challenges/designer-door-mat/problem

# Enter your code here.
# --------------------------------------------------------- #  
N, M = map(str,input().split())
#print(f"N: {N}, M: {M}")

N = int(N)
M = int(M)
n_middle = (N - 1) / 2
m_middle = (M - 1) / 2

multiplier = 1
count = 0
for n in range(N):
    if (n == n_middle):
        welcome = "WELCOME"
        print("-" * int((M - len(welcome)) / 2), end ="")
        print(welcome, end ="")
        print("-" * int((M - len(welcome)) / 2))
        multiplier = -1
        count = 1
    else:        
        I_count = ((n + (multiplier * count * 2))+1) * 2 - 1
        mat = ".|." * I_count
        line = "-" * int((M - len(mat)) / 2)
        print(line + mat + line)
        if (multiplier == -1):
            count += 1
# --------------------------------------------------------- #  