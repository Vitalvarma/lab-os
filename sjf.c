#include <stdio.h>
#include <stdbool.h>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int bt[], int pid[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                swap(&bt[j], &bt[j + 1]);
                swap(&pid[j], &pid[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

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
    
    if (n <= 0) {
        printf("Number of processes must be positive.\n");
        return 1; 
    }
    
    int bt[n], tat[n], wt[n], pid[n];
    
    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        pid[i] = i + 1; 
    }
    

    bubbleSort(bt, pid, n);
    

    calculateTAT(n, bt, tat);    
    calculateWT(n, bt, wt, tat);
    

    int total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
    }

    printf("Process\tBurst Time\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t%d\n", pid[i], bt[i], tat[i], wt[i]);
    }
    
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n); 
    return 0; 
}
