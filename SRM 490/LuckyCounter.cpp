#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

class LuckyCounter {
    public:
    bool isLucky(string a)
    {
        char A = a[0];
        char B = a[1];
        char C = a[3];
        char D = a[4];

        if (A==C && B==D)
            return true;

        if (A==B && C==D)
            return true;

        if (A==D && B==C)
            return true;

        return false;
    }
    int countLuckyMoments(vector<string> moments) {
        int result = 0 ;
        for(int i=0;i<moments.size();i++)
            if(isLucky(moments[i]))
                result++;
        return result;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> moments, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    LuckyCounter *instance = new LuckyCounter();
    int __result = instance->countLuckyMoments(moments);
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
            string moments[] = {
                "12:21",
                "11:10"
            };
            int __expected = 1;
            return do_test(to_vector(moments), __expected, __no);
        }
        case 1: {
            string moments[] = {
                "00:00",
                "00:59",
                "23:00"
            };
            int __expected = 1;
            return do_test(to_vector(moments), __expected, __no);
        }
        case 2: {
            string moments[] = {
                "12:34"
            };
            int __expected = 0;
            return do_test(to_vector(moments), __expected, __no);
        }
        case 3: {
            string moments[] = {
                "12:11",
                "22:22",
                "00:01",
                "03:30",
                "15:15",
                "16:00"
            };
            int __expected = 3;
            return do_test(to_vector(moments), __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "LuckyCounter (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1379372578;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
