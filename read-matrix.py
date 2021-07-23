file = open("test.txt")
lines = file.read().split("\n")

list_matrix = []
matrix_tmp = []

for i in range(0, len(lines)-1): # leave end of lines
    line = lines[i]
    if "=" not in line:
        list_value_string = line.split(" ");
        list_value_float = []
        for str in list_value_string:
            list_value_float.append(float(str))
        matrix_tmp.append(list_value_float)
    else:
        list_matrix.append(matrix_tmp)
        matrix_tmp = []

list_matrix.append(matrix_tmp) # add last case

matrix_1 = list_matrix[0] # get matrix 1
matrix_2 = list_matrix[1] # get matrix 2

print(matrix_1)
print(matrix_2)
print(list_matrix[2])

# create test.txt file with content:
#1 2 3
#3 4 5
#2 3 4
#=====
#4 5 6
#7 8 9
#=====
#1 2 3
