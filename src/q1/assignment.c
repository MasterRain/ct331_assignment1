#include <stdio.h>

int main(int arg, char* argc[]){
  printf("Hello assignment1.\n");
    
    
    int seven =7;
    double pie = 3.14;
    char me = 'r';
    
    char *intermediary =  &me;
    
    int numberNumber = 2;
    int *numberLocation = &seven;
    long numbersYo = 17;
    double *doubleLocation = &pie;
    char **charLocationLocation = &intermediary;
    
    printf("The size of numberNumber is : %lu \n", sizeof(numberNumber));
    printf("The size of numberLocation is : %lu \n", sizeof(numberLocation));
    printf("The size of numbersYo is : %lu \n", sizeof(numbersYo));
    printf("The size of doubleLocation is : %lu \n", sizeof(doubleLocation));
    printf("The size of charLocationLocation is : %lu \n", sizeof(charLocationLocation));
    
    
    
    
    
  return 0;
}
