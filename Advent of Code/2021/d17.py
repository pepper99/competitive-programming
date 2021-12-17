def part1():
    with open('Advent of Code/2021/d17.txt') as file:
        s = file.readline().strip()
        x,y = s[s.find('x'):].split(', ')
        xmin, xmax = (int(k) for k in x[2:].split('..'))
        ymin, ymax = (int(k) for k in y[2:].split('..'))

    if ymin <= 0:
        ans = (ymin+1)*ymin//2
    print('Part 1')
    print(f'ans = {ans}')

part1()

def part2():
    with open('Advent of Code/2021/d17.txt') as file:
        s = file.readline().strip()
        x,y = s[s.find('x'):].split(', ')
        xmin, xmax = (int(k) for k in x[2:].split('..'))
        ymin, ymax = (int(k) for k in y[2:].split('..'))

    xmin = abs(xmin)
    xmax = abs(xmax)
    if xmin > xmax: xmin, xmax = xmax, xmin
    
    start = []
    for sx in range(1, xmax+1):
        for sy in range(ymin, max(abs(ymin), abs(ymax))+1):
            x = 0; y = 0
            dx = sx; dy = sy
            okay = False
            while y >= ymin and x <= xmax:
                x += dx; y += dy
                if dx > 0: dx -= 1
                dy -= 1
                if ymin <= y <= ymax and xmin <= x <= xmax:
                    okay = True
                    break
            if okay: start.append((sx,sy))
            
    print('Part 2')
    print(f'ans = {len(start)}')

part2()