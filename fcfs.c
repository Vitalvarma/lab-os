#include <stdio.h>

void calculateTAT(int n, int bt[], int tat[]) {
    tat[0] = bt[0];
    for (int i = 1; i < n; i++) {
        tat[i] = tat[i - 1] + bt[i]; 
    }
}

void calculateWT(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i]; 
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bt[n], tat[n], wt[n];
    
    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    
    calculateTAT(n, bt, tat);    
    calculateWT(n, bt, wt, tat);
    
    int total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i]; 
    }
    
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n); 
    return 0; 
}
