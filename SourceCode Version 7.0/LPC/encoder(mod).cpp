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
    vector<int> arr;//vector for all immediate values
    vector<int> arr_set;//to be used as set for immediate values

    //reading the file to encode line by line
    while( getline(file,s))
    {
        type=0;
        //read the  data from line 
        data=read(type,s);

        // if of type two instruction we need to harnes the immediate value form it
        if(type==2)
        {
            //push back the immediate value in the vector
            arr.push_back(data);
        }              
          
    } 

    file.close();


    // sort all the immediate values obtained  
    sort(arr.begin(), arr.end()); 
    
    //making set from the array of immediate values
    arr_set.push_back(arr.at(0));

    int i_set=0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr.at(i)!=arr_set.at(i_set))
        {
            arr_set.push_back(arr.at(i));
            i_set++;
        }
    }
    //set constructioin is complete by now 


    //printing set valuess
    for(int i=0;i<arr_set.size();i++)
    {
        cout<<arr_set.at(i)<<" ";
    }
    cout<<endl;
    //done


    //implementing the ulimate P series of the encoding ~mohit kumar
    int setlen=0;//set length for encoded elements
    int data_bits=0;//bits for data element
    int new_bits=0;//bits for encodd elements
    double log;//temp variable used to store log


    // reset the array 
    arr.clear();

    //finfidinf the cores  to be encoded
    for (int i = arr_set.size()-1 ; i>=0;i--){

        //increasing length of set assuming that the given element will be encoded
        setlen++;

        //evaluating the bits for the given element without encoding
        log = log2(  abs(  arr_set.at(i)  ) );
        data_bits = (int)(ceil(log));
        if (data_bits==0)data_bits=1;

        //evaluating the bits for encoded elements
        log = log2( abs( setlen ) );
        new_bits = (int)(ceil(log));
        if (new_bits==0)new_bits=1;

        //displaying the element in terminal
        printf("%d  %d  %d  ",arr_set.at(i), data_bits , new_bits);

        if (new_bits<data_bits){
            //the number should be encoded and hence continue
            printf(" encoded\n");
            //the value that is to be encoded will be now be pushed to arr to set into immediate values
            arr.push_back(arr_set.at(i));

            //break;
        }
        else {
            printf(" not encoded\n");
            //this will not be anyhow put in our immediate_data.txt file
        }

        //now all the values to be encoded are with us put them in immediate_data.txt
        update_txt_data(arr);

    }

    cout<<"finally encoded data will take bits :"<<new_bits<<endl;
    
    //let's encode
    file.open("../data/"+filename+".txt");
    while( getline(file,s))
    {
        type=0;
        //read the  data from line 
        data=read(type,s);

        // if of type two instruction we need to harnes the immediate value form it
        if(type==2)
        {
            index = scan_txt_data(data);
            if (index==-1){
                s = reform(s , data , false);
            }
            else 
                s = reform(s , index , true);
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
