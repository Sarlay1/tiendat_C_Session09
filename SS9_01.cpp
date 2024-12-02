#include <stdio.h>
int main() {
    int arr[100];
    int size, value, position;

    // Nhap so phan tu
    printf("Nhap so phan tu muon nhap (toi da 100): ");
    scanf("%d", &size);

    // Kiem tra kich thuoc mang
    if (size < 0 || size > 100) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    // Nhap gia tri phan tu vao mang
    for (int i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Nhap gia tri nguoi dung muon chen
    printf("Nhap gia tri muon chen: ");
    scanf("%d", &value);

    printf("Nhap vi tri muon chen (tu 0 den %d): ", size);
    scanf("%d", &position);

    // Kiem tra vi tri phan tu
    if (position < 0 || position > size) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    // Chen phan tu vao vi tri da nhap
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    size++;

    // In mang ra man hinh sau khi chen
    printf("Mang sau khi chen:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

