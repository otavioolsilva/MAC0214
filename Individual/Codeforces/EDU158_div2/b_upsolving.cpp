#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e4+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;

void solve(){
  int n; cin >> n;

  vector<int> ribbon(n);
  for(int &c : ribbon) cin >> c;

  ll ans = ribbon[0]-1;
  for(int i = 1; i < n; i++)
    ans += max(0, ribbon[i]-ribbon[i-1]);

  cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

