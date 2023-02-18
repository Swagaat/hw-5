// SOlution-1
#include <stdio.h> 

int main() {

  int n, i, pr = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // 0 and 1 are not prime numbers
  // changing pr to 1 for non-prime number
  if (n == 0 || n == 1)
    pr = 1;

  for (i = 2; i <= n / 2; ++i) {

    // if n is divisible by i, then n is not prime
    // so changing pr to 1 for non-prime number
    if (n % i == 0) {
      pr = 1;
      break;
    }
  }

  // pr is 0 for prime numbers
  if (pr == 0)
    printf("%d is a prime number.", n);
  else
    printf("%d is not a prime number.", n);

  return 0;
}


// Solution-2
#include <stdio.h>

int main() {

    int a = 8, b = 4;
    printf("Answer after Anding = %d", a & b);

    return 0;
}


// Solution-3
#include <stdio.h>
 
void main()
{
    int n1 = 0, n2 = 1, n3, num, sum = 0;
 
    printf("Enter the value of num \n");
    scanf("%d", &num);
    printf("First %d FIBONACCI numbers are ...\n", num);
    printf("%d\n", n1);
    printf("%d\n", n2);
    sum = 2; /* fib1 and fib2 are already used */
    while (sum < num)
    {
        n3 = n1 + n2;
        sum++;
        printf("%d\n", n3);
        n1 = n2;
        n2 = n3;
   }
}



// Solution-4
#include <stdio.h>
 
void main()
{
    double number, sum = 0, i;
 
    printf("\n enter the number ");
    scanf("%lf", &number);
    for (i = 1; i <= number; i++)
    {
        sum = sum + (1 / i);
        if (i == 1)
            printf("\n 1 +");
        else if (i == number)
            printf(" (1 / %lf)", i);
        else
            printf(" (1 / %lf) + ", i);
    }
    printf("\n The sum of the given series is %.2lf", sum);
}




// Solution-5
#include <stdio.h>
int largest(int arr[], int n)
{
	int i;
	
	// Initialize maximum element
	int max = arr[0];
	
	// compare every element with current max
	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

int main()
{
	int arr[] = {5, 4, 7, 1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Largest in given array is %d", largest(arr, n));
	return 0;
}



// Solution-6
#include <stdio.h>
 
int main() {
  float a[3][2], b[3][2], result[3][2];

  // Taking input for the first matrix
  printf("Enter value for 1 matrix: ");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%f", &a[i][j]);
    }
  }

  // Taking input for the second matrix
  printf("Enter value for 2 matrix: ");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%f", &b[i][j]);
    }
  }

  // Adding the corresponding elements of the two matrices
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      result[i][j] = a[i][j] + b[i][j];
    }
  }

  // Displaying the sum of the matrices
  printf("Sum of matrix is\n");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      printf("%.0f ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}





// Solution-7
#include <stdio.h>
 
int main()
{
    int size;
    printf("Enter length of array: ");
    scanf("%d", &size);
 
    int arr[size];
    printf("Enter each element in array: ");
 
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
 
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
 
    float average = (float)sum / size;
    printf("Average value in array: %.1f", average);
 
    return 0;
}