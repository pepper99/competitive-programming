def part1():
    scoring = {')':3, ']':57, '}':1197, '>':25137}
    match = {'(':')', '[':']', '{':'}', '<':'>'}
    ans = 0
    with open('Advent of Code/2021/d10.txt') as file:
        for line in file:
            line = line.strip()
            q = []
            for c in line:
                if c in '[{(<': q.append(c)
                else:
                    x = q.pop()
                    if match[x] != c:
                        ans += scoring[c]
                        break
    print(ans)
# part1()

def part2():
    scoring = {')':1, ']':2, '}':3, '>':4}
    match = {'(':')', '[':']', '{':'}', '<':'>'}
    all_score = []
    with open('Advent of Code/2021/d10.txt') as file:
        for line in file:
            line = line.strip()
            q = []
            illegal = False
            for c in line:
                if c in '[{(<': q.append(c)
                else:
                    x = q.pop()
                    if match[x] != c:
                        illegal = True
                        break
            if illegal: continue
            
            score = 0
            for c in q[::-1]:
                score = (score * 5) + scoring[match[c]]
            all_score.append(score)

    all_score.sort()
    print(all_score[len(all_score)//2])
part2()

