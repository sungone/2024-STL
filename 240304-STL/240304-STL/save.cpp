// save.cpp �� �б� ���Ǹ� �����Ѵ�
// 2024.3.7
/////////////////////////////////////////

#include "save.h"
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

void save(std::string_view fileName)
{
	// ���� ������ ����.
	std::ifstream in{ fileName.data() };
	if (!in)
	{
		std::cout << "������ ���� ���Ͽ���." << std::endl;
		exit(0);
	}

	// �� ������ �����̱� ���� ����
	std::ofstream out("2024 1 ��56��78 ��������.txt", std::ios::app);

	// ������ �ð��� ���Ͽ� ����Ѵ�
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now); // UTC �ð����� ��ȯ
	auto lt = localtime(&time); // ���� �ð����� ��ȯ // localtime �� c ���� ���� ���ڴٸ� �Լ�

	/*cout << now << endl;*/

	auto old = out.imbue(std::locale("ko_KR"));
	out << std::endl << std::endl;
	out << "====================================================" << std::endl;
	out << fileName << std::put_time(lt, ", ����ð�: %x %A %X ") << std::endl;
	out << "====================================================" << std::endl;
	out.imbue(old);
	out << std::endl;

	// ���� ������ ��� ������ �о� �� ���Ͽ� �����δ�
	//cout << sizeof(string_view) << endl;

	std::vector<char> v{ std::istreambuf_iterator<char>{in} , {} };

	for (char c : v)
		std::cout << c;

	copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{out});
}