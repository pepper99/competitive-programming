n = int(input())
d = {}
for _ in range(n):
    s = input()
    if s in d: d[s] += 1
    else: d[s] = 1
mx = 0
s = ''
for k in d:
    if d[k] > mx:
        s = k
        mx = d[k]
print(s)