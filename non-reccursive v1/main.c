#include <stdio.h>

void dominator(int *A, int N)
{
    if (N == 0) {
        printf("No dominator (empty array)\n");
        return;
    }
    for(int i=0;i<N;i++){
        int candidate = A[i]; //1 2 3 3 3 3 4 6 3
        int count = 0;
        for(int j=0 ; j<N ;j++){
            if(candidate==A[j]){
                count++;
            }
        }
        if (count > N/2){
             printf("Dominator = %d, found at index %d\n", candidate, i);
             return ;
        }
    }
     printf("No dominator found.\n");
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
