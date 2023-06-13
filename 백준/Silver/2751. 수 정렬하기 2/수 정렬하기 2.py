import sys

countN = int(input())
nList = []
for i in range(countN): nList.append(int(sys.stdin.readline()))
nList.sort()
for i in range(countN): print(nList[i])