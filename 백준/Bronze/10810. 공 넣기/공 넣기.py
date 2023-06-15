n, m = map(int,input().split())
basket = []
for n0 in range(n): basket.append(0)
for n0 in range(m):
    i, j, k = map(int,input().split())
    for p in range(i,j+1): basket[p-1] = k
for n0 in range(n): print(basket[n0], end=" ")