
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
#include <queue>
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
void solve(long long N, long long M, long long K, std::vector<long long> A, std::vector<long long> B){
    queue<int> que_a;
    queue<int> que_b;
    rep(i, N)que_a.push(A[i]);
    rep(i, M)que_b.push(B[i]);

    int sum =0;
    int ret =0;
    int choice = 0;
    bool flag;
    if(que_a.front() < que_b.front()){
        flag = true;
        choice = que_a.front();
    }
    else
    {
        flag= false;
        choice = que_b.front();
    }
    while(sum+choice<=K){
        if(flag)if(!que_a.empty())que_a.pop();
        else if(!que_b.empty()) que_b.pop();
        sum += choice;
        ret++;
        if(que_a.empty() && que_b.empty())break;
        else if(que_a.empty())choice = que_b.front();
        else if(que_b.empty()) choice = que_a.front();
        else if(que_a.front() < que_b.front()){
        flag = true;
        choice = que_a.front();
        }
        else
        {
            flag= false;
            choice = que_b.front();
        }
    }
    cout<<ret<<endl;
}
int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> B(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&B[i]);
    }
    solve(N, M, K, std::move(A), std::move(B));
    return 0;
}
