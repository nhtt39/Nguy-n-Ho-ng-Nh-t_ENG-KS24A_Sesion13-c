#include <stdio.h>

#define MAX_SIZE 100

void sortAscend(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDescend(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice, pos, value;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu can nhap (toi da %d): ", MAX_SIZE);
                scanf("%d", &n);
                if (n > MAX_SIZE) {
                    printf("So phan tu vuot qua gioi han! Duoc nhap toi da %d phan tu.\n", MAX_SIZE);
                    n = MAX_SIZE;
                }
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Mang hien tai rong!\n");
                } else {
                    printf("Gia tri cac phan tu trong mang:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (n < MAX_SIZE) {
                    printf("Nhap vi tri can them (0 den %d): ", n);
                    scanf("%d", &pos);
                    if (pos < 0 || pos > n) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        printf("Nhap gia tri phan tu can them: ");
                        scanf("%d", &value);
                        for (int i = n; i > pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos] = value;
                        n++;
                    }
                } else {
                    printf("Mang da day! Khong the them phan tu.\n");
                }
                break;

            case 4:
                printf("Nhap vi tri can sua (0 den %d): ", n - 1);
                scanf("%d", &pos);
                if (pos >= 0 && pos < n) {
                    printf("Nhap gia tri moi cho phan tu: ");
                    scanf("%d", &value);
                    arr[pos] = value;
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;

            case 5:
                printf("Nhap vi tri can xoa (0 den %d): ", n - 1);
                scanf("%d", &pos);
                if (pos >= 0 && pos < n) {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;

            case 6:
                printf("Chon cach sap xep:\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Chon chuc nang: ");
                char sortChoice;
                getchar();
                scanf("%c", &sortChoice);
                if (sortChoice == 'a') {
                    sortDescend(arr, n);
                    printf("Sap xep giam dan thanh cong.\n");
                } else if (sortChoice == 'b') {
                    sortAscend(arr, n);
                    printf("Sap xep tang dan thanh cong.\n");
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;

            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Chon cach tim kiem:\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Chon chuc nang: ");
                char searchChoice;
                getchar();
                scanf("%c", &searchChoice);
                int result;
                if (searchChoice == 'a') {
                    result = linearSearch(arr, n, value);
                    if (result != -1) {
                        printf("Phan tu %d tim thay tai vi tri %d.\n", value, result);
                    } else {
                        printf("Phan tu %d khong ton tai trong mang.\n", value);
                    }
                } else if (searchChoice == 'b') {
                    sortAscend(arr, n); // Tìm ki?m nh? phân yêu c?u m?ng dã du?c s?p x?p
                    result = binarySearch(arr, n, value);
                    if (result != -1) {
                        printf("Phan tu %d tim thay tai vi tri %d.\n", value, result);
                    } else {
                        printf("Phan tu %d khong ton tai trong mang.\n", value);
                    }
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

