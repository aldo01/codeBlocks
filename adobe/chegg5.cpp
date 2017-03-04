//Complete the missing source code - - -
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

void* my_malloc(int size);
void my_free(void *p);
int my_allocated(); // number of allocated blocks or -1 if pool corrupted
int my_size(void *p);

/*
  Given a dynamically allocated array of dynamically allocated
  strings like in the preceding problem, convert to one long
  (dynamically allocated) string, separating entries by spaces.
  For example, flatten(heads("Hello")) returns "H He Hel Hell Hello".
*/
char *flatten(char **strings, int nstrings)
{

}
//////////////////////////////////////////////////////////////////////////////
//Use the following files:
//Tester.c
#include <stdio.h>
#include <string.h>
#include <stdarg.h>



char *flatten(char **strings, int nstrings);

char** strings(int count, ...)
{
   int i;
   char** result = my_malloc(count * sizeof(char*));
   va_list argp;
   va_start(argp, count);
   for (i = 0; i < count; i++) {
      char* str = va_arg(argp, char*);
      result[i] = my_malloc(strlen(str) + 1);
      strcpy(result[i], str);
   }
   va_end(argp);
   return result;
}

int main() {
   char* result = flatten(strings(3, "Goodbye", "cruel", "world"), 3);
   printf("%s\n", result);
   printf("Expected: Goodbye cruel world\n");
   printf("Size: %d\n", my_size(result));
   printf("Expected: 20\n");
   my_free(result);

   char* result2 = flatten(strings(5, "H", "He", "Hel", "Hell", "Hello"), 5);
   printf("%s\n", result2);
   printf("Expected: H He Hel Hell Hello\n");
   my_free(result2);
   printf("Allocated: %d\n", my_allocated());
   printf("Expected: 0\n");
   return 0;
}


myalloc.c
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define POOL_SIZE 100000
#define HEADER_SIZE (2 * sizeof(int))

static unsigned char pool[POOL_SIZE];
static unsigned char *pool_end = pool;
static int allocated = 0;

void* my_malloc(int size)
{
   if (pool == pool_end) { // first time
      for (int i = 0; i < POOL_SIZE; i++)
         pool[i] = 0xDB;
   }

   unsigned char *result = NULL;
   if (pool_end + HEADER_SIZE + size <= pool + POOL_SIZE) {
      int* header = (int*) pool_end;
      if (header[0] == 0xDBDBDBDB) { // else corrupted
         unsigned char *contents = pool_end + HEADER_SIZE;

         result = contents;
         pool_end = pool_end + HEADER_SIZE + size;
         header[0] = 0xBEEFBEEF;
         header[1] = size;
         while (size-- > 0) *contents++ = 0xBB;
         allocated++;
      }
      else
         fprintf(stderr, "Pool corrupted\n");
   }
   return result;
}

void my_free(void *p)
{
   unsigned char *contents = (unsigned char *) p;
   if (pool <= contents - HEADER_SIZE && contents < pool_end) {
      int* header = (int *)(contents - HEADER_SIZE);
      if (header[0] == 0xBEEFBEEF) {
         int size = header[1];
         if (0 <= size && size <= pool_end - contents) {
            header[0] = 0xDEADBEEF;
            while (size-- > 0) *contents++ = 0xDB;
            allocated--;
         }
      }
   }
   else
      fprintf(stderr, "Bad free\n");
}

int my_size(void *p) {
   unsigned char *contents = (unsigned char *) p;
   if (pool <= contents - HEADER_SIZE && contents < pool_end) {
      int* header = (int *)(contents - HEADER_SIZE);
      if (header[0] == 0xBEEFBEEF) {
         int size = header[1];
         if (0 <= size && size <= pool_end - contents)
            return size;
      }
   }
   return -1;
}

static bool pool_corrupted() {
   unsigned char *p = pool;
   while (p < pool_end) {
      int *header = (int *) p;
      unsigned char *contents = p + HEADER_SIZE;
      int size = header[1];
      if (header[0] != 0xBEEFBEEF && header[0] != 0xDEADBEEF)
         return true;
      if (size < 0 || size > pool_end - contents) return true;
      p = contents + size;
      if (header[0] == 0xDEADBEEF) {
         while (size-- > 0) {
            if (*contents++ != 0xDB) return false;
         }
      }
   }
   while (p < pool + POOL_SIZE)
      if (*p++ != 0xDB)
         return false;

   return false;
}

int my_allocated() {
   if (pool_corrupted()) return -1;
   else return allocated;
}






