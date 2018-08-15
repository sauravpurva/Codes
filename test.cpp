#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define a first
#define b second

/*-------------------------------------------------------- */
typedef long double ld;
typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}
vector< vector< pair<ll,ll> > > graphx;
vector<ll> markedx;
void dfs(ll x)
{
    cout<<x<<" ";
    markedx[x]=1;
        for(ll i=0;i<graphx[x].size();i++)
        {
            if(markedx[graphx[x][i].a]==0)
            {
                markedx[graphx[x][i].a]=1;
                dfs(graphx[x][i].a);
            }
        }
}
ll findset(ll x,ll arr[])
{
    
    while(arr[x]>0)
    {
        x=arr[x];
    }
    return x;
}
/*---------------------------------------------------------*/
int main()
{
/*---------------------------------------------------------*/
// taking the weighted graph input....
    ll n,E;
    cout<<"enter the no. of vertices"<<endl;
    cin>>n;
    cout<<"enter the no. of edges"<<endl;
    cin>>E;
    cout<<"enter the edges(x,y,w)  x->first vertex, y->second vertex, z->weignt between edge(x,y)"<<endl;
vector< vector< pair<ll,ll> > > graph(n+1);
    vector< pair< ll, pair<ll,ll> > > v;
    for(ll i=0;i<E;i++)
    {
        pair<ll,ll> p1,p2;
        pair<ll, pair<ll,ll> > p3;
        ll x,y,w;
        cin>>x>>y>>w;
        p3.a=w;
        (p3.b).a=x;
        (p3.b).b=y;
        v.pb(p3);
        p1.a=y;
        p1.b=w;
        p2.a=x;
        p2.b=w;
        graph[x].pb(p1);
        graph[y].pb(p2);
    
    }
    graphx=graph;
/*---------------------------------------------------------*/
  //BFS
    cout<<"enter the vertex for bfs traversal"<<endl;
    ll x;
    cin>>x;
    vector<ll> marked(n+1);
    for(ll i=1;i<=n;i++)
    marked[i]=0;
    markedx=marked;
    queue<ll> q;
    q.push(x);
    marked[x]=1;
    cout<<"bfs traversal"<<endl;
    while(q.size()>0)
    {
        cout<<q.front()<<" ";
         ll a1=q.front();
        q.pop();
       for(ll i=0;i<graph[a1].size();i++)
        {
            if(marked[graph[a1][i].a]==0)
            {
                q.push(graph[a1][i].a);
                marked[graph[a1][i].a]=1;
            }
        }
        
    }
    cout<<endl;
/*---------------------------------------------------------*/
    //DFS
     cout<<"enter the vertex for dfs traversal"<<endl;
    cin>>x;
    cout<<"dfs traversal"<<endl;
    dfs(x);
   
/*---------------------------------------------------------*/
    //kruskal
    sort(v.begin(),v.end());
    ll count=0;
    ll k=0;
    ll dsu[n+1];
    for(ll i=0;i<=n;i++)
        dsu[i]=-1;
    
    
    cout<<endl<<"Minimun spamming tree is:"<<endl;
    
    while(count<n-1)
    {
        ll a1,a2;
       // cout<<(v[k].b).a<<":::::::::"<<(v[k].b).b<<endl;
        a1=findset((v[k].b).a,dsu);
        a2=findset((v[k].b).b,dsu);
        //cout<<a1<<" "<<a2<<endl;
        if(a1!=a2)
        {
             if(dsu[a1]==dsu[a2])
             {
                 dsu[a1]=a2;
                 dsu[a2]-=1;
             }
            else if(dsu[a1]>dsu[a2])
            {
                dsu[a1]=a2;
                dsu[a2]-=1;
            }
            else if(dsu[a1]<dsu[a2])
            {
                dsu[a2]=a1;
                dsu[a1]-=1;
            }
            count++;
            cout<<" vertex1: "<<(v[k].b).a<<" vertex2: "<<(v[k].b).b<<" weight: "<<v[k].a<<endl;
            
        }
        k++;
    }
    /*---------------------------------------------------------*/
     return 0;
}