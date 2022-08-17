#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {

	printf("---------------------------------------------\n");
	printf("Enter -h (or --help) to see the list commands.\n");
	printf("---------------------------------------------\n");
	
	bool flag = false;

	if (argc < 2) {
		printf("Type -h (or --help) to display the list of commands.");
		flag = true;
	}

	if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
		printf("List command:");
		printf("-h(--help) - Output a list a commands.\n"
			"-t(--table) -- Print table of variable sizes.\n"
			"-c(--calc) -- - Calculator (digit <operation> digit).\n");
		printf("Types of format output: \n"
			" -x -- output the result in hexadecimal form.\n"
			" -f -- output the result in float form.\n"
			" -e -- output the result in exponential form.\n");
		flag = true;
	}

	if (argc == 2 && (!strcmp(argv[1], "-t") || !strcmp(argv[1], "--table"))) {
		printf("bool: %8d \n", sizeof(bool));
		printf("char: %8d \n", sizeof(char));
		printf("short: %7d \n", sizeof(short));
		printf("int: %9d \n", sizeof(int));
		printf("long int: %4d \n", sizeof(long int));
		printf("long long: %3d \n", sizeof(long long));
		printf("float: %7d \n", sizeof(float));
		printf("double: %6d \n", sizeof(double));
		printf("long double: %1d \n", sizeof(long double));
		flag = true;
	}

	if (!strcmp(argv[1], "-c") || !strcmp(argv[1], "--calc")) {
		if (argc == 5) {
			int x, y, res = 0;
			x = atoi(argv[2]);
			y = atoi(argv[4]);
			if (!strcmp(argv[3], "/") || !strcmp(argv[3], ":")) {
				if (y != 0)
					res = x / y;
				else
					printf("Error, the second variable is zero.\n");
			}
			else if (argv[3] == "*")
				res = x * y;
			else if (argv[3] == "+")
				res = x + y;
			else if (argv[3] == "-")
				res = x - y;
			else if (argv[3] == "^")
				res = x ^ y;
			printf("Answer %d\n", res);
			flag = true;
		}
		else if (argc == 6) {
			if (!strcmp(argv[2], "-X") || !strcmp(argv[2], "-x")) {
				int x, y, res = 0;
				x = atoi(argv[3]);
				y = atoi(argv[5]);
				if (!strcmp(argv[4], "/") || !strcmp(argv[4], ":")) {
					if (y != 0)
						res = x / y;
					else
						printf("Error, the second variable is zero.\n");
				}
				else if (!strcmp(argv[4], "*"))
					res = x * y;
				else if (!strcmp(argv[4], "+"))
					res = x + y;
				else if (!strcmp(argv[4], "-"))
					res = x - y;
				else if (!strcmp(argv[4], "^"))
					res = x ^ y;
				printf("Answer %X\n", res);
				flag = true;
			}
			else if (!strcmp(argv[2], "-e") || !strcmp(argv[2], "-E") || !strcmp(argv[2], "-f") || !strcmp(argv[2], "-F")) {
				float x, y, res = 0;
				x = atoi(argv[3]);
				y = atoi(argv[5]);
				if (!strcmp(argv[4], "/") || !strcmp(argv[4], ":")) {
					if (y != 0)
						res = x / y;
					else
						printf("Error, the second variable is zero.\n");
				}
				else if (!strcmp(argv[4], "*"))
					res = x * y;
				else if (!strcmp(argv[4], "+"))
					res = x + y;
				else if (!strcmp(argv[4], "-"))
					res = x - y;
				if (!strcmp(argv[2], "-E") || !strcmp(argv[2], "-e"))
					printf("Answer %e \n", res);
				else if (!strcmp(argv[2], "-F") || !strcmp(argv[2], "-f"))
					printf("Answer %f \n", res);
				flag = true;
			}
			else {
				printf("Eror, innvaid value entered.\n");
				flag = true;
			}
		}
		else if (!flag)
			printf("Eror, innvaid value entered.\n"
				"Input -h (or --help) to see list of commands.\n");
	}
	return 0;
}