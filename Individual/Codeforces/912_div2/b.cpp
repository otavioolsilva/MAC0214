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
  int n; cin >> n;

  vector<vector<ll>> mat(n, vector<ll>(n));
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> mat[i][j];

  if(n == 1){
    cout << "YES\n7\n";
    return;
  }

  vector<ll> candidates(n, 0);

  for(int i = 0; i < n; i++){
    if(i == 0) candidates[i] = mat[i][1];
    else candidates[i] = mat[i][0];

    for(int j = 1; j < n; j++){
      if(i == j) continue;
      candidates[i] = (candidates[i] & mat[i][j]);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      
      if((candidates[i] | candidates[j]) != mat[i][j]){
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
  for(int i = 0; i < n; i++)
    cout << candidates[i] << " ";
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

