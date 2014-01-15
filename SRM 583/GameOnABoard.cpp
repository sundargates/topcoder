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

class GameOnABoard {
    public:
    int optimalChoice(vector<string> cost) {
        return 2;
        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> cost, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GameOnABoard *instance = new GameOnABoard();
    int __result = instance->optimalChoice(cost);
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
            string cost[] = {
                "11",
                "10"
            };
            int __expected = 2;
            return do_test(to_vector(cost), __expected, __no);
        }
        case 1: {
            string cost[] = {
                "01",
                "10"
            };
            int __expected = 1;
            return do_test(to_vector(cost), __expected, __no);
        }
        case 2: {
            string cost[] = {
                "111001",
                "001000",
                "111111",
                "001111",
                "001100",
                "001011",
                "111001",
                "010011"
            };
            int __expected = 3;
            return do_test(to_vector(cost), __expected, __no);
        }
        case 3: {
            string cost[] = {
                "001001101011",
                "110011001101",
                "111111000001",
                "111101010001",
                "011100101111",
                "110010111000",
                "111111110101",
                "111011110111",
                "111100100011",
                "000000000110",
                "101011011110",
                "011111000111",
                "101111001011"
            };
            int __expected = 5;
            return do_test(to_vector(cost), __expected, __no);
        }
        case 4: {
            string cost[] = {
                "110010100101010110100010001100111011",
                "001000000110100011010100000001001000",
                "011000110111101001011101110111000100",
                "111001011000100101111010100110110011",
                "111000011101001010000100001010000010",
                "111001110010100101000001001100011011",
                "111110100111010101100000100111000111",
                "011111111100100111111110000001110111",
                "110000010101001111100011110000001000",
                "010010110111111100011101100000011010",
                "110001100001111001101000101110110001",
                "110010000111011110000010110111010101",
                "100100110101001001101000001101101101",
                "001011101101001100111110101111001110",
                "111010111111111100110100000011111100",
                "110101101000001001000100101011100000",
                "011011001011010001001000100000110101",
                "011111111100000011010111010011010100",
                "111001111110001110001110010100111010",
                "000001111000001100101010000001101110",
                "010000110000010010111110111000010101",
                "100010010100110011000111101001101011",
                "111010110001101011010001111101111100",
                "000111110000110000000101100101000110",
                "110000010111001001110001101010111100",
                "011111101101001011011010011111100010",
                "110101111101010100110010000011001101",
                "101101111001010100101111100001110001",
                "000110010100101111011011110010010010",
                "110101010011101000111011100000010011",
                "110001010001110011010100110000010001",
                "111010101100111100100011001101010100",
                "011000000000100001011010000100010001",
                "100000110110000001010001001111010000",
                "100011111110010011011011001110011111",
                "101100001111100101001101100000100001",
                "010000111011010110011001110011111000",
                "100010100111110111001010100101111010",
                "000110011110111011111000101000001000"
            };
            int __expected = 7;
            return do_test(to_vector(cost), __expected, __no);
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
    cout << "GameOnABoard (900 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1373260605;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
