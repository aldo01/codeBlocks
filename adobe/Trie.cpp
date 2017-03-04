#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>





void search(struct dictionary **current) {
    if((*current)->is_end==1){
        printf("\n"); getchar();
    }

    for(int i=0; i<26; i++){
        if((*current)->Children[i]!=NULL){
            printf("%c",i+(int)'a');
            search(&(*current)->Children[i]);
        }
    }
}
