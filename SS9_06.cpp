#include <stdio.h>
// Hien menu va lua chon cua nguoi dung
int displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap kich thuoc va gia tri phan tu cua mang\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In gia tri cac phan tu la le va tinh tong\n");
    printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
    printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
    printf("6. In ra cac phan tu nam tren duong cheo phu\n");
    printf("7. In ra dong co tong gia tri cac phan tu lon nhat\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}
// Nhap so hang , so cot va nhap phan tu
int inputMatrix(int matrix[][100], int *rows, int *cols) {
    printf("Nhap so hang cua mang: ");
    scanf("%d", rows);
    printf("Nhap so cot cua mang: ");
    scanf("%d", cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    return 0;
}
// In gia tri cac phan tu cua mang theo ma tran
int printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// In gia tri cac phan tu la le va tinh tong
int printOddAndSum(int matrix[][100], int rows, int cols) {
    int sum = 0;
    printf("Cac phan tu le la: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                printf("%d ", matrix[i][j]);
                sum += matrix[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le la: %d\n", sum);
    return sum;
}
// In ra cac phan tu nam tren duong bien va tinh tich
int printBorderAndProduct(int matrix[][100], int rows, int cols) {
    int product = 1;
    printf("Cac phan tu nam tren duong bien: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", matrix[i][j]);
                product *= matrix[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren duong bien: %d\n", product);
    return product;
}
// In ra cac phan tu nam tren duong cheo chinh
int printMainDiagonal(int matrix[][100], int rows, int cols) {
    printf("Cac phan tu nam tren duong cheo chinh: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
    return 0;
}
// In ra cac phan tu nam tren duong cheo phu
int printSecondaryDiagonal(int matrix[][100], int rows, int cols) {
    printf("Các ph?n t? n?m trên du?ng chéo ph?: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][cols - i - 1]);
    }
    printf("\n");
    return 0;
}
// In ra dong co tong gia tri cac phan tu lon nhat
int findRowWithMaxSum(int matrix[][100], int rows, int cols) {
    int maxSum = 0, maxRow = 0;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        if (i == 0 || sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    printf("Dong co tong lon nhat la dong %d voi tong: %d\n", maxRow + 1, maxSum);
    return maxRow;
}
int main() {
    int matrix[100][100];
    int rows = 0, cols = 0;
    int choice;

    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                inputMatrix(matrix, &rows, &cols);
                break;
            case 2:
                printf("Ma tran:\n");
                printMatrix(matrix, rows, cols);
                break;
            case 3:
                printOddAndSum(matrix, rows, cols);
                break;
            case 4:
                printBorderAndProduct(matrix, rows, cols);
                break;
            case 5:
                printMainDiagonal(matrix, rows, cols);
                break;
            case 6:
                printSecondaryDiagonal(matrix, rows, cols);
                break;
            case 7:
                findRowWithMaxSum(matrix, rows, cols);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
                break;
        }
    } while (choice != 8);
// Ket thuc chuong trinh
    return 0;
}
