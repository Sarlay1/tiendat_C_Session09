#include <stdio.h>
int main() {
	//Khai bao mang va bien
    int arr[100];
    int size, position;
    // Nhap so phan tu
    printf("Nhap so phan tu muon nhap (toi da 100): ");
    scanf("%d", &size);
    // Kiem tra kich thuoc hop le
    if (size < 0 || size > 100) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }
    // Nhap cac phan tu vao mang
    for (int i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Nhap vi tri can xoa 
    printf("Nhap vi tri can xoa (tu 0 den %d): ", size - 1);
    scanf("%d", &position);
    // Kiem tra vi tri phan tu
    if (position < 0 || position >= size) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }
    // Xoa phan tu tai vi tri da nhap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    // In mang sau khi xoa
    printf("Mang sau khi xoa:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
