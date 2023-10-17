#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e5+10;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

using coord = long double;
const long double pi = acos(-1);
const coord EPS = 1e-8;

int sign(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point p){ x = p.x, y = p.y; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(tht)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){ return point(-y, x);}
	inline point rot(long double ang){ return point(cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y); 		}
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }
	
	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct circle{
	point c; coord r;
	circle() {} circle(point _c, coord _r): c(_c), r(_r) {}

	vector<point> get_tan(point p){ // tangent points
		long double d2 = (c - p).norm2();
		if (sign(d2 - r * r) < 0) return {};
		if (sign(d2 - r * r) == 0) return {p};
		long double tht = acos(sqrt((r*r)/d2));
		point vec = ((p - c)/(p - c).norm()) * r;
		return {c + vec.rot(tht),c + vec.rot(-tht)};
	}
};	

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  point current, destination;
  cin >> current.x >> current.y;
  cin >> destination.x >> destination.y;

  circle blue, red;
  cin >> blue.c.x >> blue.c.y >> blue.r;
  cin >> red.c.x >> red.c.y >> red.r;

  vector<point> current_tan = red.get_tan(current),
                destination_tan = red.get_tan(destination);

  long double ans = INF;
  int dx[4] = {0, 0, 1, 1}, dy[4] = {0, 1, 0, 1};

  for(int k = 0; k < 4; k++){
    long double aux = 0;

    aux += (current - current_tan[dx[k]]).norm();
    aux += (destination_tan[dy[k]] - destination).norm();

    long double dist2_tan = (current_tan[dx[k]] - destination_tan[dy[k]]).norm2();

    aux += red.r * acos(1.0 - (dist2_tan/(2.0 * red.r * red.r)));

    ans = min(ans, aux);
  }

  cout << fixed << setprecision(10) << ans << "\n";

  return 0;
}

