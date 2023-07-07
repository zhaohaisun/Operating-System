#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#define PAGESIZE 4096
  
int main(int argc, char *argv[])
{
	if(argc != 3) {
		fprintf(stderr, "error parameters!");
			exit(0);
	}
	struct timeval start, end;
	int NUMPAGES = atoi(argv[1]);
	int i,j, trynum = atoi(argv[2]);
	int jump = PAGESIZE / sizeof(int);
	int arr[NUMPAGES * jump];

	gettimeofday(&start, NULL);
	for(j = 0; j < trynum; ++j) {
		for(i = 0; i < NUMPAGES * jump; i += jump) {
			arr[i] += 1;
		}
	}
	gettimeofday(&end, NULL);
	printf("%f %ld %ld\n", ((double) end.tv_usec - start.tv_usec) / NUMPAGES / trynum, end.tv_usec, start.tv_usec);
	return 0;
}

