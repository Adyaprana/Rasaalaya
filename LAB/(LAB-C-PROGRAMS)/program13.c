// PROGRAM: 13
// Question:
// Write a program to find a subset of a given set S={s1,s2,….,sn} of n positive integers
// whose sum is equal to a given positive integer d. 
// A suitable message is to be displayed if the given problem instance doesn’t have a solution
// and prove its efficiency.

#include <stdio.h>

int s[10], d, n, set[10], count = 0;
int flag = 0;

void display(int);
void subset(int, int);

int main() {
    int i;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the set values: ");
    for (i = 0; i < n; ++i)
        scanf("%d", &s[i]);

    printf("Enter the desired sum: ");
    scanf("%d", &d);

    printf("\nSubsets with sum = %d are:\n", d);
    subset(0, 0);

    if (flag == 0)
        printf("\nNo subset found with the given sum.\n");

    return 0;
}

void subset(int sum, int i) {
    if (sum == d) {
        flag = 1;
        display(count);
        return;
    }

    if (sum > d || i >= n)
        return;

    // include s[i] in the subset
    set[count] = s[i];
    count++;
    subset(sum + s[i], i + 1);

    // exclude s[i] from the subset
    count--;
    subset(sum, i + 1);
}

void display(int count) {
    int i;
    printf("{ ");
    for (i = 0; i < count; i++) {
        printf("%d", set[i]);
        if (i < count - 1)
            printf(", ");
    }
    printf(" }\n");
}
