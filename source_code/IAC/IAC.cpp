#include "../data/encoder.h" 
using namespace std; 

void lac_encoder(string filename)
{
    ifstream file(filename+".txt");
    ofstream file_encoded(filename+"_encoded.txt");
    string s;
    while( getline(file,s))
    {
        //cout<<s<<endl;
        int data;
        int type=rand()%8;
        int index;
        data=rand()%10;//read(type,s);
        if(type==2)
        {
            index=write_txt_data(data,"immediate_data_2.txt");
            s=s+"< 2";//s=reform(s,type,index);
        }          
        else if(type==4)
        {
            index=write_txt_data(data,"immediate_data_4.txt");
            s=s+"< 4";//s=reform(s,type,index);
        }    
        else if(type==7)
        {
            index=write_txt_data(data,"immediate_data_7.txt");
            s=s+"< 7";//s=reform(s,type,index);
        }          
        file_encoded<<s<<"\n";   
    }       
    file.close();
    file_encoded.close(); 
}
int main() 
{ 
    lac_encoder("xxx");
    return 0; 
} 