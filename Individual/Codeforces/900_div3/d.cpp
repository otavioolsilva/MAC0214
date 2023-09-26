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

int n, k, q;
string s;
vector<int> l, r, acc;

void solve(){
  cin >> n >> k;
  cin >> s;

  l.resize(k+1); l[0] = 0; r.resize(k+1); r[0] = 0;
  for(int i = 1; i <= k; i++) cin >> l[i];
  for(int i = 1; i <= k; i++) cin >> r[i];

  acc.assign(n+2, 0);

  cin >> q;
  while(q--){
    int x; cin >> x;
    int pos = lower_bound(r.begin(), r.end(), x) - r.begin();

    acc[min(x, r[pos] + l[pos] - x)] += 1;
    acc[max(x, r[pos] + l[pos] - x) + 1] -= 1;
  }

  for(int i = 2; i <= n; i++)
    acc[i] += acc[i-1];
  
  for(int i = 1; i <= k; i++)
    for(int j = l[i]; j < (r[i] + l[i] + 1)/2; j++)
      if(acc[j]&1)
        swap(s[j - 1], s[r[i] + l[i] - j - 1]);

  cout << s << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

