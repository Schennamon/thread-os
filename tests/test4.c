#include <stdio.h>
#include <pthread.h>

void print_msg(){
	fprintf(stderr, "Hello World\n");
	pthread_exit(NULL);
	fprintf(stderr, "Test\n");
}

void *any_func(void *arg){
	print_msg();
	fprintf(stderr, "End of any_func()\n");

	return 0;
}

int main()
{
	pthread_t thread;

	if(pthread_create(&thread, NULL, &any_func, NULL) != 0){
		fprintf(stderr, "Erorr\n");
		return 1;
	}

	while(1);

	return 0;
}