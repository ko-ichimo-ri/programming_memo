#include <stdio.h>

int main(){
    unsigned char chars[2];
    int x,y;

    printf("Enter two integers between 0 and 255.\n");
    scanf("%d%d",&x,&y);

    short *p=(short *)chars;
    *p=y*256+x;

    printf("\n");
    
    for(int i=0;i<2;i++){
        printf("%d\n",chars[i]);
    }
    return 0;
}