#include<stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
 
 
using namespace std;
 
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


unsigned gcd(unsigned a, unsigned b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

LL lcm(LL a, LL b) {
	int g;
	g = gcd(a, b);
    // cout<<g<<endl;
	return a*b/g;
}
LL lcm_n(vector<LL> &numbers) {
	LL l;
	l = numbers[0];
	for (LL i = 1; i < numbers.size(); i++) {
		l = lcm(l, numbers[i]);
	}
	return l;
}
LL gcd_n(vector<LL> numbers){
    LL l;
	l = numbers[0];
	for (LL i = 1; i < numbers.size(); i++) {
		l = gcd(l, numbers[i]);
	}
	return l;
}

void solve(long long N, long long X, std::vector<long long> x){ 
    LL min_diff = 100000000;
    x.PB(X);
    SORT(x);
    vector<LL>diffs;
    REP(i, N){
        LL diff = abs(x[i]-x[i+1]);
        diffs.PB(diff);
    }
    // REP(i, N){
    //     cout<<diffs[i]<<",";
    // }cout<<endl;
    LL val = gcd_n(diffs);
    cout<<val<<endl;
    // int dist = min(X-x[0], x[N-1]-X);
    // int dist2 = max(X-x[0], x[N-1]-X);
    // int ans = 2 * dist/val + dist2/val;
    // cout<<ans<<endl;

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    std::vector<long long> x(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
    }
    solve(N, X, std::move(x));
    return 0;
}
