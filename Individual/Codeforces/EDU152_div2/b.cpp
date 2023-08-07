#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << ", ate aqui bao" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

vector<pair<int, int>> arr;

void solve(){
  int n, k; cin >> n >> k;
  
  arr.resize(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i].first;

    arr[i].first %= k;

    arr[i].second = i+1;
  }

  sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b){
    if(a.first == b.first) return a.second < b.second;
    if(a.first == 0) return true;
    if(b.first == 0) return false;
    return a.first > b.first;
  });

  for(int i = 0; i < n; i++)
    cout << arr[i].second << " ";
  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

