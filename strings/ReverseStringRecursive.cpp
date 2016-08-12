#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int reverse(char *);
char *reverseLoop(char *);

int main(){
 char *str="nimishkaran";
// reverse(str);
  printf(",,,,,,,,,,,,,,,,,,,,,,\n");
   int  len =strlen(str);
  printf("%d ",len);
  char *temp=strtok(str," ");
  // printf("%s",temp);

   printf("%s",reverseLoop(str));

}


char* reverseLoop(char *str)
{
char temp;
size_t len = strlen(str) - 1;
size_t i;
size_t k = len;

for(i = 0; i < len; i++)
{
	temp = str[k];
	str[k] = str[i];
	str[i] = temp;
	k--;

	    /* As 2 characters are changing place for each cycle of the loop
	       only traverse half the array of characters */

    }
    return str;
}
