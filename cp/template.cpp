#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clz
#define ctz __builtin_ctz
#define cnz __builtin_popcount
#define clmsb __builtin_clrsb
#define bitswap __builtin_bswap32

#define clzl __builtin_clzl
#define ctzl __builtin_ctzl
#define cnzl __builtin_popcountl
#define clmsbl __builtin_clrsb
#define bitswapl __builtin_bswap64

#define mod       1000000007
#define mods      998244353
#define all(x)    (x).begin(), (x).end()
#define pwp(x,y)  fixed<<setprecision(y)<<x
#define FIO()     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define repeat    int t;cin>>t;while(t--)

vector<int>sieve(int n){int*arr=new int[n+1];vector<int>vect;for(int i=2;i<=n;i++)if(arr[i]==0){vect.push_back(i);for(int j=2*i;j<=n;j+=i)arr[j]=1;}free(arr);return vect;}
int power(int x,unsigned int y,int m){int res=1;x=x%m;if(x==0)return 0;while(y>0){if(y&1)res=(res*x)%m;y=y>>1;x=(x*x)%m;}return res;}
int mod_inverse(int a,int p){return power(a,p-2,p);}
int mod_add(int a,int b,int m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
int mod_mul(int a,int b,int m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
int mod_sub(int a,int b,int m){a=a%m;b=b%m;return(((a-b)%m)+m)%m;}
int mod_div(int a,int b,int m){a=a%m;b=b%m;return(mod_mul(a,mod_inverse(b,m),m)+m)%m;}

string binary(int n) {
    string s;
    while (n) {
        s.push_back(n % 2 + '0');
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}


#if !defined(ONLINE_JUDGE) && 1
#define dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

template <class T> void _print(T t) {cerr << t;}
void _print(string t) {cerr << '"' << t << '"';}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


int main() {
    FIO();
    //repeat {}
    vector<string> v(5, "hi");
    dbg(v);

    return 0;
}
