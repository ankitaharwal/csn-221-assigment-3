#include "../data/encoder.h" 
#include "../data/Read.h" 
using namespace std; 

void lac_encoder(string filename)
{
    ifstream file(filename+".txt");
    ofstream file_encoded(filename+"_encoded.txt");
    string s;
    int data;
    int type;
    int index;
    while( getline(file,s))
    {
        //cout<<s<<endl;
        type=0;
        data=read(type,s);
        if(type==2)
        {
            index=write_txt_data(data);
            s=s+"< 2";//s=reform(s,type,index);
        }              
        file_encoded<<s<<"\n";   
    }       
    file.close();
    file_encoded.close(); 
}

int main() 
{ 
  lac_encoder("file1");
    // string s="syscall";
    // int type=0;
    // int data=read(type,s);
    // cout<<data<<" "<<type<<endl;
    return 0; 
} 