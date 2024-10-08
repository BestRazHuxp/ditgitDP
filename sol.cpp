#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define mp make_pair
#define vi vector<int>
#define ld long double
#define ull unsigned ll
#define pii pair<int,int>
#define MASK(i) (1LL << (i))
#define sz(x) (int)(x).size()
#define BIT(x , i) ((x) >> (i) & 1)
#define all(x) (x).begin() , (x).end()
#define Times (1.0 * clock() / CLOCKS_PER_SEC)
#define show(x) cout << #x << " = " << x << '\n';
#define checkervn cout << "Real!\n"; else cout << "Fake!\n"
#define HowBigIs(x) to_string(sizeof(x) / 1000000.0) + " mb"
#define compress(x) sort(all((x))) , (x).erase(unique(all((x))) , (x).end())

using namespace std;

template <typename T1, typename T2> bool minimize(T1 &a, T2 b){if (a > b) {a = b; return true;} return false;}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b){if (a < b) {a = b; return true;} return false;}
const int inf = 1e9 + 7;
const ll linf = 1ll * inf * inf;
const int base = 31;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 2;

void setIO(string task, string i, string o, bool use)
{
    //if (!fopen((task + "." + i).c_str(), "r")) task = "1" , i = "inp", o = "out"; 
    if (fopen((task + "." + i).c_str(), "r") && use) {
        freopen((task + "." + i).c_str(), "r", stdin);
        freopen((task + "." + o).c_str(), "w", stdout);
    }
}
string x , y;
ll dp[100][2][2][2];
int trace[100][2][2][2];
ll dq(int i, bool ok , bool under , bool greater){
	ll &res = dp[i][ok][under][greater];
	if(res != -1) return res;
	if(i == sz(x)){
		return res = 1;
	}
	int hi = (under ? 9 : y[i] - '0');
	int lo = (greater ? 0 : x[i] - '0');
	for(int j = lo ; j <= hi ; j++){
		if(maximize(res , (!ok && !j ? 1 : j) * dq(i + 1, ok || j != 0 , under || j < hi , greater || j > lo))){
			trace[i][ok][under][greater] = j;
		}
	}  
	return res;
}
void t(int i , bool ok , bool under, bool greater){
	if(i == sz(x)) return;
	int j = trace[i][ok][under][greater];
	if(j || ok) cout << j;
	int hi = (under ? 9 : y[i] - '0');
	int lo = (greater ? 0 : x[i] - '0');
	t(i + 1, ok || j , under || j < hi , greater || j > lo);
}
void doo(const int &ts){
	cin >> x >> y;
	x = "0" + x;
	y = "0" + y;
	while(sz(x) < sz(y)) x = "0" + x;
    memset(dp, -1, sizeof dp);
	dq(1, 0 , 0 , 0);
    t(1, 0 , 0 , 0);
}
int main()
{
    setIO("odometer", "in", "out", true);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
	for(int i = 1; i <= t; i++) doo(i);
}
/* Keep typing, Keep loving Linh <3  */
