#include <unistd.h>

int main(void)
{
    int i;

    for (i = 1; i <= 5; i++)
    {
        char c = i + '0';
        write(1, &c, 1);
    }
    return (0);
    }
