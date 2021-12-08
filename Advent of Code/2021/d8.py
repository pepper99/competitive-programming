def part1():
    check = [2,3,4,7]
    ans = 0
    with open('Advent of Code/2021/d8.txt') as file:
        for line in file:
            line = line.strip().split('|')
            b = line[1].strip().split(' ')
            for c in b:
                if len(c) in check: ans += 1
    print(ans)
# part1()

def deduction(a):
    ez = {1:'', 4:'', 7:'', 8:''}
    fiv_g = {}
    six_g = {}
    for x in a:
        if len(x) == 5:
            for c in x:
                if c in fiv_g: fiv_g[c] += 1
                else: fiv_g[c] = 1
        elif len(x) == 6:
            for c in x:
                if c in six_g: six_g[c] += 1
                else: six_g[c] = 1
        elif len(x) == 2: ez[1] = x
        elif len(x) == 4: ez[4] = x
        elif len(x) == 3: ez[7] = x
        elif len(x) == 7: ez[8] = x
    
    fiv_de = ''; six_de = ''; fiv_in = ''; six_in = ''
    for c in fiv_g:
        if fiv_g[c] < 3: fiv_de += c
        else: fiv_in += c
    for c in six_g:
        if six_g[c] < 3: six_de += c
        else: six_in += c
    
    translate = {}
    rev_translate = {}
    
    for c in ez[7]:
        if c not in ez[1]:
            translate[c] = 'a'
            rev_translate['a'] = c
        elif c in six_de:
            translate[c] = 'c'
            rev_translate['c'] = c
    for c in ez[4]:
        if c not in fiv_de:
            translate[c] = 'd'
            rev_translate['d'] = c
            break
    for c in fiv_de:
        if c not in ez[4]:
            translate[c] = 'e'
            rev_translate['e'] = c
            break
    for c in fiv_in:
        if c != rev_translate['a'] and c != rev_translate['d']:
            translate[c] = 'g'
            rev_translate['g'] = c
            break
    for c in ez[7]:
        if c != rev_translate['a'] and c != rev_translate['c']:
            translate[c] = 'f'
            rev_translate['f'] = c
            break
    for c in fiv_de:
        if c != rev_translate['c'] and c != rev_translate['e'] and c != rev_translate['f']:
            translate[c] = 'b'
            rev_translate['b'] = c
            break
    return translate
            
def part2():
    ans = []
    num = ['abcefg','cf','acdeg','acdfg','bcdf','abdfg','abdefg','acf','abcdefg','abcdfg'] # 6 2 5 5 4 5 6 3 7 6
    with open('Advent of Code/2021/d8.txt') as file:
        for line in file:
            a,b = [x.strip().split(' ') for x in line.strip().split('|')]
            translate = deduction(a)
            x = ''
            for s in b:
                k = ''
                for c in s: k += translate[c]
                x += str(num.index(''.join(sorted(k))))
            ans.append(int(x))
    print(sum(ans))
part2()

