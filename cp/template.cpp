#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clz
#define ctz __builtin_ctz
#define cnz __builtin_popcount
#define clmsb __builtin_clrsb
#define bitswap __builtin_bswap32

#define clzl __builtin_clzll
#define ctzl __builtin_ctzll
#define cnzl __builtin_popcountll
#define clmsbl __builtin_clrsb
#define bitswapl __builtin_bswap64

#define mod       1000000007
#define mods      998244353
#define all(x)    (x).begin(), (x).end()
#define FIO()     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define repeat    int t;cin>>t;while(t--)
#define ll        long long

vector<int>spf(int n){vector<int>ans(n+1);for(int i=2;i<=n;i++){if(!ans[i]){ans[i]=i;for(int j=i*i;j<=n;j+=i)if(!ans[j])ans[j]=i;}}return ans;}
string binary(ll n){string s;while(n){s.push_back(n%2+'0');n/=2;}reverse(s.begin(),s.end());return s;}
ll power(ll x,unsigned ll y,ll m){ll res=1;x=x%m;if(x==0)return 0;while(y>0){if(y&1)res=(res*x)%m;y=y>>1;x=(x*x)%m;}return res;}
ll mod_inverse(ll a,ll p){return power(a,p-2,p);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
ll mod_div(ll a,ll b,ll m){a=a%m;b=b%m;return(mod_mul(a,mod_inverse(b,m),m)+m)%m;}

#if !defined(ONLINE_JUDGE) && 1
#define dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

template <class T> void _print(T t) {cerr << t;}
void _print(string t) {cerr << '"' << t << '"';}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


int main() {
  FIO();
  repeat {

  }
}
