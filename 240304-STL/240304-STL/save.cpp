// save.cpp 한 학기 강의를 저장한다
// 2024.3.7
/////////////////////////////////////////

#include "save.h"
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

void save(std::string_view fileName)
{
	// 읽을 파일을 연다.
	std::ifstream in{ fileName.data() };
	if (!in)
	{
		std::cout << "파일을 열지 못하였다." << std::endl;
		exit(0);
	}

	// 쓸 파일을 덧붙이기 모드로 연다
	std::ofstream out("2024 1 월56목78 강의저장.txt", std::ios::app);

	// 저장한 시간을 파일에 기록한다
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now); // UTC 시간으로 변환
	auto lt = localtime(&time); // 현재 시간으로 변환 // localtime 은 c 에서 만든 구닥다리 함수

	/*cout << now << endl;*/

	auto old = out.imbue(std::locale("ko_KR"));
	out << std::endl << std::endl;
	out << "====================================================" << std::endl;
	out << fileName << std::put_time(lt, ", 저장시간: %x %A %X ") << std::endl;
	out << "====================================================" << std::endl;
	out.imbue(old);
	out << std::endl;

	// 읽을 파일의 모든 내용을 읽어 쓸 파일에 덧붙인다
	//cout << sizeof(string_view) << endl;

	std::vector<char> v{ std::istreambuf_iterator<char>{in} , {} };

	for (char c : v)
		std::cout << c;

	copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{out});
}