//#include <term.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	char str[2000];
//	int l;
//	struct termios term;
//	char *term_name = "xterm-256color";
//
//	tcgetattr(0, &term);
//	term.c_lflag &= ~(ECHO);
//	term.c_lflag &= ~(ICANON);
//	tcsetattr(0, TCSANOW, &term);
//	tgetent(0, term_name);
//	l = read(0, &str, 100);
//	printf("%s\n", str);
//}