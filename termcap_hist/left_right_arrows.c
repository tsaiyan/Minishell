#include "header.h"

int left_arrow(char *buf, int len)
{
	write(1, buf, len);
	return (0);
}

int right_arrow(char *buf, int len)
{
	write(1, buf, len);
	return (0);
}