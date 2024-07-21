#include <iostream>

using namespace std;

int n;
int seq[5005];
int dp[5005];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    dp[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        dp[i] = 1;
        for(int j = i + 1; j < n; j++) {
            if(seq[i] < seq[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }
    printf("%d", res);
}