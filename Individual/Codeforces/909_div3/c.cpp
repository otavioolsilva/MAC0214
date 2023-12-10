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

int calc(vector<int> &arr, int l, int r){
  int best = arr[l], now = arr[l];

  for(int i = l+1; i <= r; i++){
    if(now + arr[i] < arr[i]) now = arr[i];
    else now += arr[i];

    best = max(best, now);
  }

  return best;
}

void solve(){
  int n; cin >> n;

  vector<int> arr(n+1, 0), acc(n+1, 0), cut;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    acc[i] = acc[i-1] + arr[i];

    if(i == 1 || (arr[i]&1) == (arr[i-1]&1)) cut.push_back(i-1);
  }
  cut.push_back(n);

  int ans = -INF;
  for(int i = 0; i < cut.size()-1; i++)
    ans = max(ans, calc(arr, cut[i]+1, cut[i+1]));

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

