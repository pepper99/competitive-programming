def part1():
    with open('Advent of Code/2021/d13.txt') as file:
        points = set()
        for line in file:
            line = line.strip()
            if line == '':
                break
            x,y = [int(k) for k in line.split(',')]
            points.add((x,y))
        axis, k = file.readline().strip().split(' ')[2].split('=')
        k = int(k)
        l = []
        if axis == 'x':
            for x,y in points:
                if x > k:
                    l.append((k-x+k,y))
                else:
                    l.append((x,y))
        else:
            for x,y in points:
                if y > k:
                    l.append((x,k-y+k))
                else:
                    l.append((x,y))
        points = set(l)
        
        print(len(points))

# part1()

def part2():
    with open('Advent of Code/2021/d13.txt') as file:
        points = set()
        for line in file:
            line = line.strip()
            if line == '':
                break
            x,y = [int(k) for k in line.split(',')]
            points.add((x,y))
        for line in file:
            axis, k = line.strip().split(' ')[2].split('=')
            k = int(k)
            remove_list = []
            add_list = []
            tl = [2000,2000]; br = [0,0]
            if axis == 'x':
                for x,y in points:
                    if x > k:
                        remove_list.append((x,y))
                        add_list.append((k-x+k,y))
                        p = (k-x+k,y)
                    else:
                        p = (x,y)
                    tl = [min(tl[0], p[0]), min(tl[1], p[1])]
                    br = [max(br[0], p[0]), max(br[1], p[1])]
            else:
                for x,y in points:
                    if y > k:
                        remove_list.append((x,y))
                        add_list.append((x,k-y+k))
                        p = (x,k-y+k)
                    else:
                        p = (x,y)
                    tl = [min(tl[0], p[0]), min(tl[1], p[1])]
                    br = [max(br[0], p[0]), max(br[1], p[1])]
            for p in remove_list:
                points.remove(p)
            for p in add_list:
                points.add(p)

        g = [['.' for _ in range(tl[0], tl[0]+br[0]+1)] for _ in range(tl[1], tl[1]+br[1]+1)]
        for x,y in points:
            g[y][x] = '#'
        for l in g:
            print(''.join(l))

part2()

