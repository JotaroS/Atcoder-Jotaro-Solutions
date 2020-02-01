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

void solve(std::string S, std::string T){
    map<char, int> s,t;
    for(char c = 'a'; c <='z'; c++){
        s[c]=-1;
        t[c]=-1;
    }
    REP(i, S.size()){
        s[S[i]]++;
        t[T[i]]++;
    }
    bool flag = true;
    for(char c = 'a'; c <='z'; c++){
        int cnt=0;
        for(char d = 'a'; d <='z'; d++){
            if(s[c]==t[d] && c!=d && t[d]!=0 &&s[c]!=1)cnt++;
            if(cnt>1){
                cout<<c<<'-'<<d<<endl;
                flag=false;
            }
        }
        if(cnt==0)flag=false;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() { 
    string S, T; cin >> S >> T;
    map<char, char> st;
    map<char, char> ts;

    REP(i, S.size()) {
        char x = S[i];
        char y = T[i];
        if (st.count(x) == 0) {
            st[x] = y;
        } else {
            if (st[x] != y) {
                cout << "No" << endl;
                return 0;
            }
        }
        if (ts.count(y) == 0) {
            ts[y] = x;
        } else {
            if (ts[y] != x) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}