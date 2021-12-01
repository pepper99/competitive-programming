l = []
with open('AoC/2021/d1.txt') as file:
    for line in file:
        l.append(int(line.strip()))

##### part 1 #####
def part1():
    global l
    prev = -1
    count = 0
    for x in l:
        if prev != -1 and prev < x: count += 1
        prev = x
    print(count)
# part1()

##### part 2 #####
def part2():
    global l
    prev = -1
    count = 0
    for i in range(2,len(l)):
        k = l[i]+l[i-1]+l[i-2]
        if prev != -1 and prev < k: count += 1
        prev = k
    print(count)
part2()
