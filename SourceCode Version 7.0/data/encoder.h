#ifndef ENCODER_H
#define ENCODER_H

#include <iostream> 
#include <fstream>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <bits/stdc++.h> 
using namespace std; 

//creates binary of the number given as per the specifications
void int_to_binary(int n,int binary_digits)
{
    int arr[binary_digits];
    for(int j=0;j<binary_digits;j++)
    {
        arr[j]=0;
    }
    if(n==0)
    {
        for(int j=0;j<binary_digits;j++)
         {
            cout<<arr[j];
        }
        cout<<endl;
        return;
    }
    else if(n<0)
    {
        arr[0]=1;
        n=-n;
    }
    int i=binary_digits-1;
    while(n!=0)
    {
        arr[i]=n%2;
        n=n/2;
        i--;
    }
    for(int j=0;j<binary_digits;j++)
    {
        cout<<arr[j];
    }
    cout<<endl;
}

//main crux function of this file
void encoder(vector<int> arr,vector<int> &arr_data,vector<int> &arr_new)
{
    for(int i=0;i<arr.size();i++)
    {
        bool insert=true;
        for(int j=0;j<arr_data.size();j++)
        {
            if(arr_data[j]==arr[i])
            {
                arr_new.push_back(j);
                insert=false;
                break;
            }
        }
        if(insert)
        {
            arr_new.push_back(arr_data.size());
            arr_data.push_back(arr[i]);
        }
    }
}


void update_txt_data(vector<int> arr_data)
{
    ofstream myfile;
    myfile.open ("immediate_data.txt");               
    for(int i=0;i<arr_data.size();i++)
    {
        myfile<<arr_data.at(i)<<"\n";   
    }       
    myfile.close();
}

////this is used for giving or tending O(1) complexity to the overall encoding function in sequence
int write_txt_data(int n)
{
    int i=0;
    int a;
    //vector<int> arr_data;
    ifstream infile("immediate_data.txt");
    while(infile>>a)
    {
        //arr_data.push_back(a);
        if(n==a)
        {
            return i;
        }
        i++;
    }
    infile.close();

    FILE * myfile = fopen("immediate_data.txt","a");
    fprintf(myfile,"%d\n",n);
    fclose(myfile);   
    return i;   
}
int write_txt_data(int n,char const *filename)
{
    int i=0;
    int a;
    //vector<int> arr_data;
    ifstream infile(filename);
    while(infile>>a)
    {
        //arr_data.push_back(a);
        if(n==a)
        {
            return i;
        }
        i++;
    }
    infile.close();

    FILE * myfile = fopen(filename,"a");
    fprintf(myfile,"%d\n",n);
    fclose(myfile);   
    return i;   
}




int read_txt_data(int i)
{
    ifstream file("immediate_data.txt");
    int a;
    do 
    {   file>>a;
    }   while( i-- > 0);
    return a;  
}
int read_txt_data(int i,char const *filename)
{
    ifstream file(filename);
    int a;
    do 
    {   file>>a;
    }   while( i-- > 0);
    return a;  
}
int number_of_values(char const *filename)
{
    int a;
    int i=0;
    ifstream infile("immediate_data.txt");
    while(infile>>a)
    {
        i++;
    }
    infile.close();
    return i;
}


#endif