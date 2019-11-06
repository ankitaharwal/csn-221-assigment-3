#include "../data/encoder.h" 
#include "../data/Read.h" 
using namespace std; 

void iac_encoder(string filename)
{
    ifstream file("../data/"+filename+".txt");
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
        //cout<<type<<" "<<data<<endl;
        //cout<<s<<"->"<<data<<"->"<<type<<endl;
        if(type==2)
        {
            index=write_txt_data(data,"immediate_data_2.txt");
            s=reform(s,index);
        }          
        else if(type==4)
        {
            index=write_txt_data(data,"immediate_data_4.txt");
            s=reform(s,index);
        }    
        else if(type==7)
        {
            index=write_txt_data(data,"immediate_data_7.txt");
           s=reform(s,index);
        }              
        file_encoded<<s<<"\n";   
    }       
    file.close();
    file_encoded.close(); 
}

int main() 
{ 
    ofstream file2("immediate_data_2.txt");
    file2.close();
    ofstream file4("immediate_data_4.txt");
    file4.close();
    ofstream file7("immediate_data_7.txt");
    file7.close();
    iac_encoder("file1");
    return 0; 
} 