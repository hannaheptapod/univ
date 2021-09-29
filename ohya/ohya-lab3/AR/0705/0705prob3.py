import urllib.request
import csv
import os
url = 'https://www.data.jma.go.jp/obd/stats/data/mdrr/tem_rct/alltable/mxtemsadext01.csv'
csv_name = 'weather.csv'
urllib.request.urlretrieve(url, csv_name)
with open(csv_name, mode='r+', encoding='shift-jis', newline='') as f:
    f_list = [row for row in csv.reader(f)]
w_list = []
for row in f_list:
    try:
        w_list.append([row[1], row[2], float(row[9])])
    except Exception:
        pass
temp_ave = sum([row[2] for row in w_list]) / len(w_list)
w_dic = {}
print_list = []
min = 100
for row in w_list:
    diff = abs(row[2] - temp_ave)
    if diff < min:
        print_list.clear()
        min = diff
        print_list.append(row[0] + ' ' + row[1])
    elif diff == min:
        print_list.append(row[0] + ' ' + row[1])
print_str = '\n'.join(print_list)
print(temp_ave)
print(print_str)
os.remove(csv_name)