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
void solve(string S){
    
    

    if(S.length()==1){
        int r = (int)(S[0]-'0');
        if(r==8){cout<<"Yes"<<endl;return;}
        else{cout<<"No"<<endl;return;}
        return;
    }
    else if(S.length()==2){
        int r = (int)(S[1]-'0')*10 + (int)(S[0]-'0');
        int l = (int)(S[0]-'0')*10 + (int)(S[1]-'0');
        if(r%8==0 || l%8==0){cout<<"Yes"<<endl;return;}
        else{cout<<"No"<<endl;return;}
        return;
    }
    int m[10];
    rep(i,10)m[i]=0;
    rep(i, S.length()){
        m[(int)(S[i]-'0')]++;
    }
    rep(i, 1000){
        if(i % 8 ==0){
            int one = i%10;
            int two = (i%100)/10;
            int three =i/100;
            int _m[10];
            memcpy(_m, m, sizeof(m));
            int a = min(1,_m[one]);
            _m[one]--;
            int b = min(1,_m[two]);
            _m[two]--;
            int c = min(_m[three],1);
            _m[three]--;
            // debug(one)debug(two)debug(three)debug(i)
            if(a+b+c>=3 && i >=100){
                debug(i)
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
    
}
int main(){
    string S;
    cin>>S;
    solve(S);
    return 0;
}
