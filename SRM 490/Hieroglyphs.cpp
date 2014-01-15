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

#define DIFF 80

class Hieroglyphs {
    public:
    int graph[161][161];
    pair<ii,ii> get_coordinates(string a)
    {
        stringstream s;
        int x1, y1, x2, y2;
        s<<a;
        s>>x1;

        // s<<a;
        s>>y1;

        // s<<a;
        s>>x2;

        // s<<a;
        s>>y2;

        db(x1);
        db(y1);
        db(x2);
        db(y2);

        return mp(mp(x1,y1), mp(x2, y2));
    }
    int minimumVisible(vector<string> hier1, vector<string> hier2) 
    {

        int res = INT_MAX;
        memset (graph, 0, sizeof graph);

        vector< pair<ii,ii> > hier2_points;

        FORN(i, sz(hier1))
        {
            pair<ii, ii> temp = get_coordinates(hier1[i]);
            FOR (j, temp.first.first, temp.second.first)
                FOR (k, temp.first.second, temp.second.second) {

                    int x = j + DIFF;
                    int y = k + DIFF;
                    db(x);
                    db(y);

                    graph[x][y] = 1;

                }
        }

        int hier1_distance = 0;
        FORN(i, 161)
            FORN(j, 161)
                if(graph[i][j])
                    hier1_distance++;


        db(hier1_distance);
        FORN(i, sz(hier2))
        {
            hier2_points.pb(get_coordinates(hier2[i]));
        }

        FOR(dx, -80, 80)
            FOR(dy, -80, 80) 
            {
                int temp_res = 0;
                FORN(i, sz(hier2_points))
                {
                    int x1 = hier2_points[i].first.first + DIFF + dx;
                    int y1 = hier2_points[i].first.second + DIFF + dy;

                    int x2 = hier2_points[i].second.first + DIFF + dx;
                    int y2 = hier2_points[i].second.second + DIFF + dy;

                    FOR(j, x1, x2)
                        FOR(k, y1, y2) {

                            if(!graph[j][k])
                                temp_res ++;

                            graph[j][k] ++;
                        }

                }

                res = min(res, hier1_distance + temp_res);

                FORN(i, sz(hier2_points))
                {
                    int x1 = hier2_points[i].first.first + DIFF + dx;
                    int y1 = hier2_points[i].first.second + DIFF + dy;

                    int x2 = hier2_points[i].second.first + DIFF + dx;
                    int y2 = hier2_points[i].second.second + DIFF + dy;

                    FOR(j, x1, x2)
                        FOR(k, y1, y2) {
                            graph[j][k] --;
                        }

                }
            }

        return res;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> hier1, vector<string> hier2, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Hieroglyphs *instance = new Hieroglyphs();
    int __result = instance->minimumVisible(hier1, hier2);
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
        // case 0: {
        //     string hier1[] = {
        //         "0 0 10 0,10 0 10 3"
        //     };
        //     string hier2[] = {
        //         "0 1 10 1",
        //         "5 1 5 4"
        //     };
        //     int __expected = 16;
        //     return do_test(to_vector(hier1), to_vector(hier2), __expected, __no);
        // }
        case 1: {
            string hier1[] = {
                "1 1 1 5"
            };
            string hier2[] = {
                "3 2 5 2"
            };
            int __expected = 6;
            return do_test(to_vector(hier1), to_vector(hier2), __expected, __no);
        }
        // case 2: {
        //     string hier1[] = {
        //         "0 2 6 2"
        //     };
        //     string hier2[] = {
        //         "5 1 6 1,8 1 9 1"
        //     };
        //     int __expected = 6;
        //     return do_test(to_vector(hier1), to_vector(hier2), __expected, __no);
        // }
        // case 3: {
        //     string hier1[] = {
        //         "10 20 10 30,15 20 15 30",
        //         "10 20 15 20,0 30 30 30"
        //     };
        //     string hier2[] = {
        //         "0 5 0 15,5 5 5 25",
        //         "0 5 5 5,0 15 5 15"
        //     };
        //     int __expected = 65;
        //     return do_test(to_vector(hier1), to_vector(hier2), __expected, __no);
        // }
        // case 4: {
        //     string hier1[] = {
        //         "10 10 10 20,10 30 10 40",
        //         "10 10 20 10"
        //     };
        //     string hier2[] = {
        //         "10 0 10 20,10 27 10 35",
        //         "10 0 20 0"
        //     };
        //     int __expected = 45;
        //     return do_test(to_vector(hier1), to_vector(hier2), __expected, __no);
        // }

        // // Your custom testcase goes here
        // case 5:
        //     break;
        // default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "Hieroglyphs (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379374768;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
