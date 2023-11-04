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

vector<array<int, 3>> queries;
vector<vector<int>> adj;

vector<pair<int, int>> range;
vector<ll> st;

vector<ll> ans;

void dfs(int u, int p, int &clk){
  range[u].first = clk++;

  for(int v : adj[u]) if(v != p)
    dfs(v, u, clk);

  range[u].second = clk++;
}

void st_update(int pos, int l, int r, int x, int k){
  if(r < range[x].first || range[x].second < l) return;
  if(range[x].first <= l && r <= range[x].second){
    st[pos] += k;
    return;
  }

  int m = (l+r)/2;
  st_update(pos*2, l, m, x, k);
  st_update(pos*2+1, m+1, r, x, k);
}

ll st_query(int pos, int l, int r, int x){
  if(r < x || x < l) return 0;
  if(l == r) return st[pos];

  int m = (l+r)/2;
  return st[pos] + st_query(pos*2, l, m, x) + st_query(pos*2+1, m+1, r, x);
}

void solve(){
  int n = 1;
  int q; cin >> q;

  queries.resize(q);
  adj.clear();
  adj.resize(q+10);

  for(auto &qry : queries){
    cin >> qry[0];

    if(qry[0] == 1){
      cin >> qry[1];
      n++;

      adj[qry[1]].push_back(n);
      adj[n].push_back(qry[1]);
    } else cin >> qry[1] >> qry[2];
  }

  range.resize(n+10);
  st.assign(8*n+10, 0);

  int clk = 1;
  dfs(1, 1, clk);

  ans.resize(n+1);
  for(int i = q-1, j = n; i >= 0; i--){
    if(queries[i][0] == 1){
      ans[j] = st_query(1, 1, 2*n, range[j].first);
      j--;
    } else {
      st_update(1, 1, 2*n, queries[i][1], queries[i][2]);
    }
  }

  ans[1] = st_query(1, 1, 2*n, range[1].first);

  for(int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

