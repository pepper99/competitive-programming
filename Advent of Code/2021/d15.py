import heapq

def dijkstra(g,h,w,ty,tx):
    vs = [[-1 for _ in range(w)] for _ in range(h)]
    q = [(0,0,0)]
    heapq.heapify(q)
    dr = [(1,0),(-1,0),(0,1),(0,-1)]

    while len(q) > 0:
        d,y,x = heapq.heappop(q)
        if vs[y][x] != -1 and vs[y][x] <= d: continue
        vs[y][x] = d

        for dx, dy in dr:
            nx,ny = x+dx, y+dy
            if 0 <= ny < h and 0 <= nx < w and (vs[ny][nx] == -1 or vs[ny][nx] > d + g[ny][nx]):
                heapq.heappush(q,(d + g[ny][nx],ny,nx))
    return vs[ty][tx]


def part1():
    g = []
    with open('Advent of Code/2021/d15.txt') as file:
        for line in file:
            g.append([int(x) for x in line.strip()])
    h = len(g); w = len(g[0])

    print('Part 1')
    print(dijkstra(g,h,w,h-1,w-1))

part1()

def part2():
    gt = []
    with open('Advent of Code/2021/d15.txt') as file:
        for line in file:
            gt.append([int(x) for x in line.strip()])
    h = len(gt); w = len(gt[0])

    g = [[0 for _ in range(w*5)] for _ in range(h*5)]
    for i in range(h):
        for j in range(w):
            for y in range(5):
                for x in range(5):
                    k = gt[i][j] + x + y
                    g[h*y+i][w*x+j] = k - (9 * (k//10))

    h *= 5; w *= 5

    print('Part 2')
    print(dijkstra(g,h,w,h-1,w-1))

part2()