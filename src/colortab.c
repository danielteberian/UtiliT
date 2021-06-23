#include <stdio.h>

void tab(const char *title, const char *mode)
{
	int f, b;
	printf("\n\033[1m%s\033[m\n bg\t fg\n", title);
	for (b = 40; b <= 107; b++) {
		if (b == 48) b = 100;
		printf("%3d\t\033[%s%dm", b, mode, b);
		for (f = 30; f <= 97; f++) {
			if (f == 38) f = 90;
			printf("\033[%dm%3d ", f, f);
		}
		puts("\033[m");
	}
}

int main(void)
{
	int fg, bg, blink, inv;

	tab("NORMAL ( ESC[22m or ESC[m )", "22;");
	tab("BOLD ( ESC[1m )", "1;");
	tab("FAINT ( ESC[2m ), UNSUPPORTED", "2;");
	tab("ITALIC ( ESC[3m ), UNSUPPORTED", "3;");
	tab("UNDERLINE ( ESC[4m ), INCONSISTENT", "4;");
	tab("BLINK ( ESC[5m )", "5;");
	tab("INVERT ( ESC[7m )", "7;");
	return 0;
}
