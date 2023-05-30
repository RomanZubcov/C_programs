#include <stdio.h>

void fibonacci(int n, unsigned long long sequence[]) {
    sequence[0] = 0;
    sequence[1] = 1;

    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
}

void golden_ratio(int n, unsigned long long fibonacci_sequence[], double ratios[]) {
    for (int i = 1; i < n; i++) {
        ratios[i-1] = (double)fibonacci_sequence[i] / fibonacci_sequence[i-1];
    }
}

int main() {
    int n = 20;//20 elemente
    unsigned long long fibonacci_sequence[n];
    double golden_ratios[n-1];


    fibonacci(n, fibonacci_sequence);


    golden_ratio(n, fibonacci_sequence, golden_ratios);

   
    printf("Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("%llu\n", fibonacci_sequence[i]);
    }

   
    printf("\nGolden Ratio:\n");
    for (int i = 0; i < n-1; i++) {
        printf("%f\n", golden_ratios[i]);
    }

    return 0;
}
