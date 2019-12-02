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

void solve(int X, int Y, int Z, int K,
           std::vector<long long> A, std::vector<long long> B,
           std::vector<long long> C) {
            SORT(A);
            SORT(B);
            SORT(C);
            std::reverse(A.begin(),A.end()); 
            std::reverse(B.begin(),B.end()); 
            std::reverse(C.begin(),C.end()); 
            vector<unsigned long long> res;
            vector<long long> a;
            vector<long long> b;
            vector<long long> c;
            for(int i=0; i<min(X,200); i++){
              a.PB(A[i]);
            }
            for(int i=0; i<min(Y,200); i++){
              b.PB(B[i]);
            }
            for(int i=0; i<min(Z,200); i++){
              c.PB(C[i]);
            }
            REP(i, min(X,200)){
              REP(j, min(Y,200)){
                REP(k, min(Z,200)){
                  res.PB(a[i]+b[j]+c[k]);
                }
              }
            }
            SORT(res);
            std::reverse(res.begin(),res.end()); 
            for(int i=0; i<K; i++){
              cout<<res[i]<<endl;
            }
           }

int main() {
  int X;
  scanf("%d", &X);
  int Y;
  scanf("%d", &Y);
  int Z;
  scanf("%d", &Z);
  int K;
  scanf("%d", &K);
  std::vector<long long> A(X);
  for (int i = 0; i < X; i++) {
    scanf("%lld", &A[i]);
  }
  std::vector<long long> B(Y);
  for (int i = 0; i < Y; i++) {
    scanf("%lld", &B[i]);
  }
  std::vector<long long> C(Z);
  for (int i = 0; i < Z; i++) {
    scanf("%lld", &C[i]);
  }
  solve(X, Y, Z, K, std::move(A), std::move(B), std::move(C));
  return 0;
}
