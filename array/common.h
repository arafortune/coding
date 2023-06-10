#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SUCCESS 0
#define FAIL -1
#define INVAL -1
#define ASSERT(a, b) assert(a == b)
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
