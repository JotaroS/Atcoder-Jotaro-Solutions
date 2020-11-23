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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int wx[8] = {-1,0,1,-1,1,-1,0,1};
int wy[8] = {-1,-1,-1,0,0,1,1,1};

int table[1010][1010];
char s[1010][1010];
int h, w;

int dfs(int x, int y, int val){ //x, y, warp_cnt
    int m =101010;
    table[x][y] = val;
    rep(i, 4){ // for all direction
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( nx >= 0 && nx < w && ny >= 0 && ny < h && table[nx][ny]==-1 &&s[nx][ny]=='.'){
            m = min(dfs(nx, ny, val), m);
            if(table[nx][ny]!=-1)m = min(table[nx][ny], m);
        }
    }
    rep(i, 8){
        int nx= x+wx[i];
        int ny= y+wy[i];
        if(nx >= 0 && nx < w && ny >= 0 && ny < h && table[nx][ny]==-1 && s[nx][ny]=='.'){
            m = min(dfs(nx, ny, val+1), m);
        }
    }
    return m;
}

int main(){
    // Failed to predict input format
    cin>>h>>w;
    int ch, cw,dh,dw; cin>>ch>>cw>>dh>>dw;    
    rep(i, h){
        rep(j, w){
            cin>>s[i][j];
            table[i][j] = -1;
        }
    }
    dh--; dw--; //0-index
    dfs(ch-1, cw-1, 0);
    rep(i, h){
        rep(j, w){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<table[dh][dw]<<endl;
    return 0;
}
