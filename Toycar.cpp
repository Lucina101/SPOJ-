#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,inf=1e9;
int t,n,k,p,x,v[maxn],ans,c;
vector<int> a[maxn];
bool b[maxn];
/*
3 cases
1) Toy is at the floor-> Do nothing
2) Toy is on the shelf and floor has space left-> Just put toys in
3) Floor is full and Toy is on the shelf-> Swap it with toy that has greatest next play
Why does this work? 1 and 2 are trivial Let's look at 3)
Assume that you swap toys with smaller next play. The answer can't be better right.
You still have to swap Toy with greatest next play and swap some toys before it.
If you swap toy with the greatest next play, it's better that toys with less next play are still on the floor. And no need to 
swap in and out to play.
*/
/*
Another comment
This problem can be also solve by queue or list. List also support operation push and pop_front like queue.
You don't have to reverse vector if you use list. :)
*/
int main(){
    scanf("%d",&t);
    while(t--){
        priority_queue<pair<int,int>> q;
        scanf("%d%d%d",&n,&k,&p);
        for(int i=1;i<=n;i++){
            a[i].clear();
            b[i]=false;;
        }
        for(int i=1;i<=p;i++){
            scanf("%d",&v[i]);
            a[v[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)
            a[i].push_back(p+1);
        for(int i=1;i<=n;i++)
            reverse(a[i].begin(),a[i].end());
        ans=0,c=0;
        for(int i=1;i<=p;i++){
            if(b[v[i]]){
                a[v[i]].pop_back();
                q.push(make_pair(a[v[i]].back(),v[i]));
                continue;
            }
            if(c<k){
                b[v[i]]=true;
                a[v[i]].pop_back();
                ans++;
                c++;
                q.push(make_pair(a[v[i]].back(),v[i]));
            }
            else{
                auto it=q.top(); q.pop();
                b[it.second]=false;
                a[v[i]].pop_back();
                b[v[i]]=true;
                q.push(make_pair(a[v[i]].back(),v[i]));
                ans++;
            }
        }
        printf("%d\n",ans);
    }

}
