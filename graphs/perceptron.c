#include <stdio.h>
#include <conio.h>
#define n 3
#define m 4

void main() {
    int i, j, net, y, epoch, epochs = 5, X[n][m], W[m], d[n], c;
    clrscr();
    printf("Enter %d training input vectors: ", n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &X[i][j]);
        }
    }

    printf("Enter weight vector: ");
    for(i = 0; i < m; i++) {
        scanf("%d", &W[i]);
    }

    printf("Enter learning capacity: ");
    scanf("%d", &c);

    printf("Enter desired outputs: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    for(epoch = 0; epoch < epochs; epoch++) {
        printf("------- Epoch %d ----------\n", epoch + 1);
        for(i = 0; i < n; i++) {
            net = 0;
            printf("\nPass %d:\n", i + 1);

            for(j = 0; j < m; j++) {
                net += W[j] * X[i][j];
            }
            y = (net >= 0) ? 1 : -1;
            if(y != d[i]) {
                for(j = 0; j < m; j++) {
                    W[j] = W[j] + c * (d[i] - y) * X[i][j];
                }
            }
            printf("Weights: [ ");
            for(j = 0; j < m; j++) {
                printf("%d ", W[j]);
            }
            printf("]\n");
        }
    }

    printf("Final Weights: [ ");
    for(j = 0; j < m; j++) {
        printf("%d ", W[j]);
    }
    printf("]\n");
    getch();
}