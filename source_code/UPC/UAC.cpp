#include "../data/encoder.h" 
using namespace std; 

void uac_encoder(string filename)
{
    ifstream file(filename+".txt");
    ofstream file_encoded(filename+"_encoded.txt");
    string s;
    while( getline(file,s))
    {
        //cout<<s<<endl;
        int data;
        int type=2;
        int index;
        data=rand()%10;//read(type,s);
        if(type==2 || type==4 || type==7)
        {
            index=write_txt_data(data);
            s=s+"yo";//s=reform(s,type,index);
        }              
        file_encoded<<s<<"\n";   
    }       
    file.close();
    file_encoded.close(); 
}
int main() 
{ 
    uac_encoder("xxx");
    return 0; 
} 