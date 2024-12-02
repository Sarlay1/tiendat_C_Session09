#include<stdio.h>
	// Nhap mang va so luong phan tu
int nhapMang(int arr[], int maxSize) {
    int n, i;
    printf("Nhap so luong phan tu (toi da %d): ", maxSize);
    scanf("%d", &n);
    if (n > maxSize) {
        printf("So luong phan tu vuot qua gioi han (%d). Gioi han so phan tu la %d.\n", n, maxSize);
        n = maxSize;
    }
    for (i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    return n;
}
// Hien thi mang ra man hinh 
int inRaMang(int arr[], int n) {
    if (n == 0) {
        printf("Mang trong.\n");
        return n;
    }
    printf("arr[]: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return n;
}
// Them phan tu moi  
int themPhanTuMoi(int arr[], int n, int maxSize) {
    if (n >= maxSize) {
        printf("Mang da day, khong the them phan tu.\n");
        return n;
    }
    int value;
    printf("Nhap gia tri can thêm: ");
    scanf("%d", &value);
    arr[n] = value;
    printf("Dien them %d vao mang.\n", value);
    return n + 1;
}
// Sua phan tu trong mang 
int thayDoiPhanTu(int arr[], int n) {
    if (n == 0) {
        printf("Mang trong, khong co phan tu de sua.\n");
        return n;
    }
    int index, newValue;
    printf("Nhap vi tri can sua (tinh tu 0): ");
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        printf("Nhap gia tri moi: ");
        scanf("%d", &newValue);
        arr[index] = newValue;
        printf("Da cap nhat phan tu tai vi tri %d thanh %d.\n", index, newValue);
    } else {
        printf("Vi tri khong hop le.\n");
    }
    return n;
}
// Xoa phan tu trong mang 
int xoaPhanTu(int arr[], int n) {
    if (n == 0) {
        printf("Mang trong, khong co phan tu de xoa.\n");
        return n;
    }
    int index;
    printf("Nhap vi tri can xoa (tinh tu 0): ");
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        int removedValue = arr[index];
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        printf("Da xoa phan tu tai vi tri %d.\n", removedValue, index);
        return n - 1;
    } else {
        printf("Vi tri khong hop le.\n");
        return n;
    }
}
int main(){
    int maxSize;
    printf("Nhap kich thuoc toi da cua mang: ");
    scanf("%d", &maxSize);
    int arr[maxSize];
    int n = 0;
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu moi cho mang\n");
        printf("4. Sua phan tu trong mang\n");
        printf("5. Xoa phan tu trong mang\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                n = nhapMang(arr, maxSize);
                break;
            case 2:
                inRaMang(arr, n);
                break;
            case 3:
                n = themPhanTuMoi(arr, n, maxSize);
                break;
            case 4:
                thayDoiPhanTu(arr, n);
                break;
            case 5:
                n = xoaPhanTu(arr, n);
                break;
            case 6:
                printf("Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Lua chon cua ban khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);
    return 0;
} 
