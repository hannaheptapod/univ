import colorsys

def dist(hsv):
    # Hを30, 90, 150, 210, 270, 330度で6等分し，色を名付ける
    c_name = ['赤', '黄', '緑', 'シアン', '青', 'マゼンタ']
    color = c_name[round(hsv[0]*6) % 6]
    # Sが小さい場合は，Vの値によって白かグレーと名付ける
    if hsv[1] < 1/12:
        if hsv[2] >= 300:
            color = '白'
        elif hsv[2] >= 60:
            color = 'グレー'
    # Vが小さい場合は黒と名付ける
    if hsv[2] < 60:
        color = '黒'
    return color

def color():
    # (R, G, B)を入力してHSVに変換
    rgb = tuple(int(input(f'{i}を入力:')) for i in ['R', 'G', 'B'])
    hsv = colorsys.rgb_to_hsv(*rgb)
    # 色を識別
    color = dist(hsv)
    # 識別結果を表示
    print(f'{rgb}は{color}に近いです．')

color()