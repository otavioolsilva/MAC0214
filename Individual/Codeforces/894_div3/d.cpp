#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n; cin >> n;

  ll l = 2, r = 1500000000, mid, best = 1;

  auto eval = [&](ll x){ return x*(x-1)/2; };

  while(l <= r){
    mid = (l+r)/2;

    if(eval(mid) > n) r = mid-1;
    else {
      best = mid;
      l = mid+1;
    }
  }

  cout << best + (n-eval(best)) << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}
