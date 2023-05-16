#PKNU 수업 가산점을 위한 python 문제풀이

N0=int(input())         #숫자 입력
N1=int(input())

digit1=int(N1%10)       #자릿수에 해당하는 숫자 구하기 (1>2>3)
digit2=int(N1%100//10)
digit3=int(N1//100)

print(N0*digit1)        #출력
print(N0*digit2)
print(N0*digit3)
print(N0*N1)