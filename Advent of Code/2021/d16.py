from functools import reduce
import operator

def decypher(s, pt):
    return_data = {}
    version = int(s[pt:pt+3],2)
    version_sum = version
    typeId = int(s[pt+3:pt+6],2)
    return_data['version'] = version
    return_data['typeID'] = typeId
    pt += 6
    
    if typeId == 4:
        val = ''
        while True:
            val += s[pt+1:pt+5]
            if s[pt] == '0':
                pt += 5
                break
            pt += 5
        return_data['val'] = int(val,2)
    else:
        lengthTypeId = s[pt]
        pt += 1
        return_data['sub'] = []
        if lengthTypeId == '0':
            cur = 0
            length = int(s[pt:pt+15],2)
            pt += 15
            while cur < length:
                data, new_pt, new_sum = decypher(s, pt)
                cur += new_pt - pt
                pt = new_pt
                return_data['sub'].append(data)
                version_sum += new_sum
        else:
            cur = 0
            length = int(s[pt:pt+11],2)
            pt += 11
            while cur < length:
                data, pt, new_sum = decypher(s, pt)
                cur += 1
                return_data['sub'].append(data)
                version_sum += new_sum
        if typeId == 0:
            return_data['val'] = sum(x['val'] for x in return_data['sub'])
        elif typeId == 1:
            return_data['val'] = reduce(operator.mul, [x['val'] for x in return_data['sub']])
        elif typeId == 2:
            return_data['val'] = min(x['val'] for x in return_data['sub'])
        elif typeId == 3:
            return_data['val'] = max(x['val'] for x in return_data['sub'])
        elif typeId == 5:
            return_data['val'] = int(return_data['sub'][0]['val'] > return_data['sub'][1]['val'])
        elif typeId == 6:
            return_data['val'] = int(return_data['sub'][0]['val'] < return_data['sub'][1]['val'])
        elif typeId == 7:
            return_data['val'] = int(return_data['sub'][0]['val'] == return_data['sub'][1]['val'])

    return return_data, pt, version_sum


def part1():
    with open('Advent of Code/2021/d16.txt') as file:
        s = ''.join(bin(int(h, 16))[2:].zfill(4) for h in file.readline().strip())
    print('Part 1')
    _, _, version_sum = decypher(s,0)
    print(f'ans = {version_sum}')

part1()

def part2():
    with open('Advent of Code/2021/d16.txt') as file:
        s = ''.join(bin(int(h, 16))[2:].zfill(4) for h in file.readline().strip())
    print('Part 2')
    data, _, _ = decypher(s,0)
    print(f'ans = {data["val"]}')

part2()