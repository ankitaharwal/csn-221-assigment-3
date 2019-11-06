#include "../data/encoder.h" 
using namespace std; 

void uac_decoder(string filename)
{
    ifstream file(filename+"_encoded.txt");
    ofstream file_decoded(filename+"_decoded.txt");
    string s;
    while( getline(file,s))
    {
        //cout<<s<<endl;
        int data;
        int type=2;
        int index=rand()%10;//read(type,s);
        if(type==2)
        {
            data=read_txt_data(index,"immediate_data_2.txt");
            s=s+"< 2";//s=reform(s,type,data);
        }        
        else if(type==4)
        {
            data=read_txt_data(index,"immediate_data_4.txt");
            s=s+"< 4";//s=reform(s,type,data);
        }   
        else if(type==7)
        {
            data=read_txt_data(index,"immediate_data_7.txt");
            s=s+"< 7";//s=reform(s,type,data);
        }           
        file_decoded<<s<<"\n";   
    }       
    file.close();
    file_decoded.close(); 
}
int main() 
{ 
    uac_decoder("xxx");
    return 0; 
} 