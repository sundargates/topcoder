#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <ctime>
#include <cstring>
#include <climits>

#include <sstream>
#include <typeinfo>
#include <fstream>
using namespace std;

#define FOR(i,x,y) for(int i=x; i<=y; i++)
#define FORN(i,n) FOR(i,0,(n-1))
#define FORE(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define db(x) 
// cout << (#x) << " = " << x << endl;
#define CLR(x) memset(x,0,sizeof(x));
#define sz(x) ((int)x.size())
#define mp make_pair
#define pb push_back
#define re return
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

class WinterAndReindeers {
    public:
    vector<string> allA; 
    vector<string> allB; 
    vector<string> allC; 

    int dp[2501][2501];
    string tA, tB, tC;
    int lcs_helper(int leftA, int rightA, int leftB, int rightB) {

        if (leftA >= tA.length())
            return 0;

        if (leftB >= tB.length())
            return 0;

        // db(leftA);
        // db(leftB);
        // db(rightA);
        // db(rightB);

        int res = 0;
        if ( (rightA - 1) >= 0 && (rightB - 1) >= 0) {
            db(dp[rightA-1][rightB-1]);
            res += dp[rightA-1][rightB-1];
        }
        if ((leftA - 1) >= 0 && (leftB - 1) >= 0) {
            db(dp[leftA - 1][leftB - 1]);
            res -= dp[leftA - 1][leftB - 1];
        }

        return res;
    }
    int lcs (string A, string B) {
        if (!A.length())
            return 0;

        if (!B.length())
            return 0;

        memset(dp, 1, sizeof dp);
        FORN(i, A.length()) {
            FORN(j, B.length()) {
                if (A[i] == B[j]) {
                    if (i-1>=0 && j-1>=0) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    else {
                        dp[i][j] = 1;
                    }
                } else {
                    int res = 0;
                    if(i-1>=0)
                        res = max(res, dp[i-1][j]);
                    if (j-1 >=0)
                        res = max(res, dp[i][j-1]);
                    dp[i][j] = res;
                }

            }
        }
        return dp[A.length()-1][B.length()-1];
    }

    int subsequence_helper(string A, string B, int pos) {
        int index = 0;
        FOR(i, pos, A.length()-1) {

            if (A[i] == B[index]) {
                index++;
            }

            if (index == B.length()) {
                return i;
            }
        }
        return -1;
    }
    std::vector<ii> subsequence(string A, string B) {
        std::vector<ii> res;
        FORN(i, A.length()) {
            if (A[i]==B[0]) {
                int t = subsequence_helper(A, B, i);
                if (t != -1)
                    res.pb(mp(i, t));
            }
        }
        return res;
    }
    void display(std::vector<ii> v) {
        FORN(i, sz(v)) {
            db(v[i].first);
            db(v[i].second);
        }
    }
    int getNumber(vector<string> allA, vector<string> allB, vector<string> allC) {

        this->allA = allA; 
        this->allB = allB; 
        this->allC = allC; 

        tA = ""; FORN(i, sz(allA)) tA += allA[i];
        tB = ""; FORN(i, sz(allB)) tB += allB[i];
        tC = ""; FORN(i, sz(allC)) tC += allC[i];

        vector<ii> posA = subsequence(tA, tC);
        if (!sz(posA))
            return 0;

        std::vector<ii> posB = subsequence(tB, tC);
        if (!sz(posB))
            return 0;

        lcs (tA, tB);

        unsigned long res = 0;
        FORN(i, sz(posA)) {
            FORN(j, sz(posB)) {
                // string leftA = tA.substr(0, posA[i].first);
                // string leftB = tB.substr(0, posB[j].first);
                int left_ = lcs_helper(0, posA[i].first, 0, posB[j].first);
                // db(leftA);
                // db(leftB);
                // db(left_);

                // string rightA = tA.substr(posA[i].second+1);
                // string rightB = tB.substr(posB[j].second+1);
                int right_ = lcs_helper (posA[i].second+1, tA.length(), posB[j].second+1, tB.length());
                // db(rightA);
                // db(rightB);
                // db(right_);

                res = max(res, tC.length() + left_ + right_);
            }
        }

    
        return res;
    }
};

// CUT begin
ifstream data("WinterAndReindeers.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> allA, vector<string> allB, vector<string> allC, int __expected) {
    time_t startClock = clock();
    WinterAndReindeers *instance = new WinterAndReindeers();
    int __result = instance->getNumber(allA, allB, allC);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

void run_test(const set<int> &case_set) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> allA;
        from_stream(allA);
        vector<string> allB;
        from_stream(allB);
        vector<string> allC;
        from_stream(allC);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(allA, allB, allC, __answer))
            passed++;
    }
    if (case_set.size() > 0) cases = case_set.size();
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;

    int T = time(NULL) - 1387763412;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << "WinterAndReindeers (1000 Points)" << endl << endl;

    set<int> cases;
    for (int i = 1; i < argc; ++i) cases.insert(atoi(argv[i]));
    run_test(cases);
    return 0;
}
// CUT end
