#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 99999999
#define maxn 230
#define clr(x)memset(x,0,sizeof(x))
#define min(a,b)(a)<(b)?(a):(b)
int q[1000];
int flow[maxn][maxn];
int c[maxn][maxn];
int a[maxn];
int p[maxn];
int s,t,tt,n,m;
int E_K()
{
    clr(flow);
    clr(p);
    s=1;
    t=n;
    int maxflow=0;
    int u,v,front,rear;
    for(;;)
    {
        clr(a);
        a[s]=INF;
        front=rear=0;
        q[rear++]=s;
        while(front<rear)
        {
            u=q[front++];
            for(v=1;v<=n;v++)
                if(!a[v]&&(c[u][v]>flow[u][v]))
                {
                    p[v]=u;
                    q[rear++]=v;
                    a[v]=min(a[u],c[u][v]-flow[u][v]);
                }
        }
        if(a[t]==0)
            break;
        for(u=t;u!=s;u=p[u])
        {
            flow[p[u]][u]+=a[t];
            flow[u][p[u]]-=a[t];
        }
        maxflow+=a[t];
    }
    return maxflow;
}
struct node
{
    int x,y,wi;
}sc[410000];
bool ok(int di)
{
    int i;
    clr(c);
    for(i=0;i<m;i++)
        if(sc[i].wi<=di)
        {
            c[sc[i].y][sc[i].x]+=1;
            c[sc[i].x][sc[i].y]+=1;
        }
    int fl=E_K();
    if(fl>=tt)
        return true;
    return false;
}
int main()
{
    int low,high,mid,i;
    while(scanf("%d%d%d",&n,&m,&tt)!=EOF)
    {
        low=0;
        high=0;
        clr(c);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&sc[i].x,&sc[i].y,&sc[i].wi);
            if(sc[i].wi>high)
                high=sc[i].wi;
        }
        int res;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(ok(mid))
            {
                high=mid-1;
                res=mid;
            }
            else low=mid+1;
        }
        printf("%d\n",res);
    }
    return 0;
}