#include<stdio.h>
#define PG_MAJORVERSION "14"
#define CATALOG_VERSION_NO	202107181
#define CppAsString(identifier) #identifier
#define CppAsString2(x)			CppAsString(x)
#define TABLESPACE_VERSION_DIRECTORY	"PG_" PG_MAJORVERSION "_" \
									CppAsString2(CATALOG_VERSION_NO)
#define TABLESPACE_VERSION_DIRECTORY2	"PG_" PG_MAJORVERSION "_"                                   

void print_macro() {
    printf("print_macro: %s\n", TABLESPACE_VERSION_DIRECTORY);
    printf("print_macro: %s\n", TABLESPACE_VERSION_DIRECTORY2);
}                                    