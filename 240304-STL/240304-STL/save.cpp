#include "save.h"

void save(string_view fileName)
{
	// 읽을 파일을 연다.
	ifstream in{ fileName.data() };
	if (!in)
	{
		cout << "파일을 열지 못하였다." << endl;
		exit(0);
	}

	// 쓸 파일을 덧붙이기 모드로 연다
	ofstream out("2024 1 월56목78 강의저장.txt", ios::app);

	// 저장한 시간을 파일에 기록한다
	auto now = chrono::system_clock::now();
	auto time = chrono::system_clock::to_time_t(now); // UTC 시간으로 변환
	auto lt = localtime(&time); // 현재 시간으로 변환 // localtime 은 c 에서 만든 구닥다리 함수

	/*cout << now << endl;*/

	auto old = out.imbue(locale("ko_KR"));
	out << endl << endl;
	out << "===============================================" << endl;
	out << fileName << put_time(lt, ", 저장시간: %x %A %X ") << endl;
	out << "===============================================" << endl;
	out.imbue(old);

	// 읽을 파일의 모든 내용을 읽어 쓸 파일에 덧붙인다
	//cout << sizeof(string_view) << endl;

	vector<char> v{ istreambuf_iterator<char>{in} , {} };

	for (char c : v)
		cout << c;

	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});
}