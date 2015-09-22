#include <stdio.h>
typedef struct _rule{
	 int (*accept) (int n);
	 void (*print) (int n);
	 struct _rule *next;
} Rule;

int fizzbuzz_accept(int n) {
	return n % 15 == 0;
}

void fizzbuzz_print(int n) {
	printf("FizzBuzz\n");
}

int fizz_accept(int n) {
	return n % 3 == 0;
}

void fizz_print(int n) {
	printf("Fizz\n");
}

int buzz_accept(int n) {
	return n % 5 == 0;
}

void buzz_print(int n) {
	printf("Buzz\n");
}

int number_accept(int n) {
	return 1;
}

void number_print(int n) {
	printf("%d\n",n);
}


void say(Rule *rule, int n) {
	while(rule->next && !rule->accept(n)) rule = rule->next;

	rule->print(n);
}

Rule number, fizz, buzz, fizzBuzz;

Rule *initRule() {
	fizzBuzz.accept = fizzbuzz_accept;
	fizzBuzz.print = fizzbuzz_print;
	fizzBuzz.next = &fizz;

	fizz.accept = fizz_accept;
	fizz.print = fizz_print;
	fizz.next = &buzz;

	buzz.accept = buzz_accept;
	buzz.print = buzz_print;
	buzz.next = &number;

	number.accept = number_accept;
	number.print = number_print;
	number.next = NULL;
	return &fizzBuzz;
}
