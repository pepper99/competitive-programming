def check_win(board):
    for i in range(5):
        if all(board[i][j][1] for j in range(5)): return True
        elif all(board[j][i][1] for j in range(5)): return True
    if all(board[i][i][1] for i in range(5)): return True
    elif all(board[4-i][4-i][1] for i in range(5)): return True
    return False

def cal_score(board):
    s = 0
    for row in board:
        for col in row:
            if not col[1]:
                s += col[0]
    return s

def part1():
    orders = []
    with open('Advent of Code/2021/d4.txt') as file:
        orders = [int(x) for x in file.readline().strip().split(',')]
        boards = []
        count = 0
        board_no = 0
        for line in file:
            line = line.strip()
            if count == 0:
                boards.append([])
                board_no += 1
            if count != 0:
                boards[board_no-1].append([[int(line[i:i+2]), False] for i in range(0,len(line),3)])
            count = (count + 1) % 6
    
    win = False
    for num in orders:
        if win: break
        for board in boards:
            for row in board:
                for col in row:
                    if col[0] == num: col[1] = True
            win = check_win(board)
            if win:
                print(cal_score(board) * num)
                break
# part1()
            
def part2():
    orders = []
    won = []
    with open('Advent of Code/2021/d4.txt') as file:
        orders = [int(x) for x in file.readline().strip().split(',')]
        boards = []
        count = 0
        board_no = 0
        for line in file:
            line = line.strip()
            if count == 0:
                boards.append([])
                won.append(False)
                board_no += 1
            if count != 0:
                boards[board_no-1].append([[int(line[i:i+2]), False] for i in range(0,len(line),3)])
            count = (count + 1) % 6
    
    score = 0
    for num in orders:
        for i in range(len(boards)):
            if won[i]: continue
            board = boards[i]
            for row in board:
                for col in row:
                    if col[0] == num: col[1] = True
            if check_win(board):
                score = cal_score(board) * num
                won[i] = True
    print(score)
part2()

