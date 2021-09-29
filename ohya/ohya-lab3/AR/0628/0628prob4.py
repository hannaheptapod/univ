from random import shuffle

def print_card(n, hands):
    # カードの数字の辞書
    dic_num = {0: 'A', 10: 'J', 11: 'Q', 12: 'K'}
    for i in range(1, 10):
        dic_num[i] = str(i + 1)
    # カードのスートの辞書
    dic_suit = {0: '\u2660', 1: '\u2661', 2: '\u2662', 3: '\u2663'}
    # カードの数字とスートを合わせた辞書
    dic_card = {}
    for i in range(52):
        dic_card[i] = dic_num[i // 4].ljust(2) + dic_suit[i % 4]
    # n人分のカードを表示
    hands_cards = [[dic_card[j] for j in hands[i]] for i in range(n)]
    [print(f'{str(i + 1).rjust(2)}: {hands_cards[i]}') for i in range(n)]

def dealer(n):
    # カードに0〜51までの通し番号を付け，リストにしたものをシャッフル
    deck = list(range(52))
    shuffle(deck)
    # n人分の手札を，順番に配ってリストに格納
    hands = [sorted([deck[j] for j in range(i, 52, n)]) for i in range(n)]
    # カードを表示する
    print_card(n, hands)

n = int(input('nを入力:'))
dealer(n)