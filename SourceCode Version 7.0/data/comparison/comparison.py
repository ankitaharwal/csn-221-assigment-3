import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import math
import os



def data_analysis(l_data,l_encoded):
   l_data=[int(i.replace("\n","")) for i in l_data]
   l_encoded=[i.replace("\n","") for i in l_encoded]
   l_encoded=[i.replace(","," ") for i in l_encoded]
   # l_encoded=[i for i in l_encoded if "msg" not in i]
   # l_encoded=[i for i in l_encoded if "asciiz" not in i]
   instruction_no={str(i):0 for i in range(1,8)}
   type_1=["add","beq"]
   type_2=["addi","addiu","andi","ori","rll","sll","bne","bgt","blt","bge","ble","slti"]
   type_3=["la","move","lw","comment","sw"]
   type_4=["lui","li"]
   type_5=["j","jr","jal",".globl"]
   type_7=[]
   l_encoded_temp=[]
   for i in l_encoded:
      if '"' in i:
         i=i[:i.index('"')-1]+" comment"
         i=i.split(" ")
         i[0]="comment"
         i=" ".join(i)
      l=i.split(" ")
      if len(l)==1:
         instruction_no["6"]+=1
      elif l[0] in type_1:
         instruction_no["1"]+=1
      elif l[0] in type_2:
         instruction_no["2"]+=1
      elif l[0] in type_3:
         instruction_no["3"]+=1
      elif l[0] in type_4:
         instruction_no["4"]+=1
      elif l[0] in type_5:
         instruction_no["5"]+=1
      elif l[0] in type_7:
         instruction_no["7"]+=1
   # print("Total number of instructions:",len(l_encoded))
   max_bits=32
   original_memory=max_bits*len(l_encoded)
   # print("Original Memory:",original_memory,"bits or",original_memory/8,"Bytes")
   #print(l_encoded)
   if len(l_data)==0:
      immediate_bits=0
   else:
      immediate_bits=(math.ceil(math.log(len(l_data))/math.log(2)))
   max_bits_1=(0 if instruction_no["1"]==0 else 1)*(6+15)
   max_bits_2=(0 if instruction_no["2"]==0 else 1)*(6+10+immediate_bits)
   max_bits_4=(0 if instruction_no["4"]==0 else 1)*(6+5+immediate_bits)
   max_bits_7=(0 if instruction_no["7"]==0 else 1)*(6+immediate_bits)
   #print([max_bits_1,max_bits_2,max_bits_4,max_bits_7])
   max_bits=max([max_bits_2,max_bits_4,max_bits_7])#add max_bits_1
   return max_bits
   



print("In the original research, \nNumber of bits were 32")
print("Number of bits of OP code :6")
print("Number of bits of Reg :5")
print("Number of bits of Immediate value :16")
img=mpimg.imread('1.png')

file_name="file1"
path=os.getcwd()[:-10]+file_name+".txt"
f_encoded=open(path,'r')
l_encoded=f_encoded.readlines()


print("\nTotal number of instructions:",len(l_encoded))
max_bits=32
original_memory=max_bits*len(l_encoded)
print("Original Memory:",original_memory,"bits or",round(original_memory/(8*1024),2),"KBytes")
d_final_result={}
d_final_size={"No method":original_memory}
for i in ["LAC","IAC","UAC","LPC","IPC","UPC"]:
   if "I" not in i:
      print(f"\nFor {i} technique,")
      path=os.getcwd()[:-15]+i+"/"+"immediate_data.txt"
      f_data=open(path,'r')
      l_data=f_data.readlines()
      max_bits=data_analysis(l_data,l_encoded)
      new_memory=max_bits*len(l_encoded)
      print("     Compressed Memory:",new_memory,"bits or",round(new_memory/(8*1024),2),"KBytes")
      reduction_ratio=(original_memory-new_memory)*100/original_memory
      d_final_result[i]=reduction_ratio/100
      d_final_size[i]=new_memory
      print("     Reduction Ratio (%):",reduction_ratio)
   else:
      print(f"\nFor {i} technique,")
      path=os.getcwd()[:-15]+i+"/"
      f_data_2=open(path+"immediate_data_2.txt",'r')
      l_data_2=f_data_2.readlines()
      max_bits_2=data_analysis(l_data_2,l_encoded)
      f_data_4=open(path+"immediate_data_4.txt",'r')
      l_data_4=f_data_4.readlines()
      max_bits_4=data_analysis(l_data_4,l_encoded)
      f_data_7=open(path+"immediate_data_7.txt",'r')
      l_data_7=f_data_7.readlines()
      max_bits_7=data_analysis(l_data_7,l_encoded)
      max_bits_1=21
      #max_bits=max([max_bits_2,max_bits_4,max_bits_7])#add max_bits_1
      #max_bits=int(sum([max_bits_2,max_bits_4,max_bits_7])/3)#add max_bits_1
      max_bits=int((max_bits_2*len(l_data_2)+max_bits_4*len(l_data_4)+max_bits_7*len(l_data_7))/(len(l_data_2)+len(l_data_4)+len(l_data_7)))
      new_memory=max_bits*len(l_encoded)
      print("     Compressed Memory:",new_memory,"bits or",round(new_memory/(8*1024),2),"KBytes")
      reduction_ratio=(original_memory-new_memory)*100/original_memory
      d_final_result[i]=reduction_ratio/100
      d_final_size[i]=new_memory
      print("     Reduction Ratio (%):",reduction_ratio)
plt.bar(*zip(*d_final_size.items()))
plt.xlabel("Type of technique")
plt.ylabel("Memory used (Bits)")
plt.show()
plt.close()
plt.bar(*zip(*d_final_result.items()))
plt.xlabel("Type of technique")
plt.ylabel("Reduction Ratio")
plt.show()
plt.close()
f_encoded.close()
f_data.close()
