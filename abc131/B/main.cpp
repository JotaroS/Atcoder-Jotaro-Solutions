#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// conversion
//------------------------------------------
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

// math
//-------------------------------------------
template <class T> inline T sqr(T x) { return x * x; }

// typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

// container util
//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i, c)                                                             \
  for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

// repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

// clear memory
#define CLR(a) memset((a), 0, sizeof(a))

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                                               \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"                       \
       << " " << __FILE__ << endl;

void solve(long long N, long long L) {
  int m=10000000;
  int dec=0;
  bool flag=false;
  int sum=0;
  for(int i=1; i<N+1; i++){
    int cur = L+i-1;
    // cout<<cur<<endl;
    if(m>abs(cur)){
      dec=cur;
      m=abs(cur);
    }
    sum+=cur;
  }
  cout<<sum-dec<<endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long L;
  scanf("%lld", &L);
  solve(N, L);
  return 0;
}
