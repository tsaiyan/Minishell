#include "header.h"

int 			ctrlc_char(t_hist *hist)
{
	def_freestr_null(&hist->right);
	def_freestr_null(&hist->left);
	write(1, "\n", 1);
	return (2);
}