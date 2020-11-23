
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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define CLR(a) memset((a), 0 ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
bool compare_by_b(pair<LL, LL> a, pair<LL, LL> b) {
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}
std::uint32_t euclidean_gcd(std::uint32_t a, std::uint32_t b){return b != 0 ? euclidean_gcd(b, a % b) : a;}
void solve(long long N, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){
    vector< pair <long long, long long> > red;
    vector< pair <long long, long long> > blue;
    rep(i, N)red.push_back(MP(a[i],b[i]));
    rep(i, N)blue.push_back(MP(c[i],d[i]));
    int ret = 0;
    int ret2 = 0;
    rep(i, N){
        int cnt =0;
        rep(j, N){
            if(a[i]>c[j] || b[i]>d[j])cnt++;
        }
        ret = max(ret, cnt);
    }
    debug(ret)
    rep(i, N){
        int cnt =0;
        rep(j, N){
            if(c[i]<a[j] || d[i]<b[j])cnt++;
        }
        ret2 = max(ret, cnt);
    }
    cout<< ret2 << endl;
    debug(ret2);
}
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    std::vector<long long> b(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    std::vector<long long> c(N);
    std::vector<long long> d(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}
