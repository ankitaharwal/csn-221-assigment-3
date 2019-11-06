#include "../data/encoder.h" 
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
        int type=2;
        int index=rand()%10;//read(type,s);
        if(type==2)
        {
            data=read_txt_data(index);
            s=s+"yo";//s=reform(s,type,data);
        }              
        file_decoded<<s<<"\n";   
    }       
    file.close();
    file_decoded.close(); 
}
int main() 
{ 
    lac_decoder("xxx");
    return 0; 
} 