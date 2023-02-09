#include <iostream>
using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    printf("\nElements in array are:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d", arr.A[i]);
    };
    printf("\n\n");
};

int BinarySearch(struct Array arr, int key) {
    int low = 0;
    int mid;
    int high = arr.length-1;

    while (low <= high) {
        
        mid = (low+high) / 2;
        
        if (key == arr.A[mid]) {
            // Case: query element equal to mid val
            return mid;
        } else if (key < arr.A[mid]) {
            // Case: query element less than mid val
            high = mid - 1;
        } else {
            // Case: query element greater than mid val
            low = mid + 1;
        }
    }
    return -1;
};

int main() {
    struct Array arr;
    int n, query;

    // How big of an array do you want to initialize
    printf("Enter the size of array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));

    // How many elements you have
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr.length = n;

    // Inputting the elements
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.A[i]);
    };

    Display(arr);

    printf("Enter the element req. to find: ");
    scanf("%d", &query);
    
    if (BinarySearch(arr, query) != -1) {
        printf("Element found at index: %d\n", BinarySearch(arr, query));
    } else {
        printf("Element doesn't exist in arr.\n");
    };

    return 0;
}
