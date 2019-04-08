#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
long long f1[maxn],f2[maxn],g[maxn],d[maxn],e[maxn],s[maxn],x,y,z,ans[maxn];
struct f{
    long long val;
    int pos;
    bool operator<(const f a)const{
    return val<a.val;
    }
}b[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&d[i],&y,&e[i]);
        g[i]=g[i-1]+y;
        s[i]=s[i-1]+e[i];
        f1[i]=s[i]-d[i];
        b[i].val=f1[i]-e[i];
        b[i].pos=i;
    }
    sort(b+1,b+1+n);
    int pt=n;
    for(int i=1;i<=n;i++){
        while(f1[pt]<b[i].val){
            pt--;
        }
        ans[b[i].pos]=pt;
    }
    long long final_ans=0;
    for(int i=1;i<=n;i++){
        final_ans=max(final_ans,g[ans[i]]-g[i-1]);
    }
    printf("%lld\n",final_ans);
}
