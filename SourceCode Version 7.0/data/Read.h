#ifndef READ_H
#define READ_H


#include <stdio.h> 
#include <string.h>
#include <bits/stdc++.h> 
using namespace std;
int read(int &type,string s)
{
    if(s[0]=='.' or s[s.size()-1]==':' or s=="syscall")
    {
      type =0;
        return 0;
    }
  // for (string::size_type i = 0; i < s.size(); i++)
  // {
  //  cout<<s[i];
  // }
  replace( s.begin(), s.end(), '\t', ' ');
    replace( s.begin(), s.end(), ',', ' ');
    int start=-1;
    int end=-1;
  for (string::size_type i = 0; i < s.size(); i++) 
    {
        if(s[i]!=' ' && start==-1)
        {
            start=i;
            break;
        }
  }
    for (string::size_type i = start; i < s.size(); i++) 
    {
        if(s[i]==' ')
        {
            end=i;
            break;
        }
  }
    string s_function;
    for (string::size_type i = start; i < end; i++) 
    {
        string c(1,s[i]);
        s_function.append(c);
    }
   string type_2[15]={"addi","addiu","andi","ori","rll","sll","bne","bgt","blt","bge","ble","slti"};//removed beq sw lw
   string type_4[2]={"lui","li"};
   string type_7[2]={};//removeed j and jal
   for(int i=0;i<15;i++)
   {
       if(type_2[i]==s_function)
       {
           type=2;
           break;
       }
   }
    for(int i=0;i<2;i++)
   {
       if(type_4[i]==s_function)
       {
           type=4;
           break;
       }
   }
   for(int i=0;i<2;i++)
   {
       if(type_7[i]==s_function)
       {
           type=7;
           break;
       }
   }
   int data=0;
   int count=0;
   if(type==2 || type==4 || type==7)
   {
       int i=s.size()-1;
       
       while(s[i]!=' ')
       {
           //cout<<s[i]<<endl;
           count++;
           i-=1;
       }
       
       ///number is 23456 
       // data = 23
       // next 4
       /// data = data*10 + next = 23*10+4=234

       // for(int i=0;i<count;i++)
       // {
       //     int temp=1;
       //     for(int j=0;j<count-i-1;j++)
       //     {
       //         temp*=10;
       //     }
       //     if ((int)s[s.size()-count+i]== 45){
       //       data_is_negative =1 
       //     }
       //     else {

       //          data+=((int)s[s.size()-count+i]-48)*temp;
       //     }
                  
           
       // }

       // string s = fghjk -234
       //count =4 
       // index of '-' is 
       data=0;
       for (int i=1;i<count;i++){
          data=data*10+((int)s[s.size()-count+i]-48);
       }


    }
    if ((char)s[s.size()-count] == '-')
      return -1*data;
  return data;
};


string reform(string s  , int index){
  int count=0;
  int i= s.size()-1;
  string s_mod;
  for (string::size_type i = 0; i < s.size(); i++) 
    {
        string c(1,s[i]);
        s_mod.append(c);
    } 
  replace( s.begin(), s.end(), '\t', ' ');
    replace( s.begin(), s.end(), ',', ' ');
    string s_function;   
    while(s[i]!=' ' )
       {
           count++;
           i-=1;
       }
    int end = s.size()-count;   
    for (string::size_type i = 0; i < end; i++) 
    {
        string c(1,s_mod[i]);
        s_function.append(c);
    } 
    s_function.append(to_string(index));
    return s_function;
}


bool compareFiles(string f1 ){

  ifstream file1(filename+".txt");
  ifstream file2(filename+"_decoded.txt");

  string s1, s2;
  long count =0;
  bool printed = false;

  while (getline(file1,s1)){

    count++;
    getline(file2,s2);

    for (string::size_type i = 0; i < s1.size(); i++) 
        {
            if ((int)s1[1] != (int)s2[i]){
              //here some differece was found
              printed=true;
              printf("some mismatch was found at line number %ld , \nstring in file 1 is %s \nstring in file 2 is %s\n\n",count,s1,s2 );
            }
        }//for loop 
  }//while loop
  if (printed)
    return false;
  printf("voila no differeces found \n");
  return true;
}

#endif