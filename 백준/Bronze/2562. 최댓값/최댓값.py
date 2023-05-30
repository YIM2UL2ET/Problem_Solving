sel = []
for i in range(0,9):
    sel.append(int(input()))
print(max(sel))
print(sel.index(max(sel)) +1)