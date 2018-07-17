#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void helperprint(int a, int p1[9][7], int p2[9][2]) {
	printf("%-11s숫자 1 숫자 2 숫자 3 스트라이크 볼\n","HELPER");
	for (int i = 0; i < a; i++) {
		
		printf("\n< %d회차 >  ", i + 1);
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
	printf("몇자리하실지 입력하세요(3<=len<=7) : ");
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
		printf("\n[ %d 회차 입니다 ]\n", cnt);
		
		printf("숫자 %d 개를 입력 해주세요 : ", len);
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
			printf("%d회 시도 만에 다 맞혔습니다.\n★승리했습니다★\n", cnt);
			break;
		}
		else
			printf("strike:%d\nball:%d\n", st, ba);
		printf("\n");
		if (cnt == 9) {
			printf("\n☆패배했습니다☆\n정답 : ");
			for (int i = 0; i < 3; i++) {
				printf("%2d", a[i]);
			}
			printf("\n");
			break;
		}
	}
	return 0;
}