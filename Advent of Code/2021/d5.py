plot = [[0 for _ in range(1000)] for _ in range(1000)]

def part1():
    ans = 0
    with open('Advent of Code/2021/d5.txt') as file:
        for line in file:
            f,_,t = line.strip().split(' ')
            x1,y1 = [int(x) for x in f.split(',')]
            x2,y2 = [int(x) for x in t.split(',')]
            if x1 != x2 and y1 != y2: continue
            
            if x1 > x2: x1,x2 = x2,x1
            if y1 > y2: y1,y2 = y2,y1

            print(x1,y1,'->',x2,y2)

            for i in range(x1,x2+1):
                for j in range(y1,y2+1):
                    plot[i][j] += 1
                    if plot[i][j] == 2: ans += 1
    print(ans)
# part1()

def inc(a,b):
    if a > b: return -1
    else: return 1
            
def part2():
    ans = 0
    with open('Advent of Code/2021/d5.txt') as file:
        for line in file:
            f,_,t = line.strip().split(' ')
            x1,y1 = [int(x) for x in f.split(',')]
            x2,y2 = [int(x) for x in t.split(',')]
    
            if y1 == y2:
                if x1 > x2: x1,x2 = x2,x1
                for i in range(x1,x2+1):
                    plot[i][y1] += 1
                    if plot[i][y1] == 2: ans += 1

            elif x1 == x2:
                if y1 > y2: y1,y2 = y2,y1
                for i in range(y1,y2+1):
                    plot[x1][i] += 1
                    if plot[x1][i] == 2: ans += 1

            else:
                dx = inc(x1,x2); dy = inc(y1,y2)
                while (x1,y1) != (x2+dx,y2+dy):
                    plot[x1][y1] += 1
                    if plot[x1][y1] == 2: ans += 1
                    x1 += dx; y1 += dy
    print(ans)
part2()

