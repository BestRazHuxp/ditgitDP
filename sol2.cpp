#include <bits/stdc++.h>
#define ll long long
#define se second
#define fi first
#define pb push_back
#define MASK(i) (1LL << (i))
#define sz(x) (int)(x).size()
#define BIT(x , i) ((x) >> (i) & 1)
#define all(x) (x).begin() , (x).end()
#define HowBigIs(x) setprecision(2) << fixed << sizeof(x) / 1000000.0 << " mb"
#define name "1"
#define task "SDIGIT"

using namespace std;
template <typename T1, typename T2> bool minimize(T1 &a, T2 b){if (a > b) {a = b; return true;} return false;}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b){if (a < b) {a = b; return true;} return false;}
const int inf = 1e9 + 7;
const ll linf = 1ll * inf * inf;
const int mod = 1e9 + 7;
const int maxn = 1e4 + 2;

void file(){if(fopen(task".inp" , "r")){freopen(task".inp" , "r" , stdin);freopen(task".out" , "w" , stdout);}else if(fopen(name".inp" , "r")){freopen(name".inp" , "r" , stdin);freopen(name".out" , "w" , stdout);}else if(fopen(task".in" , "r")){freopen(task".in" , "r" , stdin);freopen(task".out" , "w" , stdout);}}
string k;
int a[maxn];
ll dp[maxn][10][2][102];
int pw[maxn];
int n;
int d;
int main()
{
    file();
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    cin >> d;
    reverse(all(k));

    n = sz(k);
    for(int i = n - 1; i >= 0 ; i--) a[i] = k[i] - '0';
    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = 1ll * pw[i - 1] * 10 % d;
    dp[n][0][0][0] = 1;
    for(int i = 0; i < a[n - 1] ; i++)
        dp[n - 1][i][1][i % d]++;
    dp[n - 1][a[n - 1]][0][a[n - 1] % d]++;
    for(int k = n - 2; k >= 0 ; k--)
    {
       for(int m = 0 ; m < d; m++)
       {
            for(int i = 0 ; i < 10 ; i++)
            {
                for(int j = 0  ; j < 10 ; j++)
                dp[k][i][1][(m + i) % d] += dp[k + 1][j][1][m];
                dp[k][i][1][(m + i) % d] %= mod;
            }
            for(int i = 0 ; i < a[k] ; i++)
            {
                dp[k][i][1][(m + i) % d] += dp[k + 1][a[k + 1]][0][m];
                dp[k][i][1][(m + i) % d] %= mod;
            }
            dp[k][a[k]][0][(a[k] + m )% d] += dp[k + 1][a[k + 1]][0][m];
            dp[k][a[k]][0][(a[k] + m )% d] %= mod;
       }

    }
    ll res = 0;
    for(int i = 0 ; i < 10 ;i++)
    {
        res += 0ll + dp[0][i][0][0] + dp[0][i][1][0] ;
        res %= mod;
    }
    res = (res - 1 + mod) % mod;
    cout << res;
}
