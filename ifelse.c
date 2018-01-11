#include <stdio.h>

int main()
{
  int score;
  char grade;
  printf("enter your score:");
  scanf("%d", &score);

  if (score > 90 && score <= 100)
    grade = 'A';
  else if (score > 75 && score <= 90)
    grade = 'B';
  else if (score > 60 && score <= 75)
    grade = 'C';
  else if (score >= 0 && score < 60)
    grade = 'F';
  else
    grade = 'N';

  printf("Your Grade is %c", grade);
  return 0;
}
