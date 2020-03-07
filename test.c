

#include "ft_printf.h"
//#include <stdio.h>

#define STR "|%0.0d|\n",7

int     main(void)
{
  //int t = 100;

//   printf("%d",ft_printf("|%108p|",&t));

 //printf("flag_zero : %d \nflag_minus %d\nwidth %d\n is_etoile %d\nispres %d\nlenpres %d\nspeci %c",flg.flag_zero,flg.flag_minus,flg.width,flg.is_etoile,flg.ispres,flg.lenpres,flg.speci);
  //ft_printf("%c",'a');
	int		rt;
	int		ft_rt;

	ft_rt = ft_printf(STR);
	rt = printf(STR);
	printf("\nrt: %d...ft_rt: %d", rt, ft_rt);
 }