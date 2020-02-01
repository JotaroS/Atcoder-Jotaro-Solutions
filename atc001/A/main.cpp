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

const string YES = "Yes";
const string NO = "No";
int H, W;
char m[500][500];
int sy, sx;
int gy, gx;

bool dfs(int y, int x){
    if(x<0 || y<0 || x>=W || y>=H)return false;
    if(x==gx && y==gy){
        return true;
    }
    if(m[y][x] =='#')return false;
    m[y][x]='#';
    if(dfs(y+1,x))return true;
    if(dfs(y-1,x))return true;
    if(dfs(y,x+1))return true;
    if(dfs(y,x-1))return true;
    return false;
}

int main(){
    // Failed to predict input format
    cin>>H>>W;
    REP(i, H){
        REP(j, W){
            cin>>m[i][j];
            if(m[i][j]=='s'){
                sy=i;sx=j;
            }
            if(m[i][j]=='g'){
                gy=i;gx=j;
            }
        }
    }
    // dfs(sy,sx);
    if(dfs(sy, sx))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    

    return 0;
}
