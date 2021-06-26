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
