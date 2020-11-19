""" 
    doc file text 
        """
# duong dan file 
file_path_num_word = "/media/trannguyenhan01092000/LEARN/data_training/phan_loai_van_ban/num_word_in_label.txt"
file_path_works = "/media/trannguyenhan01092000/LEARN/data_training/phan_loai_van_ban/words_in_label.txt"

# doc file
read_file_num_work = open(file_path_num_word, 'r', encoding = 'utf-8')
num_work = read_file_num_work.read()
read_file_works = open(file_path_works, 'r', encoding = 'utf-8')
works = read_file_works.read()


""" 
    doc du lieu tu 2 file gan vao cho cac bien 
        """
###----- file num_work -----###
foo = num_work.split('\n')

# work_list[i] : chua tu thu i
# number_work_list la 1 ma tran 2 chieu
# number_work_list[i][j] : so tu work_list[i] xuat hien trong van ban loai j
work_list = []
number_work_list = [] 
total = 0
for x in foo:
    # bo di dong cuoi cung
    if x == '':
        break

    tmp1 = x.split(" ",1)
    work_list.append(tmp1[0])
    
    tmp2 = tmp1[1].split(" ")
    tmp2.remove('') # bo di phan tu cuoi cung
    number_work_list.append([])
    number_work_list[total] = tmp2
    total += 1

###----- file works -----###
foo = works.split('\n')

# total_works[i] : tong so tu co trong loai van ban i
total_works = []
for x in foo:
    # bo di dong cuoi cung
    if x == '':
        break

    y = x.split(' ')
    total_works.append(y[1])


""" 
    xu li du lieu 
        """
anpha = 0.001
P = []
for i in range(0,total):
    P.append([])
    for j in range(0,27):
        tmp = (float(number_work_list[i][j]) + anpha) / (float(total_works[j]) + total +1)
        P[i].append(tmp)


""" 
    In ket qua ra file text
        """
file_name = "xac_suat_xuat_hien_tu_i_trong_van_ban_nhan_j.txt"
write_file_result = open(file_name, 'w', encoding = 'utf-8')
for i in range(0,total):
    write_file_result.write(work_list[i] + " ")
    for j in range(0,27):
        write_file_result.write(format(P[i][j], '.9f') + " ")
    write_file_result.write("\n")