#PKNU 수업 가산점을 위한 python 문제풀이

hour, minute = map(int,input().split())
extraTime = int(input())
while minute+extraTime>=60:
    hour+=1
    extraTime-=60
while hour>=24: hour-=24
print("%d %d"%(hour, minute+extraTime))