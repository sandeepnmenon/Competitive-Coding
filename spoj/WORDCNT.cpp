#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string str,word;
    cin>>n;
    getline(cin,str);
    for(int i=0;i<n;i++){
        int sz=0,cnt=0,maxcnt=0;
        getline(cin,str);
        istringstream iss(str, istringstream::in);
        while(iss>>word){
            if(word.length()==sz) cnt++;
            else{
                sz=word.length();
                cnt=1;
            }
            if(cnt>maxcnt) maxcnt=cnt;
        }
        cout<<maxcnt<<endl;
    }
    return 0;
}
