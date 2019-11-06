#include "../data/encoder.h"
 #include "../data/Read.h"
using namespace std; 

void lac_decoder(string filename)
{
    ifstream file(filename+"_encoded.txt");
    ofstream file_decoded(filename+"_decoded.txt");
    string s;
    while( getline(file,s))
    {
        //cout<<s<<endl;
        int data;
        int type=0;
        int index=read(type,s);
        if(type==2)
        {
            data=read_txt_data(index,"immediate_data_2.txt");
            s=reform(s,data);
        }   
        else if(type==4)
        {
            data=read_txt_data(index,"immediate_data_4.txt");
            s=reform(s,data);
        }   
        else if(type==7)
        {
            data=read_txt_data(index,"immediate_data_7.txt");
            s=reform(s,data);
        }                  
        file_decoded<<s<<"\n";   
    }       
    file.close();
    file_decoded.close(); 
}
int main() 
{ 
    lac_decoder("file1");
    return 0; 
} 