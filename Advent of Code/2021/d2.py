def part1():
    with open('Advent of Code/2021/d2.txt') as file:
        x,y = 0,0
        for line in file:
            act,val = line.strip().split(' ')
            if act == 'forward':
                x += int(val)
            elif act == 'down':
                y += int(val)
            elif act == 'up':
                y -= int(val)
    print(f'x = {x}, y = {y}')
    print(x*y)
# part1()
            
def part2():
    with open('Advent of Code/2021/d2.txt') as file:
        x,y,a = 0,0,0
        for line in file:
            act,val = line.strip().split(' ')
            if act == 'forward':
                x += int(val)
                y += a*int(val)
            elif act == 'down':
                a += int(val)
            elif act == 'up':
                a -= int(val)
    print(f'x = {x}, y = {y}')
    print(x*y)
part2()

