import sys
sys.setrecursionlimit(10**6)

l = {}

def cal(de):
    x = 424242
    for c in de:
        if c == ' ':
            ch = 0
        else:
            ch = ord(c) - ord('A') + 1
        x = ((x << 5) + x) + ch
        x = x & 0x0FFFFFFF
    return x

def rec(en, de, itt, magic):
    global l
    if len(de) == len(en):
        if cal(de) == magic:
            print(de)
            return True
        return False

    if l[en[itt]] != 1:
        return rec(en, de + l[en[itt]], itt + 1, magic)
    else:
        for c in l:
            if l[c] == 1:
                l[c] = en[itt]
                l[en[itt]] = c
                ret = rec(en, de + c, itt + 1, magic)
                if ret:
                    return True
                else:
                    l[c] = 1
                    l[en[itt]] = 1


def solve():
    en = input().strip()
    de = input().strip()
    magic = int(input().strip())
    global l
    l = {' ' : ' ', 'A' : 1, 'B' : 1, 'C' : 1, 'D' : 1, 'E' : 1, 'F' : 1, 'G' : 1, 'H' : 1, 'I' : 1, 'J' : 1, 'K' : 1, 'L' : 1, 'M' : 1, 'N' : 1, 'O' : 1, 'P' : 1, 'Q' : 1, 'R' : 1, 'S' : 1, 'T' : 1, 'U' : 1, 'V' : 1, 'W' : 1, 'X' : 1, 'Y' : 1, 'Z' : 1}
    for i in range(len(de)) :
        l[de[i]] = en[i]
        l[en[i]] = de[i]
    rec(en, de, len(de), magic)


def main():
    t = int(input())
    while(t > 0):
        solve()
        t -= 1

    return 0

if __name__ == '__main__':
    main()