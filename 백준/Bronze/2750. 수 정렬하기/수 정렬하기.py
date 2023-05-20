#PKNU 수업 가산점을 위한 python 문제풀이

s = int(input())
a = s
n=[]
while s>0:
    n.append(int(input()))
    s-=1
n.sort()
while a>0:
    print(n[-a])
    a-=1