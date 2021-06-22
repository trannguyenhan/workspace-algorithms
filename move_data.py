import os
root = "raw_product"
destination = "data"
try: 
    os.mkdir(destination)
except:
    print("folder exists")
for child in os.listdir(root):
    child_folder = root + "/" + child
    for jfile in os.listdir(child_folder):
        jfile_path = child_folder + "/" + jfile
        os.system("cp {} {}".format(jfile_path,destination))