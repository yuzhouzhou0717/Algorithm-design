#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

//int main() {
//	long long sum=0;
//	for (long long i = 1;i <= 20230408;i++) {e
//		sum +=i;	
//	}
//	printf("%lld", sum);
//}

//#include <stdio.h>
//
//int max_events_to_win(int n, int A[], int B[], int C[]) {
//    int max_events = -1;
//
//    // �ܹ���2^n���¼�ѡ�����
//    for (int mask = 0; mask < (1 << n); mask++) {
//        int X = 0, Y = 0, Z = 0;
//        int event_count = 0;
//
//        for (int i = 0; i < n; i++) {
//            // ���� i ���¼��Ƿ�ѡ��
//            if (mask & (1 << i)) {
//                X += A[i];
//                Y += B[i];
//                Z += C[i];
//                event_count++;
//            }
//        }
//
//        // ���ʤ������
//        if (X > Y + Z || Y > X + Z || Z > X + Y) {
//            if (event_count > max_events) {
//                max_events = event_count;
//            }
//        }
//    }
//
//    return max_events;
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n); // ʹ�� scanf ���� scanf_s
//    int A[100], B[100], C[100];
//
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &A[i]);
//    }
//    for (int j = 0; j < n; j++) {
//        scanf("%d", &B[j]);
//    }
//    for (int k = 0; k < n; k++) {
//        scanf("%d", &C[k]);
//    }
//
//    int result = max_events_to_win(n, A, B, C);
//    printf("%d\n", result);
//
//    return 0;
//}
