
int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** ans = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int count = 0;
    int currentStart = intervals[0][0];
    int currentEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= currentEnd) {

            if (intervals[i][1] > currentEnd) {
                currentEnd = intervals[i][1];
            }
        } else {

            ans[count] = (int*)malloc(2 * sizeof(int));
            ans[count][0] = currentStart;
            ans[count][1] = currentEnd;
            (*returnColumnSizes)[count] = 2;
            count++;

            currentStart = intervals[i][0];
            currentEnd = intervals[i][1];
        }
    }

  
    ans[count] = (int*)malloc(2 * sizeof(int));
    ans[count][0] = currentStart;
    ans[count][1] = currentEnd;
    (*returnColumnSizes)[count] = 2;
    count++;

    *returnSize = count;
    return ans;
}