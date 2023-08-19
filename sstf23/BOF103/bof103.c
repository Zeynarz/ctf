#include <stdio.h>
#include <stdlib.h>

unsigned long long key;

void useme(unsigned long long a, 
		unsigned long long b)
{
	key = a * b;
}

void bofme() {
	char name[16];
	puts("What's your name?");
	printf("Name > ");
	scanf("%s", name);
	printf("Bye, %s.\n", name);
}

int main() {
	system("echo 'Welcome to BOF 103!'");
	bofme();
	return 0;
}
