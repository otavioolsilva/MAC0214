#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 5e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
  int n, q; cin >> n >> q;

  vector<int> queries(q);
  for(int &i : queries) cin >> i;

  // edges
  for(int i = 1; i < n; i++)
    cout << i << " " << i+1 << "\n";

  // queries
  int last = n-1, next;
  for(int &i : queries){
    if(i == last) cout << "-1 -1 -1\n";
    else cout << n << " " << last << " " << i << "\n";

    last = i;
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

