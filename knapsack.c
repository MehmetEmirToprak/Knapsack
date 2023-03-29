#include <stdio.h>
#include <time.h>

int max( int a, int b)
{
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

int knapsack_dynamic(int *values, int *weights, int W, int n){

    int i,
        w,
        V[n][n];
    /*

    for (w = 0; w < n; ++w) {
        V[0][w] = 0;
    }
    for (i = 1; i < n; ++i) {
        V[i][0] = 0;
    }
     */

    //there are 2 nested loops
    //O(number of values * number of weights)
    // ~=O(n^2)
    for (i = 1; i < n; ++i) {
        for (w = 0; w < W; ++w) {
            if (i==0 || w==0) {
                V[i][w] = 0;
            }
            else {
                if (weights[i-1] <= w) {
                    V[i][w] = max(values[i-1] + V[i-1][w-weights[i-1]], V[i-1][w]);
                }
                else {
                    V[i][w] = V[i-1][w];
                }
            }

        }
    }
    return V[n][W];
}

int main() {

    clock_t start_t, end_t;
    double total_t;
    int values[] = { 40, 115, 120, 250, 300, 320, 640, 730};
    int weights[] = { 10, 20, 30, 40, 50, 15, 25, 35};
    int W = 145; // MAX
    int n = sizeof(values)/ sizeof(values[0]);

    start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);
    int max = knapsack_dynamic(values, weights, W, n);
    printf("Maximum knapsack value: %d\n", max);
    end_t = clock();
    printf("End of the knapsack algorithm, end_t = %ld\n", end_t);
    total_t = (double)(end_t - start_t) / (double)CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f\n", total_t  );

    return 0;
}
