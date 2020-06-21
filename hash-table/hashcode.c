#include <stdio.h>

int hashCode1(const char* p, int len) { //hashing character array
	int h = 0;
	for (int i = 0; i < len; i++) {
		/*This is called a cyclic 5-bit shift:
			bitwise or of a 5 bit left shift and a 27-bit right shift.
			This assumes a 32-bit integer word*/
		h = (h << 5) | (h >> 27);
		h += (int) p[i];
	}
	return hashCode2(h);
}

/*This is actually supposed to be more intricate.
	But for now, we'll assume it just returns the integer*/
int hashCode2(int n) { return n; }

int main() {
	const char arr[3] = {'v', 'i', 'k'}; 
	const char *ptr = arr; 
	printf("%d", hashCode1(ptr, 2));
	printf("\n");
}