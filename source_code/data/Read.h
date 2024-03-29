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
   int data_is_negative=0;
   if(type==2 || type==4 || type==7)
   {
       int i=s.size()-1;
       int count=0;
       while(s[i]!=' ')
       {
           //cout<<s[i]<<endl;
           count++;
           i-=1;
       }
       
       for(int i=0;i<count;i++)
       {
           int temp=1;
           for(int j=0;j<count-i-1;j++)
           {
               temp*=10;
           }
           if((int)s[s.size()-count+i]==45)
           {
               data_is_negative=1;
           }
           else
           {
                data+=((int)s[s.size()-count+i]-48)*temp;
           }           
       }
    }
    if(data_is_negative==1)
    {
        return data*-1;
    }
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


string reform(string s , int index , bool encoded){
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
    if (encoded)
      s_function.append(" Y ");
    else 
      s_function.append(" N ");
    s_function.append(to_string(index));
    return s_function;
}

bool compareFiles(string filename ){

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
            if ((int)s1[i] != (int)s2[i]){
              //here some differece was found
              printed=true;
              printf("some mismatch was found at line number %ld , \n",count );
              printf("\t\tthe mismatch is found in character number %ld \n",(long)(i+1) );
              printf("\t\tfor file 1 the character is %c\n",(char)s1[i] );
              printf("\t\tfor file 2 the character is %c\n-------------\n",(char)s2[i] );
            }
        }//for loop 
  }//while loop
  if (printed)
    return false;
  printf("voila no differeces found \n");
  return true;
}

#endif