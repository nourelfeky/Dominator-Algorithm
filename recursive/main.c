#include <stdio.h>

void findCandidate(int *A, int N, int i, int *candidate, int *count)
{
    if (i == N) return;
    if (*count == 0) {
        *candidate = A[i];
        *count = 1;
    } else if (A[i] == *candidate) {
        (*count)++;
    } else {
        (*count)--;
    }
    findCandidate(A, N, i + 1, candidate, count);
}

int countFreq(int *A, int N, int candidate, int i)
{
    if (i == N) return 0;
    return (A[i] == candidate ? 1 : 0) + countFreq(A, N, candidate, i + 1);
}

int findIndex(int *A, int N, int candidate, int i)
{
    if (i == N) return -1;
    if (A[i] == candidate) return i;
    return findIndex(A, N, candidate, i + 1);
}

void dominator(int *A, int N)
{
    if (N == 0) {
        printf("No dominator (empty array)\n");
        return;
    }

    int candidate = A[0];
    int count = 1;

    findCandidate(A, N, 1, &candidate, &count);

    int freq = countFreq(A, N, candidate, 0);

    if (freq <= N / 2) {
        printf("No dominator found.\n");
        return;
    }

    int index = findIndex(A, N, candidate, 0);
    printf("Dominator = %d, found at index %d\n", candidate, index);
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
