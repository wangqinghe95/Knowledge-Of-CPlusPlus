# 
import os

def checkFolderOrFileExisted(name):
    if os.path.exists(name):
        return True
    else:
        return False

def reviewFile(name):
    write_file_name = name + '_interview.md'
    # print(write_file_name)

    write_file_fd = open(write_file_name, 'w', encoding='utf-8');
    
    read_file = "../" + name + '/' + name + '.md'
    if False == checkFolderOrFileExisted(read_file):
        print(read_file + ' does not exist, and return')
        return
    # print(read_file)

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
                new_line = line[:2] + '[' + line[2:-1] + '](' + name + '/' + name + '.md)'
                write_file_fd.write(new_line)
            else:   
                continue
    write_file_fd.close()

files_name=("BasicKnowledgeForCPLUS", "LinuxOperationSystem","DataStructure", "ComputerNetwork", "Compiler", "DesignPattern")

for name in files_name:
    reviewFile(name)
    
interview_file = "InterviewGuideForC++.md"
write_file=open(interview_file,"w", encoding='utf-8')
write_file.write('# ' + interview_file[:-3] + '\n')
for name in files_name:
    read_file_name= name + '_interview.md'
    with open(read_file_name, 'r', encoding='utf-8') as file:
        for line in file:
            if line[0] == '#':
                if line[1] == ' ':
                    write_file.write('\n')
                write_file.write('#' + line)
            else:
                write_file.write(line)
    print('read file:' + read_file_name + ' successfully')
    os.remove(read_file_name)
write_file.close()
new_file = "../"+interview_file
if checkFolderOrFileExisted(new_file):
    os.remove(new_file)
os.rename(interview_file,new_file)

