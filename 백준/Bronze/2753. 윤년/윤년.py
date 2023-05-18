#PKNU 수업 가산점을 위한 python 문제풀이

year = int(input())
if year%4==0 and (year%100!=0 or year%400==0): print(1)
else: print(0)