#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec2bin(int n, char *rbn) {
	while(n > 0) {
		(n & 0x1) ? (*rbn++ = '1') : (*rbn++ = '0');
		n >>= 1;
	}
}

int main(int argc, char *argv[]) {

	FILE *fp;
	int c, i;
	char rbn[] = "0000000";

	if(argc != 2) {
		printf("Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	errno = 0;

	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		fprintf(stderr, "%s: Couldn't open file %s; %s\n", argv[0], argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}

	while((c = fgetc(fp)) != EOF) {
		dec2bin(c, rbn);
#ifdef DEBUG
		fprintf(stderr, "%c: %d - b%s\n", c, c, rbn);
#endif
		printf("   ");
		for(i = 6; i >= 0; i--)
			printf("%s", rbn[i] == '0' ? " " : "\t");
		printf("\n\t\n  ");
		strcpy(rbn, "0000000");
	}

	printf("\n\n\n");

	fclose(fp);
	exit(EXIT_SUCCESS);
}
