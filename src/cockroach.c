#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>


int func (void)
{
	const char snum[] = "-1s23-3";
	int res = atoi (snum);

	printf ("res: %d\n", res);
	return 0;
}

void func2 (void)
{
	const char *fname =  "file.tx";
	FILE *file = fopen (fname, "r");

	if (file == NULL) {
		perror (NULL);
		fprintf (stderr, ">> %d\n", errno);
	}
}

void func3 (void)
{
	char s1[] = "hello1";
	char s2[] = "hello2";

	if (strcmp (s1, s2) == -1) {
		printf ("Error: string are not equal\n");
	}
}

int main (void)
{
	func3 ();
	return 0;
}


/*
https://stackoverflow.com/questions/54483426/is-use-of-function-return-values-for-error-checking-and-or-exception-handling-go

	1) If function needs to change variable value then it should
		get variable as input argument and return error code.
		e.g. 0 success; -1 error occured.
	2) If function does not need to change any variable value then
		just return error code.
		e.g. 0 success; -1 error occured.
	3) `-1' as error code is common and widesread way to indicate
		that error occured.
	
	!WARNING
	* string.h does not follow that techiques because it returns
		return value and error code at same time.
		As well as malloc, free, etc.
		e.g. NULL - error occured, otherwise success.
*/

