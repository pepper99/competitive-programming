import sys
sys.setrecursionlimit(100000)

def dfs(x, g, secondtime):
    if x == 'end': return 1
    count = 0
    if x.islower(): g[x][0] -= 1

    for k in g[x][1:]:
        if g[k][0] > 0:
            count += dfs(k, g, secondtime)
        elif g[k][0] == 0 and secondtime and k not in ('start','end'):
            count += dfs(k, g, False)

    if x.islower(): g[x][0] += 1
    return count

def part1():
    g = {}; node = []
    with open('Advent of Code/2021/d12.txt') as file:
        for line in file:
            a,b = line.strip().split('-')

            if a not in g:
                g[a] = [False, b]
                node.append(a)
            else:
                g[a].append(b)

            if b not in g:
                g[b] = [False, a]
                node.append(b)
            else:
                g[b].append(a)

    print(dfs('start',g,False))
    
# part1()

def part2():
    g = {}; node = []
    with open('Advent of Code/2021/d12.txt') as file:
        for line in file:
            a,b = line.strip().split('-')

            if a not in g:
                g[a] = [1, b]
                node.append(a)
            else:
                g[a].append(b)

            if b not in g:
                g[b] = [1, a]
                node.append(b)
            else:
                g[b].append(a)

    print(dfs('start',g,True))

part2()

