#include<stdio.h>
int main(){
    char ch;
    printf("enter any character to check whether it is vowel or not");
    scanf("%c",&ch);
    switch(ch){
        case 'A':
        case 'a': printf("Yes %c is a vowel",ch);
                  break;
        case 'E':
        case 'e': printf("Yes %c is a vowel",ch);
                  break;
        case 'I':
        case 'i': printf("Yes %c is a vowel",ch);
                  break;
        case 'O':
        case 'o': printf("Yes %c is a vowel",ch);
                  break;
        case 'U':
        case 'u': printf("Yes %c is a vowel",ch);
                  break;      
        default:printf("no the entered character %c is not a vowel",ch);
    }
    return 0;
}