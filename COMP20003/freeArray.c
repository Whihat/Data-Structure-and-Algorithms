#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc,char *argv[]){
    //malloc
    int *a = (int *)malloc(sizeof(int)*10);

    int **b = (int **)malloc(sizeof(int *)*10);

    // [10]是第一层array
    int *c[10];

    for(int i = 0; i< 10; i++){
        b[i] = (int *)malloc(sizeof(int)*20);

        c[i] = (int *)malloc(sizeof(int)*20);
    }

    for (int i = 0; i < 10; i++) {
        a[i] = 0;
        for(int j = 0; j < 20; j++) {
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }

    free(a);

    for(int m = 0; m<10; m++){
        free(b[m]);
        free(c[m]);
    }
    free(b);
    //free(c);

    return 0;
}
