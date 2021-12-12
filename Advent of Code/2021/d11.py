def surround(g, flash, i, j, h, w):
    count = 1
    flash[i][j] = True
    d = [(1,0),(-1,0),(0,1),(0,-1),(1,-1),(1,1),(-1,1),(-1,-1)]
    for dx,dy in d:
        x = dx + j; y = dy + i
        if 0 <= y < h and 0 <= x < w and g[y][x] != 0:
            g[y][x] = (g[y][x] + 1) % 10
            if not flash[y][x] and g[y][x] == 0:
                count += surround(g,flash,y,x,h,w)
    return count

def part1():
    g = []; flash = []
    with open('Advent of Code/2021/d11.txt') as file:
        for line in file:
            g.append([int(x) for x in line.strip()])
            flash.append([False for _ in range(len(g[0]))])
    h = len(g); w = len(g[0])

    ans = 0
    for _ in range(100):
        for i in range(h):
            for j in range(w):
                g[i][j] = (g[i][j] + 1) % 10
                flash[i][j] = False
        for i in range(h):
            for j in range(w):
                if g[i][j] == 0 and not flash[i][j]:
                    ans += surround(g,flash,i,j,h,w)
    print(ans)
        
# part1()

def part2():
    g = []; flash = []
    with open('Advent of Code/2021/d11.txt') as file:
        for line in file:
            g.append([int(x) for x in line.strip()])
            flash.append([False for _ in range(len(g[0]))])
    h = len(g); w = len(g[0])

    r = 1
    while True:
        for i in range(h):
            for j in range(w):
                g[i][j] = (g[i][j] + 1) % 10
                flash[i][j] = False
        current = 0
        for i in range(h):
            for j in range(w):
                if g[i][j] == 0 and not flash[i][j]:
                    current += surround(g,flash,i,j,h,w)
        if current == h*w:
            print(r)
            break
        r += 1
part2()

