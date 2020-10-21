#include <iostream>
#include <string>

using namespace std;
int N;

void recursion(int k) {
	if (k == N) {
		for (int i = 0; i < k; i++) cout << "____";
		cout << "\"����Լ��� ������?\"\n";
		for (int i = 0; i < k; i++) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < k; i++) cout << "____";
		cout << "��� �亯�Ͽ���.\n";
		return;
	}

	for (int i = 0; i < k; i++) cout << "____";
	cout << "\"����Լ��� ������?\"\n";
	for (int i = 0; i < k; i++) cout << "____";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = 0; i < k; i++) cout << "____";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = 0; i < k; i++) cout << "____";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	recursion(k + 1);
	for (int i = 0; i < k; i++) cout << "____";
	cout << "��� �亯�Ͽ���.\n";
	return;
}

int main(void) {
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recursion(0);
	return 0;
}