#include "read.h"

#include <bits/stdc++.h> 
using namespace std; 

int main(){
	string s = "move $a0, $s2 # Argument 1: sum ($s2)";
	string s2 ="addi $s1, $s1, 1 # iencknjco";
	int type=0;
	Read* r = new Read();
	int data = r->read(type,s);
	printf("type == %d   data = = %d\n",type,data);

	data = r->read(type,s2);
	printf("type == %d   data = = %d\n",type,data);
}