#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14159265
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);


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
/*---------------------------------------------------------*/
class graph
{
  public:
    ll n,r;
    set<string> nodes;
    vector < vector< pair<ll,ll> > > graphcon; //assuming only one edge between 2 nodes
    vector< string > names,relations;    //because having more does not make sense...
    graph(ll conn)
    {
       cin>>n;
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            nodes.insert(s);
            names.pb(s);
        }
        cin>>r;
        ll count=0;
         vector < vector< pair<ll,ll> > > graphconx(n); 
        for(ll i=0;i<r;i++)
        {
        ll arr[n][n];
            string s1;
            cin>>s1;
            relations.pb(s1);
            for(ll j=0;j<n;j++)
            {
                for(ll k=0;k<n;k++)
                {
                    cin>>arr[j][k];
                    if(arr[j][k]==1)
                    {
                        graphconx[j].pb({k,count});
                    }
                }
            }
            graphcon=graphconx;
            count++;
        }
        }
    void display_graph()
    {
        for(ll i=0;i<n;i++)
        {
            cout<<names[i]<<endl;
            for(ll j=0;j<graphcon[i].size();j++)
            {
                
               cout<<relations[graphcon[i][j].second]<<" "<<names[graphcon[i][j].first]<<endl; 
            }
            cout<<endl;
        }
    }
    void find_person(string s2)
    {
        if(nodes.find(s2)==nodes.end())
        {
            cout<<"NOT FOUND"<<endl;
        }
        else
        {
            cout<<"FOUND"<<endl;
        }
    }
    void find_path(string s1,string s2)
    {
        vector< pair<ll,ll> > parent(n);
        ll flag=0;
        ll source,dest;
        for(ll i=0;i<2;i++)
        {
            for(ll j=0;j<n;j++)
            {
             if(names[j]==s1)
             {
                 source=j;
             }
            if(names[j]==s2)
             {
               dest=j;     
             }
           }
          
            if(i==1)
            {
                swap(source,dest);
            }
             
            ll visited[n];
            for(ll j=0;j<n;j++)
            {
                visited[j]=0;
            }
            
            queue<ll> q;
            q.push(source);
            visited[source]=1;
            while(q.size()>0)
            {
                ll cvert=q.front();
               
                q.pop();
                for(ll j=0;j<graphcon[cvert].size();j++)
                {
                    if(visited[graphcon[cvert][j].first]==0)
                    {
                        q.push(graphcon[cvert][j].first);
                        visited[graphcon[cvert][j].first]=1;
                        parent[graphcon[cvert][j].first].first=cvert;
                        parent[graphcon[cvert][j].first].second=graphcon[cvert][j].second;
                    }
                }
            }
          
            if(visited[dest]==1)
            {
                flag=1;
                break;
            }
         }
        if(flag==0)
        {
            cout<<"NO PATH"<<endl;
        }
        else
        {
           
            vector< pair< ll,ll > > vs;
            ll temp=dest;
           while(temp!=source)
           {
               vs.pb(parent[temp]);
               temp=parent[temp].first;
           }
            for(ll j=vs.size()-1;j>=0;j--)
            {
                cout<<names[vs[j].first]<<" "<<relations[vs[j].second]<<" ";
            }
            cout<<names[dest]<<endl;
        }
        
        
    }
    
    
    friend ostream&operator<<(ostream&stream,graph obj);
    
};
ostream&operator<<(ostream&stream,graph obj)
{
  obj.display_graph();
return stream;
}



/*---------------------------------------------------------------------*/

int main()
{
  graph g(1); //creates a object of user defined type graph.... 
    cout<<"the graph is"<<endl;
    cout<<g; // overloaded << operator (prints the graph)
    cout<<endl;
  // cout<<"input name of the person you want to be found"<<endl;
  string k;
  cin>>k;
   g.find_person(k);
    cout<<endl;
   // cout<<"input 2 names to you want to find a path between"<<endl;
  string name1,name2;
    cin>>name1>>name2;
    cout<<endl;
    g.find_path(name1,name2); 
    
    
return 0;
}
/*--------------------------------------------------------------------*/




