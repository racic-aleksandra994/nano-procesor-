#include <unistd.h>
int main (void)
{
int i;
for(i='z' ; i>='a'; i--)
{
char c=i;
write(1, &c, 1);
}
return (0);
}


