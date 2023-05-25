n = int(input())
sum = 0
scores = input().split()
scores = list(map(int,scores))
maxscore = max(scores)
for score in scores: sum += score/maxscore*100
average = sum/n
print(average)