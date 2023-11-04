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

  vector<int> arr(n);
  for(int &a : arr) cin >> a;

  sort(arr.begin(), arr.end());

  ll ans = 0, acc = 0;
  int i = 0, j = n-1;
  while(i < j){
    if(arr[i] + acc < arr[j]){
      ans += arr[i];
      acc += arr[i];
      arr[i] = 0;
      i++;
    } else {
      arr[i] -= arr[j]-acc;
      ans += arr[j]-acc;
      arr[j] = 0;
      j--;
      ans++;
      acc = 0;
    }
  }

  if(arr[i] > 0){
    if(arr[i] > 1) ans += (arr[i]-acc+1)/2;
    ans++;
  }

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

