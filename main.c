#include "all.h"

int
main()
{
	Rule *r = initRule();

	int i;
	for (i = 1; i <= 100; i++)
		say(r, i);
	return 0;
}