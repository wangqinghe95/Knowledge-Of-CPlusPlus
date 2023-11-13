# 
import os

def checkFolderOrFileExisted(name):
    if os.path.exists(name):
        return True
    else:
        return False

def reviewFile(name):
    write_file_name = name + '_interview.md'
    write_file_fd = open(write_file_name, 'w', encoding='utf-8');
    
    read_file = name + '/' + name + '.md'
    if False == checkFolderOrFileExisted(read_file):
        print(read_file + ' does not exist, and return')
        return
    print("read_file = " + read_file)
    with open(read_file, 'r', encoding='utf-8') as file:
        i = 1
        for line in file:
            if line[:4] == '####' and line[4] == ' ':
                write_file_fd.write('    + ' + line[4:].strip() + '\n')
            elif line[:3] == '###' and line[3] == ' ':
                write_file_fd.write(str(i) + '. ' + line[3:].strip() + '\n')
                i+=1
            elif line[:2] == '##' and line[2] == ' ':
                i=1
                write_file_fd.write('\n'+line)
            elif line[0] == '#' and line[1] == ' ':
                write_file_fd.write(line)
            else:   
                continue
    write_file_fd.close()

files_name=("DataStructure","BasicKnowledgeForCPLUS")

for name in files_name:
    reviewFile(name)
    