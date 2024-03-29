#include<bits/stdc++.h>
using namespace std;
long long n;
long long tree[4][1002][1002];
int maxx,maxy;
void update(int x,int y,long long val,int i)
{
    int y1=y;
    while(x<=maxx)
    {
        y1=y;
        while(y1<=maxy)
        {
            tree[i][x][y1]+=val;
            y1+=(y1 & -y1);
        }
        x+=(x&-x);
    }
}
long long submat(int x,int y,int i)
{
        int yt;
        long long sum=0;
        while(x>0)
        {
            yt=y;
            while(yt>0)
            {
                sum+=tree[i][x][yt];
                yt-=(yt&-yt);
            }
            x-=(x&-x);
        }
        return sum;
}

int main(){
    scanf("%d%d",&maxx,&n);
    maxy=maxx;
    int x1,x2,y1,y2,ch;
    long long num;
    while(n--)
    {
        scanf(" %d %d %d %d %d",&ch,&x1,&y1,&x2,&y2);
        if(ch==2)
        {
            scanf(" %lld",&num);

            update(x1,y1,num,0);
	        update(x1,y2+1,-num,0);
	        update(x2+1,y1,-num,0);
	        update(x2+1,y2+1,num,0);

	        update(x1,y1,num*(1-y1),1);
	        update(x1,y2+1,num*y2,1);
	        update(x2+1,y1,num*(y1-1),1);
	        update(x2+1,y2+1,-y2*num,1);

	        update(x1,y1,num*(1-x1),2);
	        update(x1,y2+1,num*(x1-1),2);
	        update(x2+1,y1,num*x2,2);
	        update(x2+1,y2+1,-x2*num,2);

	        update(x1,y1,(x1-1)*(y1-1)*num,3);
	        update(x1,y2+1,-y2*(x1-1)*num,3);
	        update(x2+1,y1,-x2*(y1-1)*num,3);
	        update(x2+1,y2+1,x2*y2*num,3);
        }
        else
        {
            long long mat1,mat2,mat3,mat4;
            mat1=submat(x2,y2,0)*x2*y2+submat(x2,y2,1)*x2+submat(x2,y2,2)*y2+submat(x2,y2,3);
            mat2=submat(x2,y1-1,0)*x2*(y1-1)+submat(x2,y1-1,1)*x2+submat(x2,y1-1,2)*(y1-1)+submat(x2,y1-1,3);
            mat3=submat(x1-1,y2,0)*(x1-1)*y2+submat(x1-1,y2,1)*(x1-1)+submat(x1-1,y2,2)*y2+submat(x1-1,y2,3);
            mat4=submat(x1-1,y1-1,0)*(x1-1)*(y1-1)+submat(x1-1,y1-1,1)*(x1-1)+submat(x1-1,y1-1,2)*(y1-1)+submat(x1-1,y1-1,3);
            long long ans=mat1-mat2-mat3+mat4;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
