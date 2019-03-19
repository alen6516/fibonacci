#include <stdio.h>

int recursive_fibonacci(int num) {
	if (num == 1 || num == 2)
		return 1;
	else
		return recursive_fibonacci(num-1) + recursive_fibonacci(num-2);
}

int loop_fibonacci(int num) {
	if (num == 1 || num == 2) return 1;
	
	int f = 1;		// a1 initialize
	int b = 1;		// a2 initialize
	for (int i=2; i<num; i++) { 
		// i starts from 2 beacuse the return var. b is a2
		b = f+b;
		f = b-f;
	}
	return b;
}

int main() {
	int num = 40;
	printf("%d\n", loop_fibonacci(num));
}
