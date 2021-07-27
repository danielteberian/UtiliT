#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wid = 80, yr = 2021;
int col, lead, gap;

const char *wdays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

struct mon
{
	const char *nm;
	int days, start_wday, at;
}
mon[12] = {
	{ "JANUARY",	31, 0, 0 },
	{ "FEBRUARY",	28, 0, 0 },
	{ "MARCH",	31, 0, 0 },
	{ "APRIL",	30, 0, 0 },
	{ "MAY",	31, 0, 0 },
	{ "JUNE",	30, 0, 0 },
	{ "JULY",	31, 0, 0 },
	{ "AUGUST",	31, 0, 0 },
	{ "SEPTEMBER",	30, 0, 0 },
	{ "OCTOBER",	31, 0, 0 },
	{ "NOVEMBER",	30, 0, 0 },
	{ "DECEMBER",	31, 0, 0 }
};


void spc(int n) {
	while (n-- > 0) putchar(' '); 
}

void init_mon()
{
	int i;
	if ((!(yr % 4) && (yr % 100)) || !(yr % 400))
		mon[1].days = 29;
	yr--;
	mon[0].start_wday
		= (yr * 365 + yr/4 - yr/100 + yr/400 + 1) % 7;

	for (i = 1; i < 12; i++)
		mon[i].start_wday =
			(mon[i-1].start_wday + mon[i-1].days) % 7;

	col = (wid + 2) / 22;
	while (12 % col) col--;
	gap = col - 1 ? (wid - 20 * col) / (col - 1) : 0;
	if (gap > 4) gap = 4;
	lead = (wid - (20 + gap) * col + gap + 1) / 2;
	yr++;
}

void print_r(int r)
{
	int c, i, from = r * col, to = from + col;
	spc(lead);
	for (c = from; c < to; c++)
	{
		i = strlen(mon[c].nm);
		spc((20 - i)/2);
		printf("%s", mon[c].nm);
		spc(20 -i - (20 - i)/2 + ((c == to - 1) ? 0 : gap));
	}
	putchar('\n');

	spc(lead);
	for (c = from; c < to; c++)
	{
		for (i = 0; i < 7; i++)
			printf("%s%s", wdays[i], i == 6 ? "" : " ");
		if (c < to - 1) spc(gap);
		else putchar('\n');
	}

	while (1)
	{
		for (c = from; c < to; c++)
			if (mon[c].at < mon[c].days) break;
		if (c == to) break;

		spc(lead);
		for (c = from; c < to; c++)
		{
			for (i = 0; i < mon[c].start_wday; i++) spc(3);
			while(i++ < 7 && mon[c].at < mon[c].days)
			{
				printf("%2d", ++mon[c].at);
				if (i < 7 || c < to - 1) putchar(' ');
			}
			while (i++ <= 7 && c < to - 1) spc(3);
			if (c < to - 1) spc(gap - 1);
			mon[c].start_wday = 0;
		}
		putchar('\n');
	}
	putchar('\n');
}

void print_yr()
{
	int r;
	char buf[32];
	sprintf(buf, "%d", yr);
	spc((wid - strlen(buf)) / 2);
	printf("%s\n\n", buf);
	for (r = 0; r * col < 12; r++)
		print_r(r);
}

int main(int c, char **v)
{
	int i, yr_set = 0;
	for (i = 1; i < c; i++)
	{
		if (!strcmp(v[i], "-w"))
		{
			if (++i == c || (wid = atoi(v[i])) < 20)
				goto ohno;
		}
		else if (!yr_set)
		{
		if (!sscanf(v[i], "%d", &yr) || yr <= 0)
			yr = 2021;
		yr_set = 1;
		}
		else
		goto ohno;
	}

	init_mon();
	print_yr();
	return 0;

ohno: fprintf(stderr, "Big problem! Massive oopsie! Call the police!\nUsage: %s yr [-w wid (>=20)]\n", v[0]);
	exit(1);
}
