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
#include <cfloat>
using namespace std;

#define FOR(i,x,y) for(int i=x; i<=y; i++)
#define FORN(i,n) FOR(i,0,(n-1))
#define FORE(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define db(x) cout << (#x) << " = " << x << endl;
#define CLR(x) memset(x,0,sizeof(x));
#define sz(x) ((int)x.size())
#define mp make_pair
#define pb push_back
#define re return
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

class GearsDiv2 {
    public:

    string Directions;
    int dp[51][2][2];
    int N;
    int solve(int index, bool previous, bool first)
    {
        if(index == N-1)
        {
            if( (first && Directions[0]==Directions[index]) || (previous && Directions[index-1] == Directions[index]) )
                return 0;
            return 1;
        }

        int &res = dp[index][previous][first];
        if(res!=-1)
            return res;

        res = 0;
        if(previous)
        {
            if(Directions[index]==Directions[index-1])
                res = max(res, solve(index+1, false, first));
            else
                res = max(res, solve(index+1, true, first) + 1);
        }
        else
        {
            res = max(res, solve(index+1,true, (index==0)?true:false) + 1);
        }

        res = max(res, solve(index+1, false, (index==0)?false:true));
        // db(index);
        // db(previous);
        // db(first);
        // db(res);
        return res;
    }
    int getmin(string _Directions) {

        Directions = _Directions;
        N = sz(Directions);
        memset(dp, -1, sizeof dp);
        return sz(Directions) - solve(0, 0, 0);
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string Directions, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GearsDiv2 *instance = new GearsDiv2();
    int __result = instance->getmin(Directions);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            string Directions = "LRRR";
            int __expected = 1;
            return do_test(Directions, __expected, __no);
        }
        case 1: {
            string Directions = "RRR";
            int __expected = 2;
            return do_test(Directions, __expected, __no);
        }
        case 2: {
            string Directions = "LRLR";
            int __expected = 0;
            return do_test(Directions, __expected, __no);
        }
        case 3: {
            string Directions = "LRLLRRLLLRRRLLLL";
            int __expected = 6;
            return do_test(Directions, __expected, __no);
        }
        case 4: {
            string Directions = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR";
            int __expected = 14;
            return do_test(Directions, __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "GearsDiv2 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379411536;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
