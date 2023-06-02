// Nguyen Van Duy - 20215334
/*
Bài 2.9. Dưới đây cung cấp đoạn code đơn giản để tính hàm sigmoid theo công thức trực tiếp.
Hãy viết hàm tính xấp xỉ sigmoid(x) đến độ chính xác  10−6 và có tốc độ nhanh hơn ít nhất
30% so với code đơn giản.
*/
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
/*****************
# YOUR CODE HERE #
*****************/
const int TABLE_SIZE = 40001;
const double TABLE_MIN = -20;
const double TABLE_MAX = 20;
const double TABLE_STEP = 0.001;
double sigmoid_table[TABLE_SIZE];

//# hàm chuẩn bị dữ liệu
void precalc() {
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = 0; i < TABLE_SIZE; i++) {
        double x = TABLE_MIN + i * TABLE_STEP;
        sigmoid_table[i] = 1.0 / (1.0 + exp(-x));
    }
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    if (x < TABLE_MIN) return sigmoid_table[0];
    else if (x > TABLE_MAX) return sigmoid_table[TABLE_SIZE-1];
    else {
        double i = (x - TABLE_MIN) / TABLE_STEP;
        int index = (int) i;

        return sigmoid_table[index] + (sigmoid_table[index+1] - sigmoid_table[index]) * (i - index);
    }
}

//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//#  printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;

    if (a.size() != b.size()) return false;
    for (int i = 0; i < (int) a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a, b) && (slow/fast > 1.3)) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } else {
        printf("Wrong answer or your code is not fast enough!\n");
    }

    return 0;
}
// Nguyen Van Duy - 20215334
