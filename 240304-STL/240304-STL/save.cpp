#include "save.h"

void save(string_view fileName)
{
	// ���� ������ ����.
	ifstream in{ fileName.data() };
	if (!in)
	{
		cout << "������ ���� ���Ͽ���." << endl;
		exit(0);
	}

	// �� ������ �����̱� ���� ����
	ofstream out("2024 1 ��56��78 ��������.txt", ios::app);

	// ������ �ð��� ���Ͽ� ����Ѵ�
	auto now = chrono::system_clock::now();
	auto time = chrono::system_clock::to_time_t(now); // UTC �ð����� ��ȯ
	auto lt = localtime(&time); // ���� �ð����� ��ȯ // localtime �� c ���� ���� ���ڴٸ� �Լ�

	/*cout << now << endl;*/

	auto old = out.imbue(locale("ko_KR"));
	out << endl << endl;
	out << "===============================================" << endl;
	out << fileName << put_time(lt, ", ����ð�: %x %A %X ") << endl;
	out << "===============================================" << endl;
	out.imbue(old);

	// ���� ������ ��� ������ �о� �� ���Ͽ� �����δ�
	//cout << sizeof(string_view) << endl;

	vector<char> v{ istreambuf_iterator<char>{in} , {} };

	for (char c : v)
		cout << c;

	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});
}