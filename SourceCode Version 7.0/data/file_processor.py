f=open("filet.txt",'r+')
l=f.readlines()
for i in range(len(l)):
   try:
      l[i]=l[i][:l[i].index("#")]+"\n"
   except:
      pass
s="".join(l)
s=s.replace("\t"," ")
l=s.split("\n")
for i in range(len(l)):
   l[i]=l[i].strip()
l=[i for i in l if i!='']
s="\n".join(l)
f.close()
new_f=open("file1.txt","w")
new_f.write(s)
new_f.close()
