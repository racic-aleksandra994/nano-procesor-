#include <unistd.h>
int main(void)
{
int i;
for(i=5; i>=1; i--)
{
char c = i +'0';
write(1, &c, 1);
}
return (0);
}

