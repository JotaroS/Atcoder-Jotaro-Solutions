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

void solve(long long A, long long B, long long C, long long D) {
  int a = B/C - A/C;
  int b = B/D - A/D;
  int c = B/(C*D) - A/(C*D);
  cout<<a+b-c<<endl;
}
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

LL gcd(LL m, LL n){
  LL temp;
  while(n!=0){
    temp=n;  // t=2 1
    n = m%n; // n=1 0
    m=temp;  // m=2 1
  }
  return m;
}

LL lcm(LL m,LL n){
  return m*n/gcd(m,n);
}
int main() {
  LL A,B;
  LL C,D;
  cin>>A>>B>>C>>D;
  A--;
  A -= (A/C)+(A/D)-A/lcm(C,D);
  B -= (B/C)+(B/D)-B/lcm(C,D);
  cout<<B-A<<endl;
  return 0;
}

/*


1 10 2 3

1 2' 3' 4' 5 6'' 7 8' 9' 10
10 - (10/2);
10 - (10/3);

10+10/lcm(2,3);

4' 5 6' 7 8' 9' : 2

1 2 3 4: 1

1 2' 3' 4' 5 6' 7 8' 9'
*/