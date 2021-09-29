crosses = [
    [[1, 2, 3, 4, 5, 6, 7], [], [], [], [], [], [8, 16, 24, 32, 40, 48, 56], [9, 18, 27, 36, 45, 54, 63]],
    [[2, 3, 4, 5, 6, 7], [], [], [], [0], [8], [9, 17, 25, 33, 41, 49, 57], [10, 19, 28, 37, 46, 55]],
    [[3, 4, 5, 6, 7], [], [], [], [1, 0], [9, 16], [10, 18, 26, 34, 42, 50, 58], [11, 20, 29, 38, 47]],
    [[4, 5, 6, 7], [], [], [], [2, 1, 0], [10, 17, 24], [11, 19, 27, 35, 43, 51, 59], [12, 21, 30, 39]],
    [[5, 6, 7], [], [], [], [3, 2, 1, 0], [11, 18, 25, 32], [12, 20, 28, 36, 44, 52, 60], [13, 22, 31]],
    [[6, 7], [], [], [], [4, 3, 2, 1, 0], [12, 19, 26, 33, 40], [13, 21, 29, 37, 45, 53, 61], [14, 23]],
    [[7], [], [], [], [5, 4, 3, 2, 1, 0], [13, 20, 27, 34, 41, 48], [14, 22, 30, 38, 46, 54, 62], [15]],
    [[], [], [], [], [6, 5, 4, 3, 2, 1, 0], [14, 21, 28, 35, 42, 49, 56], [15, 23, 31, 39, 47, 55, 63], []],
    [[9, 10, 11, 12, 13, 14, 15], [1], [0], [], [], [], [16, 24, 32, 40, 48, 56], [17, 26, 35, 44, 53, 62]],
    [[10, 11, 12, 13, 14, 15], [2], [1], [0], [8], [16], [17, 25, 33, 41, 49, 57], [18, 27, 36, 45, 54, 63]],
    [[11, 12, 13, 14, 15], [3], [2], [1], [9, 8], [17, 24], [18, 26, 34, 42, 50, 58], [19, 28, 37, 46, 55]],
    [[12, 13, 14, 15], [4], [3], [2], [10, 9, 8], [18, 25, 32], [19, 27, 35, 43, 51, 59], [20, 29, 38, 47]],
    [[13, 14, 15], [5], [4], [3], [11, 10, 9, 8], [19, 26, 33, 40], [20, 28, 36, 44, 52, 60], [21, 30, 39]],
    [[14, 15], [6], [5], [4], [12, 11, 10, 9, 8], [20, 27, 34, 41, 48], [21, 29, 37, 45, 53, 61], [22, 31]],
    [[15], [7], [6], [5], [13, 12, 11, 10, 9, 8], [21, 28, 35, 42, 49, 56], [22, 30, 38, 46, 54, 62], [23]],
    [[], [], [7], [6], [14, 13, 12, 11, 10, 9, 8], [22, 29, 36, 43, 50, 57], [23, 31, 39, 47, 55, 63], []],
    [[17, 18, 19, 20, 21, 22, 23], [9, 2], [8, 0], [], [], [], [24, 32, 40, 48, 56], [25, 34, 43, 52, 61]],
    [[18, 19, 20, 21, 22, 23], [10, 3], [9, 1], [8], [16], [24], [25, 33, 41, 49, 57], [26, 35, 44, 53, 62]],
    [[19, 20, 21, 22, 23], [11, 4], [10, 2], [9, 0], [17, 16], [25, 32], [26, 34, 42, 50, 58], [27, 36, 45, 54, 63]],
    [[20, 21, 22, 23], [12, 5], [11, 3], [10, 1], [18, 17, 16], [26, 33, 40], [27, 35, 43, 51, 59], [28, 37, 46, 55]],
    [[21, 22, 23], [13, 6], [12, 4], [11, 2], [19, 18, 17, 16], [27, 34, 41, 48], [28, 36, 44, 52, 60], [29, 38, 47]],
    [[22, 23], [14, 7], [13, 5], [12, 3], [20, 19, 18, 17, 16], [28, 35, 42, 49, 56], [29, 37, 45, 53, 61], [30, 39]],
    [[23], [15], [14, 6], [13, 4], [21, 20, 19, 18, 17, 16], [29, 36, 43, 50, 57], [30, 38, 46, 54, 62], [31]],
    [[], [], [15, 7], [14, 5], [22, 21, 20, 19, 18, 17, 16], [30, 37, 44, 51, 58], [31, 39, 47, 55, 63], []],
    [[25, 26, 27, 28, 29, 30, 31], [17, 10, 3], [16, 8, 0], [], [], [], [32, 40, 48, 56], [33, 42, 51, 60]],
    [[26, 27, 28, 29, 30, 31], [18, 11, 4], [17, 9, 1], [16], [24], [32], [33, 41, 49, 57], [34, 43, 52, 61]],
    [[27, 28, 29, 30, 31], [19, 12, 5], [18, 10, 2], [17, 8], [25, 24], [33, 40], [34, 42, 50, 58], [35, 44, 53, 62]],
    [[28, 29, 30, 31], [20, 13, 6], [19, 11, 3], [18, 9, 0], [26, 25, 24], [34, 41, 48], [35, 43, 51, 59], [36, 45, 54, 63]],
    [[29, 30, 31], [21, 14, 7], [20, 12, 4], [19, 10, 1], [27, 26, 25, 24], [35, 42, 49, 56], [36, 44, 52, 60], [37, 46, 55]],
    [[30, 31], [22, 15], [21, 13, 5], [20, 11, 2], [28, 27, 26, 25, 24], [36, 43, 50, 57], [37, 45, 53, 61], [38, 47]],
    [[31], [23], [22, 14, 6], [21, 12, 3], [29, 28, 27, 26, 25, 24], [37, 44, 51, 58], [38, 46, 54, 62], [39]],
    [[], [], [23, 15, 7], [22, 13, 4], [30, 29, 28, 27, 26, 25, 24], [38, 45, 52, 59], [39, 47, 55, 63], []],
    [[33, 34, 35, 36, 37, 38, 39], [25, 18, 11, 4], [24, 16, 8, 0], [], [], [], [40, 48, 56], [41, 50, 59]],
    [[34, 35, 36, 37, 38, 39], [26, 19, 12, 5], [25, 17, 9, 1], [24], [32], [40], [41, 49, 57], [42, 51, 60]],
    [[35, 36, 37, 38, 39], [27, 20, 13, 6], [26, 18, 10, 2], [25, 16], [33, 32], [41, 48], [42, 50, 58], [43, 52, 61]],
    [[36, 37, 38, 39], [28, 21, 14, 7], [27, 19, 11, 3], [26, 17, 8], [34, 33, 32], [42, 49, 56], [43, 51, 59], [44, 53, 62]],
    [[37, 38, 39], [29, 22, 15], [28, 20, 12, 4], [27, 18, 9, 0], [35, 34, 33, 32], [43, 50, 57], [44, 52, 60], [45, 54, 63]],
    [[38, 39], [30, 23], [29, 21, 13, 5], [28, 19, 10, 1], [36, 35, 34, 33, 32], [44, 51, 58], [45, 53, 61], [46, 55]],
    [[39], [31], [30, 22, 14, 6], [29, 20, 11, 2], [37, 36, 35, 34, 33, 32], [45, 52, 59], [46, 54, 62], [47]],
    [[], [], [31, 23, 15, 7], [30, 21, 12, 3], [38, 37, 36, 35, 34, 33, 32], [46, 53, 60], [47, 55, 63], []],
    [[41, 42, 43, 44, 45, 46, 47], [33, 26, 19, 12, 5], [32, 24, 16, 8, 0], [], [], [], [48, 56], [49, 58]],
    [[42, 43, 44, 45, 46, 47], [34, 27, 20, 13, 6], [33, 25, 17, 9, 1], [32], [40], [48], [49, 57], [50, 59]],
    [[43, 44, 45, 46, 47], [35, 28, 21, 14, 7], [34, 26, 18, 10, 2], [33, 24], [41, 40], [49, 56], [50, 58], [51, 60]],
    [[44, 45, 46, 47], [36, 29, 22, 15], [35, 27, 19, 11, 3], [34, 25, 16], [42, 41, 40], [50, 57], [51, 59], [52, 61]],
    [[45, 46, 47], [37, 30, 23], [36, 28, 20, 12, 4], [35, 26, 17, 8], [43, 42, 41, 40], [51, 58], [52, 60], [53, 62]],
    [[46, 47], [38, 31], [37, 29, 21, 13, 5], [36, 27, 18, 9, 0], [44, 43, 42, 41, 40], [52, 59], [53, 61], [54, 63]],
    [[47], [39], [38, 30, 22, 14, 6], [37, 28, 19, 10, 1], [45, 44, 43, 42, 41, 40], [53, 60], [54, 62], [55]],
    [[], [], [39, 31, 23, 15, 7], [38, 29, 20, 11, 2], [46, 45, 44, 43, 42, 41, 40], [54, 61], [55, 63], []],
    [[49, 50, 51, 52, 53, 54, 55], [41, 34, 27, 20, 13, 6], [40, 32, 24, 16, 8, 0], [], [], [], [56], [57]],
    [[50, 51, 52, 53, 54, 55], [42, 35, 28, 21, 14, 7], [41, 33, 25, 17, 9, 1], [40], [48], [56], [57], [58]],
    [[51, 52, 53, 54, 55], [43, 36, 29, 22, 15], [42, 34, 26, 18, 10, 2], [41, 32], [49, 48], [57], [58], [59]],
    [[52, 53, 54, 55], [44, 37, 30, 23], [43, 35, 27, 19, 11, 3], [42, 33, 24], [50, 49, 48], [58], [59], [60]],
    [[53, 54, 55], [45, 38, 31], [44, 36, 28, 20, 12, 4], [43, 34, 25, 16], [51, 50, 49, 48], [59], [60], [61]],
    [[54, 55], [46, 39], [45, 37, 29, 21, 13, 5], [44, 35, 26, 17, 8], [52, 51, 50, 49, 48], [60], [61], [62]],
    [[55], [47], [46, 38, 30, 22, 14, 6], [45, 36, 27, 18, 9, 0], [53, 52, 51, 50, 49, 48], [61], [62], [63]],
    [[], [], [47, 39, 31, 23, 15, 7], [46, 37, 28, 19, 10, 1], [54, 53, 52, 51, 50, 49, 48], [62], [63], []],
    [[57, 58, 59, 60, 61, 62, 63], [49, 42, 35, 28, 21, 14, 7], [48, 40, 32, 24, 16, 8, 0], [], [], [], [], []],
    [[58, 59, 60, 61, 62, 63], [50, 43, 36, 29, 22, 15], [49, 41, 33, 25, 17, 9, 1], [48], [56], [], [], []],
    [[59, 60, 61, 62, 63], [51, 44, 37, 30, 23], [50, 42, 34, 26, 18, 10, 2], [49, 40], [57, 56], [], [], []],
    [[60, 61, 62, 63], [52, 45, 38, 31], [51, 43, 35, 27, 19, 11, 3], [50, 41, 32], [58, 57, 56], [], [], []],
    [[61, 62, 63], [53, 46, 39], [52, 44, 36, 28, 20, 12, 4], [51, 42, 33, 24], [59, 58, 57, 56], [], [], []],
    [[62, 63], [54, 47], [53, 45, 37, 29, 21, 13, 5], [52, 43, 34, 25, 16], [60, 59, 58, 57, 56], [], [], []],
    [[63], [55], [54, 46, 38, 30, 22, 14, 6], [53, 44, 35, 26, 17, 8], [61, 60, 59, 58, 57, 56], [], [], []],
    [[], [], [55, 47, 39, 31, 23, 15, 7], [54, 45, 36, 27, 18, 9, 0], [62, 61, 60, 59, 58, 57, 56], [], [], []]
]
board = [2]*64
board[27] = board[36] = 0
board[28] = board[35] = 1
stone = ('●', '○', '-')
def num_to_stone(num):
    return stone[num]
def print_board():
    for i in range(0, 64, 8): print(*list(map(num_to_stone, board[i:i+8])))
def where_can(color):
    can = [[x] for x in range(64)]
    if color: oppo = 0
    else: oppo = 1
    for x in range(64):
        if board[x] == 2:
            cross = crosses[x]
            lines = make_lines(cross)
            for i in range(8):
                line = lines[i]
                size = len(line)
                tmp = []
                if size < 2: continue
                else:
                    for j in range(size):
                        if line[j] == oppo:
                            tmp.append(cross[i][j])
                        else:
                            if line[j] == color:
                                can[x] += tmp
                            break
    return can
def make_lines(cross):
    lines = [[board[xi] for xi in cross[i]] for i in range(8)]
    return lines

def AI(color, type):
    def turn(ci):
        for cij in ci: board[cij] = color
    if type == 0: #greed
        can = where_can(color)
        tmp = []
        tmp_n = 0
        for ci in can:
            if len(ci) > tmp_n:
                tmp = ci
                tmp_n = len(ci)
        if tmp_n > 1:
            turn(tmp)
    if type == 1: #fool
        can = where_can(color)
        for ci in can:
            if len(ci) > 1:
                turn(ci)
                break
def play_game():
    print('Init:')
    print_board()
    for turn in range(64):
        AI(turn%2, 1)
        print('Turn', turn, ':')
        print_board()

play_game()