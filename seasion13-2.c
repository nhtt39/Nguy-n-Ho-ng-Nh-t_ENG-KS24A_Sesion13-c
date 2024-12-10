#include <stdio.h>

int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    
    printf("Nhap vao so a: ");
    scanf("%d", &a);
    printf("Nhap vao so b: ");
    scanf("%d", &b);
    
    int result = ucln(a, b);
    printf("UCLN cua %d va %d la: %d\n", a, b, result);
    
    return 0;
}

