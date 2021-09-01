import sys
sys.setrecursionlimit(10**6)

ans = []

def dfs(ns, g, x, check):
    ck = False
    has = False
    if x in check :
        ck = True
    for a in g[x]:
        k = dfs(ns, g, a, check)
        if ck and k:
            ck = False
            has = True
        elif k:
            has = True
    if ck and x not in ans:
        ans.append(x)
    return ck or has

def solve():
    g = {}
    ns = []

    s = input().strip().split(' ')
    n = int(s[0])
    for i in range(1, n + 1):
        g[s[i]] = []
        ns.append(s[i])

    s = input().strip().split(' ')
    k = int(s[0])
    for i in range(1, k + 1):
        a, b = s[i].split(',')
        g[a].append(b)

    t = int(input().strip())
    for i in range(t):
        s = input().strip().split(' ')
        m = int(s[0])
        check = {}
        for j in range(1, m + 1):
            check[s[j]] = 1
        global ans
        ans = []
        dfs(ns, g, ns[0], check)
        print(len(ans), ' '.join(ans))

def main():
    t = int(input())
    while(t > 0):
        solve()
        t -= 1

    return 0

if __name__ == '__main__':
    main()