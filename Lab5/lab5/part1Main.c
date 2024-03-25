#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *pop();
extern void push(char *);

int main(int argc, char *argv[])
{
  int ch;
  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //
    if (ch == '<')
    {
      ch = getchar();
      if (isalpha(ch))
      {
        char temp[2];
        temp[0] = ch;
        temp[1] = '\0';
        push(temp);
      }
      else if (ch == '/')
      {
        ch = getchar();
        char *poppedCh = pop();

        if (poppedCh == NULL || poppedCh[0] != ch)
        {
          printf("Invalid XML\n");
          exit(1);
        }
        else
        {
          printf("Valid XML\n");
        }
      }
    }
  }
  exit(0);
}