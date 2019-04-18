#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct data {
	int num;
	int result;
} data;

void *rf(void* dd) {
	data *d = (data*)dd;
	/**printf("d->num = %d\n", d->num);	*/
	
	if ( (d->num) == 1 || (d->num) == 2) {
		(d->result) = 1;
		/**printf("result = %d\n", d->result);*/
	}
	else {
		
		data *d1 = (data*)malloc(sizeof(data));
		data *d2 = (data*)malloc(sizeof(data));

		d1->num = (d->num) -1;
		/**printf("d1->num = %d\n", d1->num);*/
		d2->num = (d->num) -2;
		/**printf("d2->num = %d\n", d2->num);*/

		pthread_t t1, t2;

		int ret1 = pthread_create(&t1, NULL, rf, (void*)d1);
		if (ret1 != 0) printf("pthread create error\n");	

		int ret2 = pthread_create(&t2, NULL, rf, (void*)d2);
		if (ret2 != 0) printf("pthread create error\n");	
		
		pthread_join(t1, NULL);			
		pthread_join(t2, NULL);
		(d->result) = (d1->result) + (d2->result);			
	}
	/**pthread_exit(NULL);*/
}

int main() {
	int num;
	scanf("%d", &num);
	data* d;
	d->num = num;
	rf((void*)d);
	/**pthread_t t;*/
	/**int ret = pthread_create(&t, NULL, rf, (void*)d);*/
	printf("result = %d\n", d->result);
}
