from random import randrange

name = {0:'グー', 1:'チョキ', 2:'パー'}
# "Cognitive Complexity"が大きいと怒られたのでいくつかの関数に細かく分割
def rsp(n):
    # CPUの名簿(0~n-1の通し番号)
    cpu_remains = list(range(n))
    turn, num_remains = 0, n
    # 残り人数が1人になるまでジャンケンをループ
    while(num_remains > 1):
        turn += 1
        # 敗者の番号を入れるリスト
        loser = []
        # CPUの番号とランダム生成した手を対応させる辞書
        hands_cpu = make_hands(cpu_remains)
        # 決勝手
        hand_winner = 0
        # ジャンケンの結果を表示
        hands_show(cpu_remains, hands_cpu, turn)
        # グー，チョキ，パーの出た数を数えるリスト
        num_hands = [list(hands_cpu.values()).count(i) for i in range(3)]
        # あいこを判定してTrueならcontinue
        if is_draw(num_hands, num_remains):
            continue
        # 敗者を判定
        loser = is_lost(num_hands, cpu_remains, hands_cpu)
        # 敗者の番号をCPUの名簿から削除
        for i in loser:
            cpu_remains.remove(i)
            num_remains -= 1
        # 決勝手を記録
        if num_remains == 1:
            hand_winner = hands_cpu[cpu_remains[0]]
    # 最終結果を表示
    show_result(turn, cpu_remains[0], hand_winner)

def make_hands(cpu_remains):
    dic = {}
    for i in cpu_remains:
        dic[i] = randrange(3)
    return dic

def hands_show(cpu_remains, hands_cpu, turn):
    dic = {}
    for i in cpu_remains:
        dic[i] = name[hands_cpu[i]]
    print(f'{str(turn).rjust(2)}: {dic}')

def is_draw(num_hands, num_remains):
    return any([num_hands[i] == num_remains for i in range(3)]) or all([num_hands[i] != 0 for i in range(3)])

def is_lost(num_hands, cpu_remains, hands_cpu):
    loser = []
    for i in cpu_remains:
            if any(num_hands[j] == 0 and hands_cpu[i] == (j - 1) % 3 for j in range(3)):
                loser.append(i)
    return loser

def show_result(turn, winner, hand):
    print(f'{turn}回目で{winner}が{name[hand]}で勝利しました．')

n = int(input('nを入力:'))
rsp(n)