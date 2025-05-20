#include<iostream>
#include<string>
using namespace std;

int main(){
        string s = "babadaaaa";
        int size = s.size();
        string sub ="";
        int i,l=0,r=0,maxlength=1,len=0,k=0,count=0,start=0;
        int hash[256],a[256];
        //if(s == "") return "";
        for(i=0;i<255;i++) {
            hash[i] = -1;
            a[i] = -1;    
        }
        for(i=0;i<8;i++) 
        std::cout<<a[i]<<" ";
        std::cout<<"\n";
        while(r<size){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= 1){
                    a[k]=r;
                    l = hash[s[r]] + 1;
                    k++;
                }
            }
            hash[s[r]] = r;
            r++;
        }
        i = 0;
        while(a[i] != -1){
            int flag = start;
            count = a[i];
            int flag2 = count;
            if(start == count) {
                i++;
                count = a[i];
            }
            else{
                int val = a[i] - start;
                while(start < count){
                    if(s[start] != s[count]) break;
                    start++;
                    count--;
                }
                if(start == count && sub.size() < val) 
                   while(flag < flag2) sub = sub + s[flag];
                start = a[i];
            }
        }        
        //std::cout<<count<<"\n";
        
        std::cout<<sub<<" ";
        return 0;

    
}