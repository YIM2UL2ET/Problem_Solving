totalMoney = int(input())
totalCount = int(input())
for n in range(0,totalCount):
    money, count = map(int,input().split())
    totalMoney -= money * count
if totalMoney == 0: print("Yes")
else: print("No")