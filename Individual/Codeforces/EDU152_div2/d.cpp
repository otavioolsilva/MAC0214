#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << ", ate aqui bao" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int n;
vector<int> arr;

int compute(){
  int ans = 0;
  bool block = false, used;

  for(int i = 0; i < n; i++){
    if(arr[i] == 1 && !block){
        block = true;

        if(i == 0) used = false;
        else used = true;

        ans++;
    } else if(arr[i] == 2){
      if(!block){
        block = true;
        ans++;
      }

      used = false;
    } else if(arr[i] == 0){
      if((!block || used) && (i + 1 == n || arr[i+1] == 0))
        ans++;

      block = false;
    }
  }

  return ans;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  arr.resize(n);

  for(int i = 0; i < n; i++)
    cin >> arr[i];

  if(n == 1){
    cout << "1\n";
    return 0;
  }

  int ans = compute();
  reverse(arr.begin(), arr.end());
  ans = min(compute(), ans);

  cout << ans << "\n";

  return 0;
}

