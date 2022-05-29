# https://www.hackerrank.com/challenges/calendar-module/problem

# Enter your code here.
# --------------------------------------------------------- # 

import calendar

month, day, year = map(int, input().strip().split())
#print(f"{day} {month} {year}")

weekday = calendar.weekday(year, month, day)
#print("weekday: " + str(weekday))
day_name = calendar.day_name[weekday]
print(day_name.upper())

# --------------------------------------------------------- # 