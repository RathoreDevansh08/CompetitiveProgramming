#include<stdio.h>
#include<stdlib.h>

static char a;
struct g
{
 char data;
 struct g* next;
};
void push(struct g* top,char new)
{
 
 struct g* newp=(struct g*)malloc(sizeof(struct g*));
 newp->data=new;
 newp->next=top;
 top=newp;
 a=(top)->data;printf("%c\n",a);
}
void pop(struct g* top)
{
  struct g* t;
  if (top == NULL)
  {
    return;
  }
  else
  {
     t= top;
     top= (t)->next;
     free(t);
  }
  return;
}
int Match(char c1, char c2)
{
   if (c1 == '(' && c2 == ')')
     return 1;
   else if (c1 == '{' && c2 == '}')
     return 1;
   else if (c1 == '[' && c2 == ']')
     return 1;
 
     return 0;
}
int Balance(char e[])
{
   int i = 0;
   struct q *stack = NULL;

   while (e[i])
   {
      if (e[i] == '{' || e[i] == '(' || e[i] == '[')
        push(&stack, e[i]);
      if (e[i] == '}' || e[i] == ')' || e[i] == ']')
      {
         if (stack == NULL)
           return 0; 
 
         else if ( Match(a, e[i]) )
         {
           pop(&stack);
           //return 0;
         }
      }
      i++;
   }
    
   if (stack == NULL)
     return 1;
   else
     return 0;
} 

int main()
{
 char e[] = "{[]}()";
  if (Balance(e))
    printf("Balanced \n");
  else
    printf("Not Balanced \n");  
 return 0;
} 
