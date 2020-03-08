#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll, pair<ll,ll> > >Edges; //first->u, first.first->v, first.second->w
vector<ll>G[30009]; //
ll parent[30009];
map<ll,ll>status,sum;
map<pair<ll,ll>,ll>weight;
vector<ll>cycleReps;
ll visited[30009];
ll dp[30009]; /// sum of the weight of the cycle.

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

ll dfs(ll a, ll b)
{
    if(a==b) return 0;
    ll len=
}

ll Query(ll a, ll b)
{
    ll u=Find(a);
    ll v=Find(b);
    if(u==v){
        if(status[u]){
            ll ans1=sum[u];
            ll ans2=dfs(a,b);
            return min(ans1,ans2);

        }else{
            ll ans=dfs(a,b);
            return ans;
        }
    }else{
        return -1;
    }
}
ll subWeight(ll n)
{
    visited[n]=1;
    ll ct=0;
    ll leng=G[n].size();
    for(ll i=0; i<leng;i++){
        ll u=G[n][i];
        if(!visited[u]){
            return dp[n]=dp[n]+weight[make_pair(n,u)]+subWeight(u);
        }
    }
    return dp[n];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll T=1; T<=t; T++){
        ll n, e;
        cin>>n>>e;
        for(ll i=0; i<=n; i++){
            makeset(i);
        }
        for(ll i=0; i<e; i++){
            ll u,v,w;
            cin>>u>>v>>w;
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
            weight[make_pair(u,v)]=w;
            weight[make_pair(v,u)]=w;
            Union(u,v);
        }
        ll len=cycleReps.size();
        for(ll i=0; i<len; i++){
            ll u=cycleReps[i];
            ll ww=subWeight(u);
            sum[cycleReps[i]]=ww;
        }
        ///Query Part
        ll q;
        cin>>q;
        for(ll i=0; i<q; i++){
            ll L, ll R;
            cin>>L>>R;
            L--;R--;
            ll ans=Query(L,R);
            cout<<ans<<endl;
        }
    }
    return 0;
}
