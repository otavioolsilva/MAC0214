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
  int n, x;
  cin >> n >> x;

  int ans = -1, last = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    ans = max(ans, a-last);
    last = a;
  }

  ans = max(ans, 2*(x-last));

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

