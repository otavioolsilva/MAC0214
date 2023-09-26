#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

vector<ll> acc(MAXN);

void solve(){
  ll n, k, x;
  cin >> n >> k >> x;

  if(acc[k] > x || acc[n] - acc[n-k] < x) cout << "NO\n";
  else cout << "YES\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  acc[0] = 0;
  for(int i = 1; i < MAXN; i++)
    acc[i] = i + acc[i-1];

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

