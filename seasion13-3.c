#include <stdio.h>
#include <stdbool.h>

int isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void nhapMang(int n, int m, int arr[n][m]) {
    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap arr[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMang(int n, int m, int arr[n][m]) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inGoc(int n, int m, int arr[n][m]) {
    printf("Cac phan tu o goc ma tran:\n");
    printf("arr[0][0] = %d\n", arr[0][0]);
    printf("arr[0][%d] = %d\n", m-1, arr[0][m-1]);
    printf("arr[%d][0] = %d\n", n-1, arr[n-1][0]);
    printf("arr[%d][%d] = %d\n", n-1, m-1, arr[n-1][m-1]);
}

void inBien(int n, int m, int arr[n][m]) {
    printf("Cac phan tu tren duong bien:\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", arr[0][j]);
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", arr[n-1][j]);
    }
    printf("\n");

    for (int i = 1; i < n-1; i++) {
        printf("%d ", arr[i][0]);
    }
    printf("\n");

    for (int i = 1; i < n-1; i++) {
        printf("%d ", arr[i][m-1]);
    }
    printf("\n");
}

void inChieu(int n, int m, int arr[n][m]) {
    printf("Cac phan tu tren duong chieu chinh va chieu phu:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
        if (i != n-i-1) {
            printf("%d ", arr[i][m-i-1]);
        }
    }
    printf("\n");
}

void inSNT(int n, int m, int arr[n][m]) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPrime(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m;
    int choice;

    printf("Nhap so hang (n): ");
    scanf("%d", &n);
    printf("Nhap so cot (m): ");
    scanf("%d", &m);

    int arr[n][m];

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong chieu chinh va chieu phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(n, m, arr);
                break;
            case 2:
                inMang(n, m, arr);
                break;
            case 3:
                inGoc(n, m, arr);
                break;
            case 4:
                inBien(n, m, arr);
                break;
            case 5:
                inChieu(n, m, arr);
                break;
            case 6:
                inSNT(n, m, arr);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

