n, m = map(int,input().split())
sel = [1000,1000]
for i in range(m):
    pack, piece = map(int,input().split())
    if sel[0]>pack:
        sel.insert(0,pack)
        del sel[1]
    if sel[1]>piece:
        sel.insert(1,piece)
        del sel[2]
if sel[0] > sel[1]*6: print(sel[1]*n)
elif sel[0] > sel[1]*(n%6): print(sel[0]*(n//6) + sel[1]*(n%6))
else: print(sel[0]*(n//6+1))