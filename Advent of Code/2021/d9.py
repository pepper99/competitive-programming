from queue import Queue

def part1():
    g = []
    ans = 0
    w, h = -1, -1
    with open('Advent of Code/2021/d9.txt') as file:
        for line in file:
            line = line.strip()
            g.append([int(x) for x in line])
    h = len(g); w = len(g[0])
    d = [(1,0),(-1,0),(0,1),(0,-1)]
    for i in range(h):
        for j in range(w):
            check = True
            for dx, dy in d:
                x,y = j+dx, i+dy
                if 0 <= y < h and 0 <= x < w:
                    check &= g[i][j] < g[y][x]
            if check:
                ans += g[i][j] + 1
    print(ans)
# part1()

def bfs(j,i,g,w,h):
    d = [(1,0),(-1,0),(0,1),(0,-1)]
    vs = []
    for _ in range(h):
        vs.append([False for _ in range(w)])
    count = 0
    q = Queue()
    q.put((j,i))
    while not q.empty():
        x,y = q.get()
        if vs[y][x] or g[y][x] == 9: continue
        count += 1
        vs[y][x] = True
        for dx, dy in d:
            nx,ny = x+dx, y+dy
            if 0 <= ny < h and 0 <= nx < w and not vs[ny][nx] and g[y][x] <= g[ny][nx]:
                q.put((nx,ny))
                
    return count

def part2():
    g = []
    w, h = -1, -1
    with open('Advent of Code/2021/d9.txt') as file:
        for line in file:
            line = line.strip()
            g.append([int(x) for x in line])
    h = len(g); w = len(g[0])
    
    d = [(1,0),(-1,0),(0,1),(0,-1)]
    sz = []
    for i in range(h):
        for j in range(w):
            check = True
            for dx, dy in d:
                x,y = j+dx, i+dy
                if 0 <= y < h and 0 <= x < w:
                    check &= g[i][j] < g[y][x]
            if check:
                sz.append(bfs(j,i,g,w,h))
    sz.sort()
    print(sz[-1] * sz[-2] * sz[-3])
part2()

