 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
 int i ,a;
    int b=92;

  scanf("%d",&a);
    printf("  /%c\n",b);
    for(i=0;i<a;i++){
        printf("  ||\n");
    }
        printf(" /||%c\n/:||:%c\n",b,b);
    for(i=0;i<a-1;i++){
        printf("|:||:|\n");
    }
    printf("|/||%c|\n  **\n  **",b);

    return 0;
}

