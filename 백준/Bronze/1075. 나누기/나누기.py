#PKNU 수업 가산점을 위한 python 문제풀이

N0 = int(input(""))
N1 = int(input(""))
i=N0-N0%N1                   # i=N0-나머지 (N1으로 나누었을때 나누어 떨어지도록)

if i//100<N0//100: i+=N1     # 세자리수 숫자 변동 방지
while i%100>=N1: i-=N1        # 첫,둘째자리 수를 최대한 작게 만드는 과정

result=i%100                 # result = i의 첫,두번째 자리수

if result>=10: print(result) # result가 10이상일때 두자리수 그대로 출력
else: print("0%d"%(result))  # result가 10미만이면 앞에 0을 붙여 두자리수로 출력