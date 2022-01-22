# https://www.hackerrank.com/challenges/zipped/

student, course = list(map(int, input().split()))

notes, result = [], []
[notes.append(input().split()) for c in range(course)]
result = [sum(tuple(map(float, col))) / course for col in zip(*notes)]
[print(r) for r in result]