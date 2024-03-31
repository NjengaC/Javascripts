#include "shell.h"
int main()
{
	    char input[] = "This,is,a,custom,strtok,function";
	        char* token = c_strtok(input, ",");
		    
		    while (token != NULL) {
			            printf("%s\n", token);
				            token = c_strtok(NULL, ",");
					        }
		    
		        return 0;
}
