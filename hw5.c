//Solution-1:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int label;
    double pr;
} PetriDish;

int main() {
    int total, i, j;
    printf("Enter total number of Petri dishes: ");
    scanf("%d", &total);

    // Initialize empty arrays to store data for A and B sub-species
    PetriDish a_data[total], b_data[total];
    int a_count = 0, b_count = 0;

    // Loop through each Petri dish to collect original and new bacterial numbers
    for (i = 0; i < total; i++) {
        int label, original, new;
        printf("Enter Petri dish %d label, original bacterial number, new bacterial number after one hour reproduction: ", i+1);
        scanf("%d %d %d", &label, &original, &new);
        // Calculate the reproduction rate (PR) for the current Petri dish
        double pr = (double)new / original;
        // Add data to the appropriate sub-species array based on PR value
        if (a_count == 0 || fabs(pr - a_data[0].pr) < fabs(pr - b_data[0].pr)) {
            a_data[a_count].label = label;
            a_data[a_count].pr = pr;
            a_count++;
        } else {
            b_data[b_count].label = label;
            b_data[b_count].pr = pr;
            b_count++;
        }
    }

    // Sort the data arrays in ascending order of PR values using bubble sort
    for (i = 0; i < a_count; i++) {
        for (j = 0; j < a_count-i-1; j++) {
            if (a_data[j].pr > a_data[j+1].pr) {
                PetriDish temp = a_data[j];
                a_data[j] = a_data[j+1];
                a_data[j+1] = temp;
            }
        }
    }
    for (i = 0; i < b_count; i++) {
        for (j = 0; j < b_count-i-1; j++) {
            if (b_data[j].pr > b_data[j+1].pr) {
                PetriDish temp = b_data[j];
                b_data[j] = b_data[j+1];
                b_data[j+1] = temp;
            }
        }
    }

    // Print the final results
    printf("%d in A sub-species and Petri dish labels from smaller PR to bigger PR are ", a_count);
    for (i = 0; i < a_count; i++) {
        printf("%d ", a_data[i].label);
    }
    printf("\n%d in B sub-species and Petri dish labels from smaller PR to bigger PR are ", b_count);
    for (i = 0; i < b_count; i++) {
        printf("%d ", b_data[i].label);
    }
    printf("\n");

    return 0;
}

//Solution-2:
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int numbers[100], odds[100], evens[100], num_count = 0, odd_count = 0, even_count = 0, i;
    
    printf("Enter a series of integer numbers: ");
    fgets(input, 100, stdin);
    
    // Parse the input string and separate odd and even numbers
    char *token = strtok(input, " ");
    while (token != NULL) {
        int num = atoi(token);
        numbers[num_count++] = num;
        if (num % 2 == 0) {
            evens[even_count++] = num;
        }
        else {
            odds[odd_count++] = num;
        }
        token = strtok(NULL, " ");
    }
    
    // Find the maximum odd number and the minimum even number
    int max_odd = -1, min_even = -1;
    for (i = 0; i < odd_count; i++) {
        if (odds[i] > max_odd) {
            max_odd = odds[i];
        }
    }
    for (i = 0; i < even_count; i++) {
        if (min_even == -1 || evens[i] < min_even) {
            min_even = evens[i];
        }
    }
    
    // Calculate the absolute value of the difference between max odd and min even
    int result = abs(max_odd - min_even);
    
    printf("Result is: %d\n", result);
    
    return 0;
}

// Solution-3:
#include <stdio.h>

int find_king(int n, int m) {
    // create an array of numbers from 0 to n-1
    int monkeys[n];
    for (int i = 0; i < n; i++) {
        monkeys[i] = i;
    }

    // start counting from the first monkey
    int i = 0;
    while (n > 1) {
        // count m monkeys in clockwise direction and remove the mth monkey
        i = (i + m - 1) % n;
        for (int j = i; j < n-1; j++) {
            monkeys[j] = monkeys[j+1];
        }
        n--;
    }

    // the last remaining monkey is the king
    return monkeys[0];
}

int main() {
    int n, m;
    printf("Enter total number of monkeys in a group: ");
    scanf("%d", &n);
    printf("Enter m value: ");
    scanf("%d", &m);

    // find the king's number and print the result
    int king = find_king(n, m);
    printf("The king will be %d\n", king);

    return 0;
}

// Solution-4:
#include <stdio.h>
#include <stdlib.h> /* for exit() */

int main(void)
{
    int amount, bills, i;
    int denominations[] = {100, 50, 20, 10, 5, 1};
    int num_denominations = sizeof(denominations) / sizeof(denominations[0]);

    printf("\nEnter a dollar amount: ");
    if (scanf("%d", &amount) != 1 || amount < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < num_denominations; i++) {
        bills = amount / denominations[i];
        printf("$%d bills: %d\n", denominations[i], bills);
        amount = amount - (bills * denominations[i]);
    }

    return 0;
}



// Solution-5:
#include <stdio.h>

int main() {
    // Define the expert reviews
    int expert_a = 2;
    int expert_b = 4;
    int expert_c[3] = {1, 2, 4};
    char expert_d[] = "B is wrong";

    // Iterate over the cars and experts to find the correct answer
    int car;
    for (car = 1; car <= 4; car++) {
        char *correct_expert = NULL;
        if (expert_a == car) {
            correct_expert = "A";
        }
        else if (expert_b == car) {
            continue;
        }
        else if (car == 3) {
            int i;
            for (i = 0; i < 3; i++) {
                if (expert_c[i] == car) {
                    continue;
                }
                else {
                    correct_expert = (i == 0) ? "C" : NULL;
                    break;
                }
            }
        }
        else if (strcmp(expert_d, "B is wrong") == 0) {
            if (car == 4) {
                correct_expert = "D";
            }
        }
        else {
            correct_expert = "B";
        }
        if (correct_expert != NULL) {
            printf("The best car is %d, and the correct expert is %s.\n", car, correct_expert);
            break;
        }
    }

    return 0;
}



// Solution-6:
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int row, col;
    int array[MAX_SIZE][MAX_SIZE];

    // Input the size of the array
    printf("Enter size of row & column: ");
    scanf("%d %d", &row, &col);

    // Input the elements of the array
    printf("Enter each element:\n");
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int malignant_cells = 0;
    // Detect malignant cells
    for(int i=1; i<row-1; i++) {
        for(int j=1; j<col-1; j++) {
            if(array[i][j] < 50) {
                if(array[i-1][j] > 50 && array[i+1][j] > 50 && array[i][j-1] > 50 && array[i][j+1] > 50) {
                    malignant_cells++;
                }
            }
        }
    }

    // Print the result
    printf("Result of malignant cell detection: %d\n", malignant_cells);

    return 0;
}
