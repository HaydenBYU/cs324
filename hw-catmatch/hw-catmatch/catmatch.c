//Part 1
// 1. 1,2,3
// 2. 1
// 3. 3
// 4. 2
// 5.1 #include <sys/types.h>
// 5.2 #include <sys/stat.h>
// 5.3 #include <fcntl.h>
// 6. 2,7
// 7. SO_ACCEPTCONN
// 8. 3 pages (man -k getaddrinfo)
// 9. Null-terminated strings
// 10. It will return an integer greater than 0
// Part 2
// I completed the TMUX exercise from Part 2
// Part 3


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	//get the enviornemnt variable
	const char* s = getenv("CATMATCH_PATTERN");
	//printf("%s",s);
	//print to standard error
	fprintf(stderr,"%ld",(long)getpid());
	printf("%s","\n\n");
	//printf("%s",argv[1]);	
	//setup variables
	FILE *textfile = fopen(argv[1],"r");
	
    	char line[2000];
	
   	 //textfile = fopen(argv[1], "r");
	
    	int counter = 0;
	
	//A while loop that retrieves each line
	while(fgets(line, sizeof(line), textfile)){
		const char *tmp = line;
		counter = 0;
		if(s != NULL){        

			//A while loop that counts the number of sought string
    			while(NULL != strstr(tmp, s)){
				tmp = strstr(tmp,s);
        			counter = counter + 1;
        			tmp++;
    			}
		}
		else{
			counter = 0;
		}
	//print each line along with its counter

	printf("%d ", counter);
	printf("%s",line);
    }
	printf("%s","\n\n");
     
    fclose(textfile);
    	
	return 0;	
}
