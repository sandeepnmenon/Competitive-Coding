/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
//Your code here
    int ansLen=0;
    for(int i=0;i<n;++i)
        if(arr[i]==0){
            arr[i]=-1;
        }

    int sum=0;

    map<int,int>m;
    for(int i=0;i<n;++i){
        sum+=arr[i];
        if(sum==0 and ansLen==0)
            ansLen=1;
        if(sum==0)
            ansLen=i+1;

        if(m.find(sum)!=m.end())
            ansLen=max(ansLen,i-m[sum]);
        else
            m[sum]=i;
    }


    return ansLen;
}
