#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e4+10;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f;

void solve(){
  int n; cin >> n;

  vector<int> coord(2*n);
  for(int &a : coord) cin >> a;

  sort(coord.begin(), coord.end());

  int ans = 0; vector<array<int, 2>> points(n);
  for(int i = 0, j = 0; i < 2*n; i++, j++){
    if(i == n) j = 0;

    points[j][i/n] = coord[i];
    if(j > 0) ans += abs(points[j][i/n] - points[j-1][i/n]);
  }

  cout << ans << "\n";
  for(auto& p : points)
    cout << p[0] << " " << p[1] << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

