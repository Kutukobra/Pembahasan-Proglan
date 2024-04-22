#include <stdio.h>

int main()
{
    char buffer[] = "boom";

    int num;
    int i = sscanf(buffer, "%d", &num);
    printf("%d", i);
}