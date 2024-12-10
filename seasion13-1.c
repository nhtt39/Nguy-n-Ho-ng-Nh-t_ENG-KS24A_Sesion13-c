#include <stdio.h>

void taoMaTran(int hang, int cot, int maTran[hang][cot]) {
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i+1, j+1);
            scanf("%d", &maTran[i][j]);
        }
    }
}

void inMaTran(int hang, int cot, int maTran[hang][cot]) {
    printf("Ma tran ban da nhap:\n");
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int hang, cot;
    
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", &hang);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &cot);
    
    int maTran[hang][cot];
    
    taoMaTran(hang, cot, maTran);
    
    inMaTran(hang, cot, maTran);
    
    return 0;
}

