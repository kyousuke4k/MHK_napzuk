#include<stdio.h>
#include<iostream>
#include<time.h>
#include<cmath>
#include<windows.h>
using namespace std;
int a, gcduv, b;
int x, e, P;

inline void InitRand()
{
	srand((unsigned int)time(NULL));
}

inline int Dice()
{
	return rand() % 300 + 1;
}

inline int Dice2()
{
	return rand() % 5000 + P;
}

inline int Dice3()
{
	return rand() % P - 1;
}

bool isPrimeNum(int x) {//�f���Ȃ�TRUE��Ԃ�

	if (x <= 1) {
		return false;
	}

	//sqrt�͈����̕�������double�^�ŕԂ��̂�,int�ŃL���X�g
	int n = (int)sqrt((double)x);

	for (int i = 2; i <= n; i++) {
		if (x%i == 0) {
			return false;	//����؂鐮��������ꍇ�A����I��
		}
	}
	return true;	//����؂鐮�����Ȃ��ꍇ�A�f��
}

//�g�����[�N���b�h
int yukurid(int *P, int *e) {
	//Step1
	int P1 = 1;
	int P2 = *P;
	int P3 = 0;

	int e1 = 0;
	int e2 = *e;
	int e3 = 1;

	for (int i = 2; i > 1; i++) {
		//Step2
		int w = P2 / e2;
		int t1 = P2 - e2 * w;
		int t2 = P2 - e2 * w;
		int t3 = P3 - e3 * w;

		P1 = e1;
		P2 = e2;
		P3 = e3;

		e1 = t1;
		e2 = t2;
		e3 = t3;

		if (e2 == 0) {
			i = 0;
		}
	}
	a = P1;
	gcduv = P2;
	b = P3;
	return a, gcduv, b;
}

int main(void) {
	int sumk = 0;
	int end, e, m, Z, M, Euc, c, cal, mul;
	int count = 0;
	int n = 8;

	cout << "Step1\t�@Z����͂��Ă��������B" << endl;
	cin >> Z;
	cout << "����m����͂��Ă��������B" << endl;
	cin >> m;

	cout << endl;

	cout << "Step2\t�閧���x�N�g���̐���" << endl;
	cout << endl;

	int* bi = new int[7];
	int* ai = new int[7];

	int sumbi = 0;
	int bri = 0;
	int bir = 0;
	int Csum = 0;
	int* C = new int[7];
	int* sumC = new int[7];
	int* ir = new int[7];
	int* biri = new int[7];
	int* sumai = new int[7];

	int sum = 0;

	ir[0] = 0;
	ir[1] = 0;
	ir[2] = 0;
	ir[3] = 0;
	ir[4] = 0;
	ir[5] = 0;
	ir[6] = 0;
	ir[7] = 0;
	bool s = false;
	bool cc = false;

	//���J���x�N�g���̎����̓���

	int *a = new int[n];
	InitRand();
	for (int i = 0; i < n; i++) {
		int ran;
		ran = Dice();
		a[i] = ran;
		cout << flush;
	}
	cout << "�������ꂽ����s" << endl;
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			cout << a[i] << ',';
		}
		else {
			cout << a[i];
		}
	}
	cout << endl;

	sumk = 0;
	for (int i = 0; i < n; i++) {
		sumk += a[i];
	}

	cout << endl;

	cout << "sum(s) =" << sumk << endl;
	cout << endl;

	cout << "Step3\t�f��P�𐶐�" << endl;
	cout << endl;

	bool sosuu = false;

	P > sumk&&sumk > P / 2;

	for (; !sosuu;) {
		InitRand();
		x = Dice2();
		cout << x << endl;
		if (isPrimeNum(x)) {
			cout << "A prime nuber" << endl;
			sosuu = true;
		}
		else {
			cout << "Not a prime number" << endl;
			Sleep(1000);
		}
	}

	P = x;
	e = Dice3();
	cout << "P=" << P << endl;
	cout << "step4 e�𐶐�" << endl;
	cout << "e=" << e << endl;
	cout << endl;

	cout << "step5 ���J��a�𐶐�" << endl;
	cout << endl;
	cout << "ai=";
	for (int j = 0; j < n; j++) {
		mul = (e*a[j]) % P;
		cout << mul << ",";
		ai[j] = mul;
	}
	cout << endl;
	cout << endl;

	cout << "step6 ���J���x�N�g��b�𐶐�" << endl;
	cout << endl;

	cout << "bi=";
	for (int j = 0; j < n; j++) {
		cal = a[j] % Z;
		cout << cal << ",";
		bi[j] = cal;
	}
	for (int i = 0; i < 8; i++) {
		sumbi = sumbi + bi[i];
	}
	for (int i = 0; bri < sumbi; i++) {
		biri[i] = m + Z * i;
		bri = biri[i];
		bir++;
	}
	for (end = 0; !s; end++) {
		if (ir[7] == 0) {
			ir[7] = 1;
			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum == biri[i]) {
					C[count] = sum;
					cout << "ir[0]" << "ir[1]" << "ir[2]" << "ir[3]" << "ir[4]" << "ir[5]" << "ir[6]" << "ir[7]" << "�̘a��" << biri[i
					] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count] = Csum;
					count++;
				}
			}
			sum = 0;
		}
		if (ir[7] == 1 && ir[6] == 0) {
			ir[7] = 0;
			ir[6] = 1;

			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum == biri[i]) {
					C[count] = sum;
					cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7] << "�̘a��" << biri[i] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count] = Csum;
					count++;
				}
			}
			sum = 0;
		}
		if (ir[7] == 1 && ir[6] == 1 && ir[5] == 0) {
			ir[7] == 0;
			ir[6] == 0;
			ir[5] == 1;

			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum == biri[i]) {
					C[count] = sum;
					cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7] << "�̘a��" << biri[i] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count = Csum];
					count++;
				}
			}
			sum = 0;
		}
		if (ir[7] == 1 && ir[6] == 1 && ir[5] == 1 && ir[4] == 0) {
			ir[7] = 0;
			ir[6] = 0;
			ir[5] = 0;
			ir[4] = 1;

			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum == biri[i]) {
					C[count] = sum;
					cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7] << "�̘a��" << biri[i] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count] = Csum;
					count++;
				}
			}
			sum = 0;
		}
		if (ir[7] == 1 && ir[6] == 1 && ir[5] == 1 && ir[4] == 1 && ir[3] == 0) {
			ir[7] = 0;
			ir[6] = 0;
			ir[5] = 0;
			ir[4] = 0;
			ir[3] = 1;

			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum == biri[i]) {
					C[count] = sum;
					cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7] << "�̘a��" << biri[i] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count] = Csum;
					count++;
				}
			}
			sum = 0;
		}
		if (ir[7] == 1 && ir[6] == 1 && ir[5] == 1 && ir[4] == 1 && ir[3] == 1 && ir[2] == 0) {
			ir[7] = 0;
			ir[6] = 0;
			ir[5] = 0;
			ir[4] = 0;
			ir[3] = 0;
			ir[2] = 1;

			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}

			for (int i = 0; i < bir; i++) {
				if (sum == biri[i]) {
					C[count] = sum;
					cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7] << "�̘a��" << biri[i] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count] = Csum;
					count++;
				}
			}
			sum = 0;
		}
		if (ir[7] == 1 && ir[6] == 1 && ir[5] == 1 && ir[4] == 1 && ir[3] == 1 && ir[2] == 1 && ir[1] == 0) {
			ir[7] = 0;
			ir[6] = 0;
			ir[5] = 0;
			ir[4] = 0;
			ir[3] = 0;
			ir[2] = 0;
			ir[1] = 1;
			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum = -biri[i]) {
					C[count] = sum;
					cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7] << "�̘a��" << biri[i] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count] = Csum;
					count++;
				}
			}
			sum = 0;
		}

		//395�s��

		if (ir[7] == 1 && ir[6] == 1 && ir[5] == 1 && ir[4] == 1 && ir[3] == 1 && ir[2] == 1 && ir[1] == 1 && ir[0] == 0) {
			ir[7] = 0;
			ir[6] = 0;
			ir[5] = 0;
			ir[4] = 0;
			ir[3] = 0;
			ir[2] = 0;
			ir[1] = 0;
			ir[0] = 1;
			for (int i = 0; i < 8; i++) {
				sumai[i] = ir[i] * bi[i];
				sum = sum + sumai[i];
			}
			for (int i = 0; i < bir; i++) {
				if (sum = -biri[i]) {
					C[count] = sum;
					cout << ir[0] << ir[1] << ir[2] << ir[3] << ir[4] << ir[5] << ir[6] << ir[7] << "�̘a��" << biri[i] << "�ƂȂ莮�𖞂����܂�" << endl;
					Csum = 0;
					for (int i = 0; i < 8; i++) {
						C[i] = ai[i] * ir[i];
						Csum = Csum + C[i];
					}
					sumC[count] = Csum;
					count++;
				}
			}
			sum = 0;
		}

		//425
		if (ir[0] == 1, ir[1] == 1, ir[2] == 1, ir[3] == 1, ir[4] == 1, ir[5] == 1, ir[6] == 1, ir[7] == 1) {
			s = true;
		}
	}
	cout << "�����ɍ���ri�̐�������" << count << endl;

	cout << endl;
	//�g�����[�N���b�h
	yukurid(&P, &e);
	Euc = b;
	//���ԕ���
	for (int i = 0; i < count; i++) {
		M = Euc * sumC[i] % P;
		//step2�@����ma�̌v�Z
		int ma;
		ma = M % Z;

		if (ma == m) {
			cout << "�Í���C=" << sumC[i] << "�͕����\" << endl;
		}
		else {
			cout << "�Í���C=" << sumC[i] << "��\t�����s��" << endl;
		}
	}
	cin.get();
	cin.get();
	return 0;
}
