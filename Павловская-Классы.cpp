#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Arrays
{
public:
    int size1, size2, index;
    
    
    void get_input()
    {   
        
        
    }
    void clutch(string* farr, string* sarr)
    {
        string *clutch_arr = new string[size1*size2];
        int cnt = 0;
        
        while(cnt<size1*size2)
        {
            for(int i = 0; i<size1; i++)
            {
                for(int j = 0; j<size2; j++)
                {
                    clutch_arr[cnt]=farr[i]+sarr[j];
                    cnt+=1;
                }
            }
        }
        
        cout<<size1*size2<<endl;
        for(int i = 0; i<size1*size2; i++){
            cout<<clutch_arr[i]<<endl;
        }
    }
    
    void merger(string* farr, string* sarr)
    {   
        vector<string> merger_arr;
        
        for(int i = 0; i<size1; i++)
        {
            merger_arr.push_back(farr[i]);
        }
        
        for(int i = 0; i<size2; i++)
        {
            bool ok = true;
            for(int j = 0; j<size1; j++)
            {
                if(sarr[i]==farr[j])
                {
                    ok = false;
                }
            }
            if(ok)
            {
                merger_arr.push_back(sarr[i]);
            }
        }
        
        cout<<merger_arr.size()<<endl;
        for(int i = 0; i<merger_arr.size(); i++)
        {
            cout<<merger_arr[i]<<endl;
        }
    }
    
    void find_row(string* farr, string* sarr, int index)
    {
        if(size1<index)
        {
            cout<<"Not exist"<<endl;
        }
        else
        {
            cout<<farr[index-1]<<endl;
        }
        if(size2<index)
        {
            cout<<"Not exist"<<endl;
        }
        else
        {
            cout<<sarr[index-1]<<endl;
        }
    }
    
};
int main()
{
    Arrays arr;
    
    cin>>arr.size1;
    string *farr = new string[arr.size1];
    
    for(int i = 0; i<arr.size1; i++)
    {
        cin>>farr[i];
    }
    
    cin>>arr.size2;
    string *sarr = new string[arr.size2];
    
    for(int i = 0; i<arr.size2; i++)
    {
        cin>>sarr[i];
    }
    
    cin>>arr.index;
    
    arr.clutch(farr, sarr);
    arr.merger(farr, sarr);
    arr.find_row(farr, sarr, arr.index);
}