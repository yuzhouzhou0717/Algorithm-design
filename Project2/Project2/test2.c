#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    scanf("%s", a);
    int len = strlen(a);
    int m = 0;
    scanf("%d", &m);
    char str[100] = { 0 };
    for (int i = 0;i<len-m;i++) {
        str[i] = a[m];
        m++;
        if (m == len) {
            break;
        }
    }
    str[len - m] = '\0'; // Ìí¼Ó¿Õ×Ö·ûÀ´ÖÕÖ¹×Ö·û´®
    printf("%s", str);


    return 0;
}
