#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void helperprint(int a, int p1[9][7], int p2[9][2]) {
	printf("%-11s���� 1 ���� 2 ���� 3 ��Ʈ����ũ ��\n","HELPER");
	for (int i = 0; i < a; i++) {
		
		printf("\n< %dȸ�� >  ", i + 1);
		for (int j = 0; j < 3; j++) {
			printf("%6d", p1[i][j]);
		}
		for (int j = 0; j < 2; j++) {
			printf("%8d", p2[i][j]);
		}
		
	}
	printf("\n");
}
int main(void) {
	int a[7], input[7], cnt = 0, len = 0, st, ba, helper[9][7] = { 0, }, score[9][2] = { 0, };
	srand((unsigned)time(0));
	printf("���ڸ��Ͻ��� �Է��ϼ���(3<=len<=7) : ");
	scanf("%d", &len);
	for (int i = 0; i < len; i++) {
		a[i] = rand() % 9+1;
		for (int j = 0; j <i; j++) {
			if (a[i] == a[j]) {
				i--;
			}

		}
	}

	while (1) {
		cnt++;
		st = ba = 0;
		if (cnt != 1) {
			helperprint(cnt - 1, helper, score);
		}
		printf("\n\n-------------------------------------------\n\n");
		printf("\n[ %d ȸ�� �Դϴ� ]\n", cnt);
		
		printf("���� %d ���� �Է� ���ּ��� : ", len);
		for (int i = 0; i < len; i++) {
			scanf("%d", &input[i]);
			helper[cnt - 1][i] = input[i];
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (a[i] == input[j]) {
					if (i == j) {
						st++;
					}
					else
						ba++;
				}
			}
		}
		score[cnt - 1][0] = st;
		score[cnt - 1][1] = ba;
		if (st == len) {
			printf("%dȸ �õ� ���� �� �������ϴ�.\n�ڽ¸��߽��ϴ١�\n", cnt);
			break;
		}
		else
			printf("strike:%d\nball:%d\n", st, ba);
		printf("\n");
		if (cnt == 9) {
			printf("\n���й��߽��ϴ١�\n���� : ");
			for (int i = 0; i < 3; i++) {
				printf("%2d", a[i]);
			}
			printf("\n");
			break;
		}
	}
	return 0;
}