#ifndef READ_H
#define READ_H


#include <stdio.h> 
#include <string.h>
#include <bits/stdc++.h> 
using namespace std;
////this is all the instructions in mips
// {
// 	//type 1 instructuoons
// 		mp["add"]=1;
// 		mp["sub"]=1;
// 		mp["addu"]=1;
// 		mp["subu"]=1;
// 		mp["mul"]=1;
// 		mp["and"]=1;
// 		mp["or"]=1;
// 		mp["slt"]=1;
// 		// mp["sw"]=2;

// 		//type 3 instructions
// 		mp["mult"]=3;
// 		mp["div"]=3;
// 		mp["la"]=3;
// 		mp["move"]=3;

// 		//type 2 instructions
// 		mp["addi"]=2;
// 		mp["addiu"]=2;
// 		mp["andi"]=2;
// 		mp["ori"]=2;
// 		mp["rll"]=2;
// 		mp["sll"]=2;

// 		mp["lw"]=2;
// 		mp["sw"]=2;

// 		mp["beq"]=2;
// 		mp["bne"]=2;
// 		mp["bgt"]=2;
// 		mp["blt"]=2;
// 		mp["bge"]=2;
// 		mp["ble"]=2;

// 		mp["slti"]=2;
// 		// mp["sw"]=2;


// 		//type 4 instructions
// 		mp["lui"]=4;
// 		mp["li"]=4;

// 		//type 5 instructions
// 		mp["mfhi"]=5;
// 		mp["mflo"]=5;
// 		mp["jr"]=5;

// 		//type 6 instructions
//		syscall

// 		//type 7 instructions
// 		mp["j"]=7;
// 		mp["jal"]=7;

// }
class Read {
	unordered_map < string , int > mp;
	const char * delimeters = "\t  ,\n";
	// {'\t',  ' ',  ',',  '\n','\0'  };
	

	//constructor
	public:
	Read(){
		//type 2 instructions
		mp["addi"]=2;
		mp["addiu"]=2;
		mp["andi"]=2;
		mp["ori"]=2;
		mp["rll"]=2;
		mp["sll"]=2;

		mp["lw"]=2;
		mp["sw"]=2;

		mp["beq"]=2;
		mp["bne"]=2;
		mp["bgt"]=2;
		mp["blt"]=2;
		mp["bge"]=2;
		mp["ble"]=2;

		mp["slti"]=2;

		// type 4 instructions
		mp["lui"]=4;
		mp["li"]=4;

		//type 7 instructions
		mp["j"]=7;
		mp["jal"]=7;

	}
	

	//read function 
	//this identifies the type of instrucion passed to this function and thus returns the required values correspondingly
	public:
	int read(int & type , string str){

		//given string is converted to cstring for quick access using strtok
		// char *szBuffer = new char[str.size()+1];
  //    	strcpy(szBuffer,str.c_str( ));
		int n =str.length();
		char buff[n+1];
		strcpy(buff, str.c_str());
		char * pch;
		printf("processing the passed string \n");


		pch = strtok (buff,delimeters);

		cout<<"the str "<< str <<endl;
		cout<<"the str copy ";
		for (int i=0;i<n;i++)
			cout<<buff[i];
		cout<<endl;
		cout<<"the first word " << pch <<endl;

		string temp(pch);
		if (mp.find(temp) == mp.end()) {
			//means the instruction is not there in the map
			type =0;
			try {
				delete[] buff;
				delete[] pch;
			}
			catch(const char* c){}
			return -1;
		}
		else {
			//the key exists in the map
			type = mp[temp];
			if (type ==2){
				//type 2 instruction

				pch = strtok (NULL, delimeters);//now pch = reg 1
				pch = strtok (NULL, delimeters);// now pch = reg 2
				pch = strtok (NULL, delimeters);//now pch has the immediate value	
			}
			else if (type ==4 ){\
				//type 4 
				pch = strtok (NULL, delimeters);// now pch = reg 1
				pch = strtok (NULL, delimeters);//now pch has the immediate value		
			}
			else if (type==7) {
					//type  7 ins

				pch = strtok (NULL, delimeters);//now pch has the immediate value	
			}
			string data(pch);//type casting the pch into a string
			try {
				delete[] buff;
				delete[] pch;
			}
			catch(const char* c){}
			return stoi(data);
		}//else statement
	try {
		delete[] buff;
		delete[] pch;
	}
	catch(const char* c){}
	return -1;	
	}//read complete



};


#endif