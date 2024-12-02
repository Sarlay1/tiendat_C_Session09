#include <stdio.h>
int main() {
	// Khai bao mang va gia tri phan tu
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int position, newValue;
    // In mang ban dau ra man hinh
    printf("Mang ban dau:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Nhap vi tri can sua va gia tri phan tu moi
    printf("Nhap vi tri can sua (tu 0 den %d): ", size - 1);
    scanf("%d", &position);
    // Kiem tra vi tri phan tu
    if (position < 0 || position >= size) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    // Ghi de gia tri moi
    arr[position] = newValue;
    // In mang sau khi sua
    printf("Mang sau khi sua:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Ket thuc chuong trinh
    return 0;
}
