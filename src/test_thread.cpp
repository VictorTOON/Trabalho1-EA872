#include <thread>
#include <iostream>

void test(int inicio, int fim, int pei, int pou) {
	int i = inicio;
	while (1) {
		if (i++ % pei == pou){
			std::cout << i << std::endl;
		}
		if (i == fim){
			break;
		}
	} 
}

int main () {
	std::thread t(test, 120, 10000000, 1000, 4);
	t.join();
	return 0;
}
