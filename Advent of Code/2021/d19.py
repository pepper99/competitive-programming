# Note.
# Brute Force with little optimization, runs around 27-30 seconds on Ryzen 3700x

import time
from itertools import product

#rotate with y axis
def Rotating(x,y,z,rot):
	if rot == 0:
		return x,y,z
	elif rot == 1:
		return z,y,-x
	elif rot == 2:
		return -x,y,-z
	else:
		return -z,y,x

def Orientating(x,y,z,axis):
	if axis == 0:
		return x,y,z
	elif axis == 1:
		return x,-y,-z
	elif axis == 2:
		return y,x,-z
	elif axis == 3:
		return y,-x,z
	elif axis == 4:
		return y,z,x
	else:
		return y,-z,-x

def Transform(x,y,z,axis,rot):
    nx,ny,nz = Orientating(x,y,z,axis)
    return Rotating(nx,ny,nz,rot)

def CheckOverlap(scanner_a, scanner_b):
    checked = set()
    dx,dy,dz = -1,-1,-1
    for ax,ay,az in scanner_a:
        for bx,by,bz in scanner_b:
            dx = ax-bx
            dy = ay-by
            dz = az-bz
            if (dx,dy,dz) in checked: continue
            new_scanner_b = set((nbx+dx,nby+dy,nbz+dz) for nbx,nby,nbz in scanner_b)
            if len(new_scanner_b & scanner_a) >= 12:
                return new_scanner_b, (dx, dy, dz)
            checked.add((dx,dy,dz))
    return None, None

def Matching(scanner_a, scanner_b):
    scanner_b_check = scanner_b
    for axis in range(6):
        for rot in range(4):
            scanner_b_check = set(Transform(x,y,z, axis, rot) for x,y,z in scanner_b)
            scanner_b_match, mx = CheckOverlap(scanner_a, scanner_b_check)
            if scanner_b_match != None:
                return scanner_b_match, mx
    return None, None

def solve():
    scanners = []
    with open('Advent of Code/2021/d19.txt') as file:
        state = 0
        for line in file:
            line = line.strip()
            if state == 0 and line.split(' ')[1] == 'scanner':
                scanners.append(set())
                state = 1
            elif state == 1:
                if line == '':
                    state = 0
                    continue
                scanners[len(scanners)-1].add(tuple(int(e) for e in line.split(',')))

    final_batch = [scanners[0]]
    okay_batch = [scanners[0]]
    check_batch = scanners[1:]
    location = [(0,0,0)]

    while len(check_batch) > 0:
        new_okay_batch = []
        for scanner_a in okay_batch:
            new_check_batch = []
            for scanner_b in check_batch:
                nb, p = Matching(scanner_a, scanner_b)
                if nb != None:
                    location.append(p)
                    new_okay_batch.append(nb)
                else:
                    new_check_batch.append(scanner_b)
            check_batch = new_check_batch
            
        final_batch += new_okay_batch
        okay_batch = new_okay_batch
        print(f'len(check_batch) = {len(check_batch)}')

    total = set()
    for s in final_batch:
        for coor in s:
            if coor not in total:
                total.add(coor)
    mx = max(abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]) for a,b in product(location, location))
            
    print('\n'.join(f'{x},{y},{z}' for x,y,z in sorted(total)))
    print(f'Part 1: {len(total)}')
    print(f'Part 2: {mx}')

t0 = time.time()
solve()
t1 = time.time()
print(f'Execution Time = {t1-t0}s')