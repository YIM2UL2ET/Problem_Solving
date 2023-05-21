sel = input().split()   # 1. 주사위 눈 입력
sel.sort()

price = 0       # 2. 변수 초기화 (price = 상금), (diceEye = 6~1 까지의 주사위 눈)
diceEye = 6

while diceEye>0:    # 3. 주사위 눈을 6~1 순으로 같은것 있는지 확인
    countEye = sel.count(str(diceEye)) 
    if countEye>1:  # 3-1. 같은것이 있으면 그만큼 상금 추가하고 확인작업을 끝냄
        price += 10**(countEye+1)+diceEye*10**countEye
        break
    diceEye-=1
else:
    price += 100*int(sel[-1]) # 3-2. 6~1까지 체크했는데도 같은것이 없다면 제일 큰 숫자만큼의 상금 추가
print(price)    # 4. 상금 출력