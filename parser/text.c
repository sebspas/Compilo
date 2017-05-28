int Fibonacci(int n)
{
    if (n < 2)
    {
		return n;
    }
    else
    {
		return (Fibonacci(n - 1) + Fibonacci(n - 2));
    }
}

int main()
{
    int a = Fibonacci(10);
	printf(a);
    return 0;
}
