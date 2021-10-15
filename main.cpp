#include <iostream>
#include <vector>
#include <valarray>

int sum_digit_in_13_system(int n){
    int count = 0;
    for (int i = 0; i < 6; ++i) {
        int pow13 = (pow(13, 5 - i));
        count += n / pow13;
        n %= pow13;
    }
    return count;
}

int main() {
    int max_sum_of_6_digit = 12 * 6;
    std::vector<int> sums(max_sum_of_6_digit + 1, 0);
    double max_value_of_6_digit = pow(13, 6);
    for (int i = 0; i < max_value_of_6_digit; ++i) {
        int s = sum_digit_in_13_system(i);
        sums[s]++;
    }
    long long sum_of_beautiful = 0;
    for (int s: sums) {
        sum_of_beautiful += (s * s);
    }
    sum_of_beautiful *= 13;
    std::cout << sum_of_beautiful;
    return 0;
}
