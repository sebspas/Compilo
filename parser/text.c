int h(int res, int a) {
	if (a > 0) {
		h(res * a, a - 1);
	} 
}

int main() {
	h(1, 5);
}
