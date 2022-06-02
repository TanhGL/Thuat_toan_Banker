#include<iostream>
using namespace std;
int allocation[10][3], need[10][3], Max[10][3], available[10][3];
int p, current[3];
bool executed[10], come;
void KT() {
	come = false;
	for (int i = 0; i < 10; ++i)
	{
		executed[i] = false;
	}
}
void tinhtoan() {
	KT();
	int i, j, dem = 0;
	for (i = 0; i < p; ++i)
	{
		for (j = 0; j < p; ++j)
		{
			while (executed[j] && j < p - 1) {
				j++;
			}
			if (need[j][0] <= current[0] && need[j][1] <= current[1] && need[j][2] <= current[2]) {
				if (!executed[j]) {
					executed[j] = true;
					current[0] += allocation[j][0]; current[1] += allocation[j][1]; current[2] += allocation[j][2];
					cout << "\nTien trinh P" << j + 1;
					cout << "\nAvailable: " << current[0] << " " << current[1] << " " << current[2];
					dem = dem + 1;
					come = true;
				}
			}
		}
		if (dem == p) {
			cout << "\n      HE THONG AN TOAN\n";
			break;
		}
		if (!come) {
			cout << "\n		 CO DEADLOCK\n\n";
			break;
		}
		else {
			come = false;
		}
	}
}

int main() {
	cout << "So tien trinh: ";
	cin >> p;
	cout << "\n";
	cout << "Available: ";
	cin >> current[0] >> current[1] >> current[2];
	for (int i = 0; i < p; ++i) {
		cout << "\n\n			Tien trinh P" << i + 1 << "\n";
		cout << "Allocation : ";
		cin >> allocation[i][0] >> allocation[i][1] >> allocation[i][2];
		cout << "Max :";
		cin >> Max[i][0] >> Max[i][1] >> Max[i][2];
		need[i][0] = Max[i][0] - allocation[i][0]; need[i][1] = Max[i][1] - allocation[i][1]; need[i][2] = Max[i][2] - allocation[i][2];
	}
	cout << "\n\n			Bang tinh Need\n\n";
	cout << "Tien trinh        Need\n";
	for (int i = 0; i < p; ++i)
	{
		cout << "  P" << i + 1 << "            ";
		cout << " " << need[i][0] << " " << need[i][1] << " " << need[i][2];
		cout << "\n";
	}
	cout << "\n\n";
	tinhtoan();
	system("pause");
	return 0;
}


