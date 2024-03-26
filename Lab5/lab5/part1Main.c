#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char *argv[])
{
  int ch;
  int length = 0, insideTag = 0;
  char tag[100];

  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //

    if (ch == '<') // if ch is the start of a tag
    {
      insideTag = 1;
      length = 0;
    }
    else if (ch == '>' && insideTag) // if ch is the end of a tag
    {
      insideTag = 0;
      tag[length] = '\0';

      if (tag[0] == '/') // if tag is a closing tag
      {
        char *popped = pop();
        if (popped == NULL)
        {
          printf("Invalid XML\n");
          exit(1);
        }
      }
      else
      {
        push(tag);
      }
    }
    else if (insideTag)
    {
      tag[length++] = ch;
    }
  }

  if (!isEmpty())
  {
    printf("Invalid XML\n");
    exit(1);
  }
  else
  {
    printf("Valid XML\n");
  }

  exit(0);
}