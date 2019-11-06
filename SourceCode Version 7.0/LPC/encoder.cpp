#include "../data/encoder.h" 
#include "../data/Read.h" 
using namespace std; 

void lpc_encoder(string filename)
{
    ifstream file("../data/"+filename+".txt");
    ofstream file_encoded(filename+"_encoded.txt");
    string s;
    int data;
    int type;
    int index;
    while( getline(file,s))
    {
        type=0;
        data=read(type,s);
        if(type==2)
        {
            cout<<number_of_values("immediate_data.txt");
            index=write_txt_data(data);
            cout<<index<<" "<<endl;
            s=reform(s,index);
        }              
        file_encoded<<s<<"\n";   
    }       
    file.close();
    file_encoded.close(); 
}

int main() 
{ 
    ofstream file("immediate_data.txt");
    file.close();
    lpc_encoder("file1");
    return 0; 
} 