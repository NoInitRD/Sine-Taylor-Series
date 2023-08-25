#include <stdio.h>
#include <math.h>
#include <stdbool.h>

long double longAbs(long double x)
{
	long double result;
	result = (x < 0) ? -x : x;
	return result;
}

bool epsilonEquals(long double x, long double y)
{	
        return longAbs(x - y) < 1e-17L;
}

//recursion is more fun
long double sineRecursive(long double libSine, long double x, long double current, long double result, int iter)
{
        if(epsilonEquals(result, libSine)) return result;
        result += current;

        printf("Iteration: %d Value: %.50Lf \n", iter, result);
        current *= -1.0 * x * x / ((2 * iter) * (2 * iter + 1)); //taylor series
	
        return sineRecursive(libSine, x, current, result, ++iter);
}

long double sineRecursiveHelper(long double x)
{
	return sineRecursive(sinl(x), x, x, 0.0, 1);
}

int main()
{
	printf("----------------------------------------------------------\n");
	long double pi = 3.1415926535897932384626433832795028841971693993751;
	long double x;
	printf("Sin(x) where x is: ");
	scanf("%Lf", &x);
	
	if(x > pi || x < pi * -1) x = fmod(x, 2 * pi);

	long double result = sineRecursiveHelper(x);
	long double libraryResult = sinl(x);

	printf("\nLibrary result: %.50Lf \n", libraryResult);
	printf("Difference of: %.50Lf \n", longAbs(libraryResult - result));
	return 0;
}
