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
        int data;
        int type=0;
        int index=read(type,s);
        if(type==2)
        {
            data=read_txt_data(index);
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
    // cout<<"comparing two files"<<endl;
    // compareFiles("file1");
    return 0; 
} 