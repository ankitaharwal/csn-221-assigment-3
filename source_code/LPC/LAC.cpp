#include "../data/encoder.h" 
#include "../data/Read.h" 
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
        int type=2;
        int index;
        data=rand()%10;//read(type,s);
        if(type==2)
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
    lac_encoder("xxx");
    Read* r = new Read();
    int type =0;
    string str="	addi	$s1, $s1, 1";
    int data = r->read(type , str);
    cout<<data<<endl;
    cout<<type<<endl;
    cout<<"dsfs"<<endl;
    return 0; 
} 