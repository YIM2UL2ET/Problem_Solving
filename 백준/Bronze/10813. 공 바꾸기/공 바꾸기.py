n, m = map(int,input().split())
sel = list(range(1,n+1))
for k in range(m):
    i, j = map(int,input().split())
    sel[j-1] , sel[i-1] = sel[i-1] , sel[j-1]
sel = map(str,sel)
print(' '.join(sel))