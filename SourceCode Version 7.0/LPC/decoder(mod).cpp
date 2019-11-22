#include "../data/encoder.h"
 #include "../data/Read.h"
using namespace std; 

void lpc_decoder(string filename)
{
    ifstream file(filename+"_encoded.txt");
    ofstream file_decoded(filename+"_decoded.txt");
    string s;
    while( getline(file,s))
    {
        int data=0;
        int type=0;
        bool encoded = read(s, data ,type);

        
        if(type==2)
        {
            if (encoded){
                //here the initial value of data is index indeed
                data=read_txt_data(data);
                s=reformV2(s,data);
            }
            else {
                s=reformV2(s,data);
            }
            
        }              
        file_decoded<<s<<"\n";   
    }       
    file.close();
    file_decoded.close(); 
}
int main() 
{ 
    lpc_decoder("file1");
    // cout<<"comparing two files"<<endl;
    // compareFiles("file1");
    return 0; 
} 
