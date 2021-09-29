import glob
import os
import sys
import shutil

args = sys.argv
path = args[1]
n = int(args[2])
f_name = args[3]
f_list = [os.path.split(f) for f in sorted(glob.glob(path + '/' + '*.txt'))]
path_to = []
result = []

for i in range(n):
    # 修正前
    """
    os.mkdir(path + str(i) + ' mod n')
    path_to.append(path + str(i) + ' mod n')
    """
    # 修正後
    os.mkdir(path + '/' + str(i) + ' mod n')
    path_to.append(path + '/' + str(i) + ' mod n')
    
for i in range(len(f_list)):
    path_from = f_list[i][0] + '/' + f_list[i][1]

    with open(path_from, mode='r', encoding='utf-8') as f:
        num_sum = 0

        for l in f.readline():
            try:
                num_sum += int(l)
            except Exception:
                continue
        
        result.append(f_list[i][1] + ' -> ' + str(num_sum % n) + ' mod n\n')
        shutil.move(path_from, path_to[num_sum % n])

with open(path + '/' + f_name, mode='w', encoding='utf-8') as f:
    f.writelines(result)

print('fin.')