#include <stdio.h>

int main(){
    char c = 'a';
    char name[] =  c"herp";
    printf("%s\n", name);//"derpherp"
    return 0;
}