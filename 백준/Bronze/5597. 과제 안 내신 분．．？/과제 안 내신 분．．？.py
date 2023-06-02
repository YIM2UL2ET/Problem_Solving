sel = list(range(1,31))
for count in range(0,28):
    del sel[sel.index(int(input()))]
print(sel[0])
print(sel[1])