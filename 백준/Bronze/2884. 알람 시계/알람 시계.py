#PKNU 수업 가산점을 위한 python 문제풀이

hour, minute = map(int,input().split())
if minute-45>=0 : print("%d %d"%(hour, minute-45))
elif minute-45<0 and hour-1>=0: print("%d %d"%(hour-1, minute+15))
else: print("%d %d"%(hour+23, minute+15))