#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef long long ll;
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
void solve(std::string S){
    set<char> s;
    SORT(S);
    rep(i, S.size()){
        s.insert(S[i]);
    }
    vector<bool> a(26);
    for(auto c :s)a[c-'a']=true;
    rep(i, a.size()){
        if(a[i]==false){
            cout<<(char)('a'+i)<<endl;return;
        }
    }
    cout<<"None"<<endl;
}
int main(){
    int H,W;
    vector<string> A;
    cin>>H>>W;
    string ss="";
    rep(i, W+2)ss+='#';
    A.push_back(ss);
    rep(i, H){
        string s;cin>>s;
        s = "#"+s+"#";
        A.push_back(s);
    }
    A.push_back(ss);
    rep(i, H+2)cout<<A[i]<<endl;
    return 0
}
