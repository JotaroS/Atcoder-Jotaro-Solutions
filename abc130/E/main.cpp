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

const long long MOD = 1000000007;

void solve(long long N, long long M, std::vector<long long> S,
           std::vector<long long> T) {}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> S(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &S[i]);
  }
  std::vector<long long> T(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &T[i]);
  }
  solve(N, M, std::move(S), std::move(T));
  return 0;
}
