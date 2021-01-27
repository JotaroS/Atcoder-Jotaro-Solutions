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


void solve(long long N, std::vector<std::string> s){
    int ab =0;
    int lb = 0;
    int ra = 0;
    int ralb = 0;
    REP(i, N){

        if(s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') ralb++;
        else if(s[i][0] == 'B') lb++;
        else if(s[i][s[i].size()-1] == 'A') ra++;
        REP(j, s[i].size()-1){
            if(s[i][j] == 'A' && s[i][j+1]=='B')ab++;
        }
    }
    if(lb ==0 && ra ==0){
        cout<<max(0,ralb-1)+ab<<endl;return;
    }
    else{
        int ret = ralb-1;
        lb--; ra--;
        
        if(lb>=0)ret++;
        if(ra>=0)ret++;
        ret+=max(0,min(ra,lb));
        cout<<ret+ab<<endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> s(N);
    for(int i = 0 ; i < N ; i++){
        std::cin >> s[i];
    }
    solve(N, std::move(s));
    return 0;
}
