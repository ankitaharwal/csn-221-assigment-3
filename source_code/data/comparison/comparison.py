file_name="file1"
f_encoded=open(file_name+"_encoded.txt",'r')
f_data=open("immediate_data.txt",'r')
l_encoded=f_encoded.readlines()
l_data=f_data.readlines()
def immediate_data_analysis(l_data):
   l=[int(i.replace("\n","")) for i in l_data]
   print("Length of data :",len(l))
immediate_data_analysis(l_data)
f_encoded.close()
f_data.close()
