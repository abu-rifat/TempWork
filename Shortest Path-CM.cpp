#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll,ll> >G[30009]; ///keeps the weighted graph
vector<ll>cycleReps; ///representatoor of cycles

ll parent[30009]; ///keeps the parents of each node
ll visited[30009]; ///node visit
ll dp[30009]; /// sum of the weight of each node

map<ll,ll>status; ///sub graph is cycle or not associated with the representator
map<ll,ll>With; ///number of connection of each node


void reset(ll n)
{
    cycleReps.clear();
    status.clear();
    With.clear();
    for(ll i=0; i<=n; i++)
    {
        parent[i]=0;
        visited[i]=0;
        dp[i]=0;
        G[i].clear();
    }
}

ll avg(ll n)
{
    if(n>=0)return n;
    else return -n;
}

void makeSet(ll n)
{
    parent[n]=n;
}

ll Find(ll Representative)
{
    if(parent[Representative]==Representative){
        return Representative;
    }
    return parent[Representative]=Find(parent[Representative]);
}

ll Union(ll a, ll b)
{
    ll u=Find(a);
    ll v=Find(b);
    if(u==v){
        status[u]=1;
        cycleReps.push_back(u);

    }else{
        parent[u]=v;
    }
}

ll Query(ll a, ll b)
{
    ll u=Find(a);
    ll v=Find(b);
    if(u==v){
        if(status[u]){
            ///if cycle

        }else{
            ///if not cycle
        }
    }else{
        return -1;
    }
}
ll subWeight(ll n)
{

    ll leng=G[n].size();
    for(ll i=0; i<leng;i++){
        ll u=G[n][i].first;

        if(!visited[u]){
            visited[n]=1;
            cout<<"U N :W "<<u+1<<" "<<n+1<<" "<<G[n][i].second<<endl;
            dp[n]=subWeight(u)+G[n][i].second;
            //dp[u]+=dp[n];
            //ll weig=G[n][i].second;
            //ll sc=subWeight(u,weig);
        }
    }
    cout<<"Serial : "<<n+1<<" "<<dp[n]<<endl;
    return dp[n];
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll T=1; T<=t; T++){
        ll n, e;
        cin>>n>>e;
        reset(n);
        for(ll i=0; i<=n; i++){
            makeSet(i);
        }
        for(ll i=0; i<e; i++){
            ll u,v,w;
            cin>>u>>v>>w;
            u--;v--;
            With[u]++;
            With[v]++;
            G[u].push_back({v,w});
            G[v].push_back({u,w});
            Union(u,v);
        }
        ll len=cycleReps.size();
        cout<<"Len : "<<len<<endl;
        for(ll i=0; i<len; i++){
            ll u=cycleReps[i];
            ll ww=subWeight(u);
        }
        for(ll i=0; i<n; i++)
        {
            if((!visited[i])&&(With[i]==1)){
                cout<<"Loop : "<<i+1<<endl;
                ll ww=subWeight(i);
                visited[i]=1;
            }
        }
        for(ll i=0; i<n; i++){
            cout<<"DP : "<<i+1<<" "<<With[i]<<" "<<dp[i]<<endl;
        }
        ///Query Part
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++){
            ll L, R;
            cin>>L>>R;
            L--;R--;
            ll ans=Query(L,R);
            cout<<ans<<endl;
        }
    }
    return 0;
}
