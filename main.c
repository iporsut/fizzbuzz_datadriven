#include "fizzbuzz.h"

int
main()
{
	Rule *r = initRule();

	int i;
	for (i = 1; i <= 15; i++)
		say(r, i);
	return 0;
}
