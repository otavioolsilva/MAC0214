#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 8010;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
  int n; cin >> n;

  vector<int> bt(n+1, 0);
  for(int i = 1; i <= n; i++){
    char c; cin >> c;
    bt[i] = (c == '1' ? 1 : 0);
  }

  int q; cin >> q;

  vector<int> pressed(n+1, 0);
  for(int i = 1; i <= q; i++){
    int b; cin >> b;
    pressed[b] ^= 1;
  }

  for(int i = 1; i <= n; i++)
    if(pressed[i])
      for(int j = i; j <= n; j += i)
        bt[j] ^= 1;

  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(bt[i]){
      ans++;
      for(int j = i; j <= n; j += i)
        bt[j] ^= 1;
    }
  }

  cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

