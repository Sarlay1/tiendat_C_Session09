#include <stdio.h>
// Hien thi menu va lua chon
int displayMenu(){
    printf("\nMENU\n");
    printf("1. Nhap so phan tu va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu\n");
    printf("3. In ra gia tri cac phan tu so chan va tinh tong\n");
    printf("4. In ra gia tri lon nhat va nho nhat\n");
    printf("5. In ra cac phan tu la so nguyen to va tinh tong\n");
    printf("6. Nhap vao 1 so va kiem tra so lan lap trong mang\n");
    printf("7. Them 1 gia tri vao vi tri chi dinh\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban la: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Nhap phan tu vao mang
int inputArray(int arr[], int *size) {
    printf("Nhap so phan tu: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    return *size;
}

// In mang ra man hinh
int printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

// In cac phan tu ra man hinh va tinh tong
int printEvenAndSum(int arr[], int size) {
    int sum = 0;
    printf("Cac phan tu chan: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac phan tu chan: %d\n", sum);
    return sum;
}

// Tim gia tri lon nhat va gia tri nho nhat
int findMinMax(int arr[], int size, int *min, int *max) {
    if (size <= 0) return 0;
    *min = *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
    return 1;
}

// Xu ly kiem tra so nguyen to
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// In cac so nguyen to ra man hinh va tinh tong
int printPrimesAndSum(int arr[], int size) {
    int sum = 0;
    printf("Cac so nguyen to la: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac so nguyen to la: %d\n", sum);
    return sum;
}

// Xu ly dem so lan xuat hien cua 1 so
int countOccurrences(int arr[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}

// Them phan tu vao vi tri chi dinh
int insertElement(int arr[], int *size, int pos, int newValue) {
    if (pos < 0 || pos > *size || *size >= 100) {
        return 0;  // Không th? thêm ph?n t?
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = newValue;
    (*size)++;
    return 1;
}

int main() {
    int arr[100];
    int size = 0;
    int choice;

    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                printf("Cac phan tu trong mang la: ");
                printArray(arr, size);
                break;
            case 3:
                printEvenAndSum(arr, size);
                break;
            case 4: {
                int min, max;
                if (findMinMax(arr, size, &min, &max)) {
                    printf("Gia tri lon nhat la: %d\n", max);
                    printf("Gia tri nho nhat la: %d\n", min);
                } else {
                    printf("Mang trong!\n");
                }
                break;
            }
            case 5:
                printPrimesAndSum(arr, size);
                break;
            case 6: {
                int x;
                printf("Nhap so can thong ke: ");
                scanf("%d", &x);
                int count = countOccurrences(arr, size, x);
                printf("So lan xuat hien cua %d: %d\n", x, count);
                break;
            }
            case 7: {
                int pos, newValue;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                printf("Nhap gia tri can them: ");
                scanf("%d", &newValue);
                if (insertElement(arr, &size, pos, newValue)) {
                    printf("Da them vao mang!\n");
                } else {
                    printf("Khong the them vao mang!\n");
                }
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long lua chon lai: \n");
                break;
        }
    } while (choice != 8);

    return 0;
}
