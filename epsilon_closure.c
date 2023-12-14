#include <stdio.h>
#include <string.h>
char result[20][20], copy[3], states[20][20];
void add_state(char a[3], int i) 
{
    strcpy(result[i], a);
}
void display(int n) 
{
    int k = 0;
    printf("\n Epsilon closure of %s={" , copy);
    while (k < n) {
    printf("%s", result[k]);
    k++;
   }
printf("}\n");
}
int main() 
{
 FILE *INPUT;
 INPUT = fopen("input.dat", "r");
 char state[3];
 int end, i = 0, n, k = 0;
 char input[3], state2[3], state1[3];
 printf("Enter number of states: ");
 scanf("%d", &n);
 printf("\nEnter the states:\n");
    for (k = 0; k < n; k++)
 {
    scanf("%s", states[k]);
 }
 for (k = 0; k < n; k++) 
 {
    i = 0;
 strcpy(state, states[k]);
 strcpy(copy, state);
 add_state(state, i++);
 while (i) 
    {
        end = fscanf(INPUT, "%s%s%s", state1,
        input, state2);
        if (end == EOF) 
        {
         break;
        }
        if (strcmp(state, state1) == 0) 
        {
         if (strcmp(input, "e") == 0) 
            {
            add_state(state2, i++);
            strcpy(state, state2);
             }
        }
    }
    display(i);
    rewind(INPUT);
 }
fclose(INPUT);
return 0;
}

/*input
q0 0 q0
q0 1 q1
q0 e q1
q1 1 q2
q1 e q2
*/