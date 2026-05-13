#include <stdio.h>

void dominator(int *A, int N)
{
    if (N == 0) {
        printf("No dominator (empty array)\n");
        return;
    }

    int candidate = A[0];
    int count = 1;

    for (int i = 1; i < N; i++) {
        if (count == 0) {
            candidate = A[i];
            count = 1;
        } else if (A[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    int freq = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == candidate)
            freq++;
    }

    if (freq <= N / 2) {
        printf("No dominator found.\n");
        return;
    }


    for (int i = 0; i < N; i++) {
        if (A[i] == candidate) {
            printf("Dominator = %d, found at index %d\n", candidate, i);
            return;
        }
    }
}

int main()
{
    int N;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    int A[N];

    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    dominator(A, N);

    return 0;
}
