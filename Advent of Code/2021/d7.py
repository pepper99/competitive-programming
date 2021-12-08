def part1():
    with open('Advent of Code/2021/d7.txt') as file:
        l = [int(x) for x in file.readline().strip().split(',')]
    ans = 2000*len(l)
    for k in l:
        s = 0
        for c in l:
            s += abs(k-c)
        ans = min(s,ans)
    print(ans)
# part1()
            
def part2():
    with open('Advent of Code/2021/d7.txt') as file:
        l = [int(x) for x in file.readline().strip().split(',')]
    mean = int(sum(l)/len(l))
    ans = 1e9
    for k in range(mean-1,mean+2):
        s = 0
        for c in l:
            x = abs(k-c)
            s += (x*(x+1))//2
        ans = min(s,ans)
    print(ans)
part2()

