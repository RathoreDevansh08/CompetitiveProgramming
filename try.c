#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

int main()
{
    struct Books b;
    strcpy(b.title, "abc");
    printf("%s",b.title);
    return 0;
}
