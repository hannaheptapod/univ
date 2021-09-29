from random import random
from datetime import datetime as dt
# datetimeで扱う時間のフォーマット
time_format = '%Y%m%d %H:%M:%S'
# 結果として表示する日付のフォーマット
date_format = '%Y年%m月%d日'

def pick_date(s_time, e_time):
    # 開始時間と終了時間のあいだにあるランダムな時間を表示
    p_time = s_time + random() * (e_time - s_time)
    print(dt.strftime(p_time, date_format))

s_time = dt.strptime(input('start_dateを入力(YYYYMMDD):')+ ' 00:00:00', time_format)
e_time = dt.strptime(input('end_dateを入力(YYYYMMDD):')+ ' 23:59:59', time_format)
pick_date(s_time, e_time)