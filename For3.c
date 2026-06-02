#include <unistd.h>
int main (void)
{
int i;
for(i='a' ; i<='z'; i++)
{
char c= i;
write(1, &c, 1);
}
return (0);
}

