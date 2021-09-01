def main():
    n = int(input())
    l = []
    while(n > 0):
        s = input().strip().split(' ')
        l.append((s[0], 'i'))
        l.append((s[1], 'o'))
        n -= 1
    l.sort()
    count = 0
    mx = 0
    s = ""
    i = 0
    while i < len(l):
        x = l[i][0]
        while(i < len(l) and l[i][0] == x):   
            if l[i][1] == 'i':
                count += 1
            elif l[i][1] == 'o':
                count -= 1
            i += 1
        if count > mx :
            s = x
            mx = count
    print(s)
    # print(mx)
    return 0

if __name__ == '__main__':
    main()