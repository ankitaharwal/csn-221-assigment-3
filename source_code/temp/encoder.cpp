#include <iostream> 
#include <fstream>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <bits/stdc++.h> 
using namespace std; 
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
    // ofstream myfile;
    // myfile.open("immediate_data.txt","a");               
    // // for(int i=0;i<arr_data.size();i++)
    // // {
    // //     myfile<<arr_data.at(i)<<"\n";   
    // // }    
    // myfile<<n<<"\n";
    // myfile.close();

    FILE * myfile = fopen("immediate_data.txt","a");
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

int main() 
{ 
    vector<int> arr;
    arr.push_back(2002);
    arr.push_back(2002);
    arr.push_back(40001);
    arr.push_back(2002);
    arr.push_back(40001);
    arr.push_back(300);
    // for(int i=0;i<20000;i++)
    // {
    //     arr.push_back(rand()%10);
    // }
     cout<<"arr immediate size:"<<arr.size()<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr.at(i)<<" -> ";
        int b_digits;
        if(arr.at(i)!=0)
        {
            b_digits=2+floor(log2(abs(arr.at(i))));
        }
        else
        {
            b_digits=2;
        }
        int_to_binary(arr.at(i),b_digits);
    }
    vector<int> arr_data;
    vector<int> arr_new;
    encoder(arr,arr_data,arr_new);
    cout<<"arr new size:"<<arr_new.size()<<endl;
    int binary_digits=ceil(log2(arr_data.size()));
    for(int i=0;i<arr_new.size();i++)
    {
        cout<<arr_new[i]<<" -> ";
        int_to_binary(arr_new[i],binary_digits);
    }
    cout<<"arr data size:"<<arr_data.size()<<endl;
    for(int i=0;i<arr_data.size();i++)
    {
        cout<<arr_data.at(i)<<" -> ";
        int b_digits;
        if(arr_data.at(i)!=0)
        {
            b_digits=2+floor(log2(abs(arr_data.at(i))));
        }
        else
        {
            b_digits=2;
        }
        int_to_binary(arr_data.at(i),b_digits);
    }
    update_txt_data(arr_data);
    cout<<write_txt_data(3001)<<endl;
    lac_encoder("xxx.txt");
    return 0; 
} 