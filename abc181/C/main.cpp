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
const string YES = "Yes";
const string NO = "No";
void solve(long long N, std::vector<long long> x, std::vector<long long> y){
    rep(i, N){
        rep(j, N){
            if(i!=j){
                float IJ = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
                rep(k, N){
                    float IK = sqrt(pow(x[i]-x[k],2)+pow(y[i]-y[k],2));
                    float JK = sqrt(pow(x[j]-x[k],2)+pow(y[j]-y[k],2));
                    // debug(IJ)debug(JK)debug(IK)
                    if(i!=j &&j!=k && i!=k){
                        // if(IJ+IK==JK || IJ+JK==IK || JK+IK==IJ){
                        if(y[i]*(x[j]-x[k]) + y[j]*(x[k]-x[i])+y[k]*(x[i]-x[j])==0){
                        // debug(i)debug(j)debug(k);
                        cout<<"Yes"<<endl;
                        return;
                        }
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
    return;
}
int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, std::move(x), std::move(y));
    return 0;
}
