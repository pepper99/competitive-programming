def part1():
    with open('Advent of Code/2021/d6.txt') as file:
        l = [int(x) for x in file.readline().strip().split(',')]
    co = {}
    for c in l:
        if c not in co: co[c] = 1
        else: co[c] += 1
    for _ in range(80):
        do = {}
        for c in co:
            if c == 0:
                if 6 in do: do[6] += co[c]
                else: do[6] = co[c]
                if 8 in do: do[8] += co[c]
                else: do[8] = co[c]
            else:
                if c-1 in do: do[c-1] += co[c]
                else: do[c-1] = co[c]
        co = do
    print(sum(co[k] for k in co))
# part1()
            
def part2():
    with open('Advent of Code/2021/d6.txt') as file:
        l = [int(x) for x in file.readline().strip().split(',')]
    co = {}
    for c in l:
        if c not in co: co[c] = 1
        else: co[c] += 1
    for _ in range(256):
        do = {}
        for c in co:
            if c == 0:
                if 6 in do: do[6] += co[c]
                else: do[6] = co[c]
                if 8 in do: do[8] += co[c]
                else: do[8] = co[c]
            else:
                if c-1 in do: do[c-1] += co[c]
                else: do[c-1] = co[c]
        co = do
    print(sum(co[k] for k in co))
part2()

