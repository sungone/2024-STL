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
// project -> �Ӽ� -> std::c++latest , SDL - no

// ���â 80 X 25

// 2024.03.04
// source file save ���

// const std::string& == string_view (�޸��� �����ּҿ� ������ �˷���)
void save(string_view fileName);
