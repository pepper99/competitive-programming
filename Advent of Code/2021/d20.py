def CountLit(img):
    x = 0
    for line in img:
        x += sum(c == '#' for c in line)
    return x

def Process(img, alg):
    h = len(img); w = len(img[0])
    new_img = []
    for i in range(1,h-1):
        new_line = ''
        for j in range(1,w-1):
            x = int(''.join(['1' if c == '#' else '0' for c in img[i-1][j-1:j+2]] +\
                ['1' if c == '#' else '0' for c in img[i][j-1:j+2]] +\
                ['1' if c == '#' else '0' for c in img[i+1][j-1:j+2]]), 2)
            new_line += alg[x]
        # print(new_line)
        new_img.append(new_line)
    return new_img

def Padding(img, alg, orig=True):
    padding_char = '.' if orig else alg[0]
    blank_line = padding_char * (len(img[0]) + 6)
    pad = padding_char * 3
    new_img = [blank_line,blank_line,blank_line]
    for l in img:
        new_img.append(pad + l + pad)
    new_img += [blank_line,blank_line,blank_line]
    return new_img

def part1():
    with open('Advent of Code/2021/d20.txt') as file:
        alg = file.readline().strip()
        file.readline().strip() # Blank line

        img = []
        
        for line in file:
            img.append(line.strip())
            print(line.strip())
    
    img = Padding(img,alg)
    img = Process(img,alg)
    img = Padding(img,alg,orig=False)
    img = Process(img,alg)

            
    # print('\n'.join(img))
    print(f'Part 1 = {CountLit(img)}')

part1()

def part2():
    with open('Advent of Code/2021/d20.txt') as file:
        alg = file.readline().strip()
        file.readline().strip() # Blank line

        img = []
        
        for line in file:
            img.append(line.strip())
            print(line.strip())
    
    for i in range(50):
        img = Padding(img,alg,orig=(i % 2 == 0))
        img = Process(img,alg)
            
    # print('\n'.join(img))
    print(f'Part 2 = {CountLit(img)}')

part2()