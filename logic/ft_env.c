#include "header.h"
int	ft_env(t_bin *bin)
{
   int i;

   i = 0;
   write(1, "\n", 1);
   while(bin->envp[i])
      ft_puts(bin->envp[i++]);
   return 0;	
}