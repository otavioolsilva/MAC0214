#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n; cin >> n;

  vector<int> a(n), aux; aux.reserve(n);
  for(int& i : a)
    cin >> i;

  if(a[0] != n){ cout << "NO\n"; return; }

  for(int i = 1, j = n-1; i <= n; i++){
    while(j > 0 && a[j] < i){
      j--;
    }

    aux.push_back(j+1);
  }

  for(int i = 0; i < n; i++){
    if(aux[i] != a[i]){
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}
