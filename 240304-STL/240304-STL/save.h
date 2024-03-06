#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
//using namespace std;

// version 17.9 or more 
// release , x64
// project -> 속성 -> std::c++latest , SDL - no

// 출력창 80 X 25

// 2024.03.04
// source file save 기능

// const std::string& == string_view (메모리의 시작주소와 개수만 알려줌)
void save(string_view fileName);
