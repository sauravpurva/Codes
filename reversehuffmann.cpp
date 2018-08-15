#include<bits/stdc++.h>
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
ll arr[5000001];
int main()
{
  vector< vector<string> > v(101); // to categorize codes based on their size XD
    map<string,string> m; // mapping of what code is linked with what character
    cout<<"enter no. of characters"<<endl;
    ll n;
    cin>>n;
    cout<<"enter the character and the respective code"<<endl;
    // following lines of code are just for input..
    for(ll i=0;i<n;i++)
    {
        string code,character;
        cin>>character;
        cin>>code;
        pair<string,string> p;
        p.first=code;
        p.second=character;
        m.insert(p);
        v[code.size()].pb(code);
    }
   vector<ld> probability; // for probabilities
    for(ll i=0;i<n;i++)
    {
        ld x;
        cin>>x;
        probability.pb(x);
    }
    sort(probability.begin(),probability.end());
    ll k=probability.size()-1;
    
    
    // Heart of the algorithm
    // assigns respective characters their probabilities
    // involves a bit of sorting and decrement operations XD
   for(ll i=0;i<v.size();i++)
    {
        if(v[i].size()>0)
        {
            sort(v[i].begin(),v[i].end());
            for(ll j=v[i].size()-1;j>=0;j--)
            {
                cout<<m[v[i][j]]<<" "<<probability[k]<<endl;
                k--;
            }
        }
    }
    // all done
    return 0;
}