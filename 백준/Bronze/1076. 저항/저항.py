#PKNU 수업 가산점을 위한 python 문제풀이

resistance = ['black','brown','red','orange','yellow','green','blue','violet','grey','white']
addValue1 = input()     # 값 입력
addValue2 = input()
squareValue = input()
print((resistance.index(addValue1)*10 + resistance.index(addValue2))*10**resistance.index(squareValue)) # (값1*10 + 값2)*10**값3