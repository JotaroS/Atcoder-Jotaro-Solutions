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

string L[4] = {"A","B","X", "Y"};
string R[4] = {"A","B","X", "Y"};
int main(){
    // Failed to predict input format
    int n; cin>>n;
    string s; cin>>s;

    int ans = 2147483647;
    rep(i, 4){
        rep(j, 4){
            rep(k, 4){
                rep(m, 4){
                    string l = L[i]+L[j];
                    string r = R[k]+R[m];
                    //first search l then r;
                    // string out="";
                    string out = "";
                    rep(q, s.length()){
                        if(q<s.length()-1 && s[q]==l[0] && s[q+1]==l[1]){
                            out += "l";q++;
                        }
                        else if(q<s.length()-1 &&  s[q]==r[0] && s[q+1]==r[1]){
                            out += "r";q++;
                        }
                        else out+=s[q];
                    }
                    ans = min(ans, (int)out.length());
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
