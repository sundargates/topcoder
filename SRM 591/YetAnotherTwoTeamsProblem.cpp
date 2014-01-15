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
#define MAX  150002

class YetAnotherTwoTeamsProblem {
    public:

    long dp[51][MAX];
    int N;
    vector<int> skill;
    int minimum;
    int sumAll;

    ll solve(int index, int sumA)
    {
        if (sumA>=MAX)
            return 0;

        if(index==N)
        {
            int sumB = sumAll - sumA;
            double diff = (sumA - sumB);
            diff/=2.0;
            // db(sumA);
            // db(sumB);
            // db(minimum);
            // db(diff);
            if(diff > 0.0 && (double)minimum > diff)
                return 1;

            return 0;
        }

        long &res = dp[index][sumA];
        if(res!=-1)
            return res;

        res = solve(index+1, sumA + skill[index]) + 
                solve(index+1, sumA) ;

        return res;

    }
    long long count(vector<int> _skill) 
    {
        skill = _skill;
        sumAll = 0;
        sort(skill.begin(), skill.end());

        FORN(i,sz(skill)) sumAll += skill[i];
        N = sz(skill);

        ll res = 0;
        FORN(i, sz(skill))
        {
            int val = skill[i];
            minimum = val;

            memset(dp, -1, sizeof dp);
            // skill.erase(skill.begin() + i);
            res += solve(i+1, val);
            // skill.insert(skill.begin() + i, val);
        }

        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> skill, long long __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    YetAnotherTwoTeamsProblem *instance = new YetAnotherTwoTeamsProblem();
    long long __result = instance->count(skill);
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
            int skill[] = {
                5, 4, 7, 6
            };
            long long __expected = 2LL;
            return do_test(to_vector(skill), __expected, __no);
        }
        case 1: {
            int skill[] = {
                1, 1, 1, 1, 1
            };
            long long __expected = 10LL;
            return do_test(to_vector(skill), __expected, __no);
        }
        case 2: {
            int skill[] = {
                1, 2, 3, 5, 10
            };
            long long __expected = 5LL;
            return do_test(to_vector(skill), __expected, __no);
        }
        case 3: {
            int skill[] = {
                1, 2, 3, 4, 10
            };
            long long __expected = 0LL;
            return do_test(to_vector(skill), __expected, __no);
        }
        case 4: {
            int skill[] = {
                999, 999, 999, 1000, 1000, 1001, 999, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 999, 1000, 512, 511, 1001, 1001, 1001, 1001, 1001, 1000
            };
            long long __expected = 17672631900LL;
            return do_test(to_vector(skill), __expected, __no);
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
    cout << "YetAnotherTwoTeamsProblem (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379474006;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
