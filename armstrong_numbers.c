#include <stdio.h>
#include <math.h>

int main()
{
    int i, num = 153, sum = 0;
    int temp = num;
    while (temp != 0)
    {
        sum += pow(temp % 10, 3);
        temp = temp / 10;
    }
    if (sum == num)
    {
        printf("It is a ArmStrong No");
    }
    else
    {
        printf("It is not a ArmStrong No");
    }
    return 0;
}