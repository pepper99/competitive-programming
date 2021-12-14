def part1():
    with open('Advent of Code/2021/d14.txt') as file:
        s = file.readline().strip()
        file.readline() # blank line skip
        rule = {}
        for line in file:
            a,_,b = line.strip().split(' ')
            rule[a] = b
        for _ in range(10):
            ns = []
            for i in range(1,len(s)):
                ns.append(s[i-1])
                if s[i-1:i+1] in rule: ns.append(rule[s[i-1:i+1]])
            ns.append(s[-1])
            s = ''.join(ns)
        counting = [0 for _ in range(26)]
        
        for c in s:
            idx = ord(c) - ord('A')
            counting[idx] += 1
        counting = [c for c in counting if c != 0]
        mx = max(counting)
        mn = min(counting)

        print('Part 1')
        print(mx - mn)

part1()

def part2():
    with open('Advent of Code/2021/d14.txt') as file:
        s = file.readline().strip()
        file.readline() # blank line skip
        rule = {}
        for line in file:
            a,_,b = line.strip().split(' ')
            rule[a] = b

        counting = [0 for _ in range(26)]
        match_count = {}
        for i in range(1,len(s)): # subtracting middle char
            if i != len(s) - 1:
                idx = ord(s[i]) - ord('A')
                counting[idx] -= 1
            if s[i-1:i+1] not in match_count:
                match_count[s[i-1:i+1]] = 1
            else: match_count[s[i-1:i+1]] += 1

        for _ in range(40):
            nc = {}
            for k in match_count:
                count = match_count[k]
                if k not in rule:
                    if k not in nc: nc[k] = count
                    else: nc[k] += count
                else:
                    m = rule[k]
                    ff = k[0] + m; ss = m + k[1] # NN -> NC, CN
                    
                    idx = ord(m) - ord('A')
                    counting[idx] -= count # subtracting middle char, last step will add 2 of the middle char

                    if ff not in nc: nc[ff] = count
                    else: nc[ff] += count
                    if ss not in nc: nc[ss] = count
                    else: nc[ss] += count

            match_count = nc

        for k in match_count:
            count = match_count[k]

            idx = ord(k[0]) - ord('A')
            counting[idx] += count
            
            idx = ord(k[1]) - ord('A')
            counting[idx] += count
            
        counting = [c for c in counting if c != 0]
        mx = max(counting)
        mn = min(counting)
        
        print('Part 2')
        print(mx - mn)

part2()

