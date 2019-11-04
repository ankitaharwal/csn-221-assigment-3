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
	// 	cout<<s[i];
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
   string type_2[15]={"addi","addiu","andi","ori","rll","sll","lw","sw","beq","bne","bgt","blt","bge","ble","slti"};
   string type_4[2]={"lui","li"};
   string type_7[2]={"j","jal"};
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
           data+=((int)s[s.size()-count+i]-48)*temp;
       }
    }
    return data;
};

#endif