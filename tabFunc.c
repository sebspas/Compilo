#include "tabFunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


func table_func[MAX_SIZE_FUNC];
int last_func = 0;

int get_adr_func(char name[SIZE_NAME_FUNC]) {
	int i = last_func-1;

	for (; i >= 0; --i)
	{
		if (strcmp(table_func[i].name, name) == 0) {
			return table_func[i].adr;
		}
	}

	fprintf(stderr, "Function not exist.\n");
    exit(2);
	return -1;
}

int add_func(char name[SIZE_NAME_FUNC], int adr) {
	strcpy(table_func[last_func].name, name);
    table_func[last_func].adr = adr;
    last_func++;
    return adr;
}

