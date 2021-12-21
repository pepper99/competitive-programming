import sys
import time
sys.setrecursionlimit(100000)

class Player:
    def __init__(self, pos=0) -> None:
        self.pos = pos
        self.score = 0
    
    def move(self, number):
        self.pos = (self.pos + number) % 10
        return self

    def scoring(self):
        self.score += self.pos + 1
        return self
    
    def won(self, winning_score):
        return self.score >= winning_score

def part1():
    with open('Advent of Code/2021/d21.txt') as file:
        p1 = int(file.readline().strip().split(':')[1]) - 1
        p2 = int(file.readline().strip().split(':')[1]) - 1

    P1 = Player(p1)
    P2 = Player(p2)
    dice = 0
    roll = 0

    while True:
        P1.move(dice + ((dice + 1) % 100) + ((dice + 2) % 100) + 3).scoring()
        dice = (dice + 3) % 100
        roll += 3
        if P1.won(1000):
            break
        
        P2.move(dice + ((dice + 1) % 100) + ((dice + 2) % 100) + 3).scoring()
        dice = (dice + 3) % 100
        roll += 3
        if P2.won(1000):
            break
    
    print(f'Part 1 = {roll * (P1.score if P1.score < P2.score else P2.score)}')

states = {}

def Play(p1_pos, p1_score, p2_pos, p2_score, toss_count, toss_sum):
    global states
    state = (p1_pos, p1_score, p2_pos, p2_score, toss_count, toss_sum)
    if state in states:
        return states[state]

    if toss_count > 0 and toss_count % 3 == 0:
        if toss_count % 2 == 1:
            p1_pos = (p1_pos + toss_sum) % 10
            p1_score += p1_pos + 1
        else:
            p2_pos = (p2_pos + toss_sum) % 10
            p2_score += p2_pos + 1
        toss_sum = 0

    if p1_score >= 21:
        ans = (1,0)
    elif p2_score >= 21:
        ans = (0,1)
    else:
        x,y = 0,0
        for c in range(1,4):
            a,b = Play(p1_pos, p1_score, p2_pos, p2_score, toss_count + 1, toss_sum + c)
            x += a; y += b
        ans = (x,y)
    states[state] = ans
    return ans

def part2():
    with open('Advent of Code/2021/d21.txt') as file:
        p1_pos = int(file.readline().strip().split(':')[1]) - 1
        p2_pos = int(file.readline().strip().split(':')[1]) - 1
    a,b = Play(p1_pos, 0, p2_pos, 0, 0, 0)

    print(f'Part 2 = {max(a,b)}')


t0 = time.time()
part1()
part2()
t1 = time.time()
print(f'Execution Time = {t1-t0}s')