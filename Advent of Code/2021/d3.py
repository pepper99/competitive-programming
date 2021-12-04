import math
def rounding(n):
    if n - math.floor(n) < 0.5:
        return math.floor(n)
    return math.ceil(n)

def part1():
    with open('Advent of Code/2021/d3.txt') as file:
        n = 0
        l = [0 for _ in range(12)]
        for line in file:
            line = line.strip()
            for i in range(len(line)):
                l[i] += int(line[i])
            n += 1
    ep = [str(rounding(x/n)) for x in l]
    gm = [str(1-rounding(x/n)) for x in l]
    print(int(''.join(ep),2) * int(''.join(gm),2))
# part1()
            
def part2():
    x = []; y = []
    with open('Advent of Code/2021/d3.txt') as file:
        for line in file:
            line = (line.strip())
            ln = len(line)
            x.append(line)
            y.append(line)

    for i in range(ln):
        n = len(x)
        if n == 1: break
        s = sum(int(x[j][i]) for j in range(n))
        x = [k for k in x if k[i] == str(rounding(s/n))]

    for i in range(ln):
        n = len(y)
        if n == 1: break
        s = sum(int(y[j][i]) for j in range(n))
        y = [k for k in y if k[i] == str(1 - rounding(s/n))]

    print(int(x[0],2) * int(y[0],2))
part2()

