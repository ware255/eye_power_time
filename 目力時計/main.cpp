#include <iostream>
#include <ctime>
#include <Windows.h>
#pragma comment(lib,"winmm")

class senpai {
private:
	int num;
	int zi;
	int hun;
public:
	senpai() : num{}, zi{}, hun{} {
		::SetConsoleTitle(TEXT("�ڗ͎��v"));
	};

	void setting();
};

void sokutei(int hou, int mini) {
	for (;;) {
		time_t t = time(nullptr);
		struct tm local;
		errno_t err = localtime_s(&local, &t);

		if (err != 0)
		{
			std::cout << "�G���[����" << std::endl;
			std::cin.get();
			exit(-1);
		}

		if (hou == local.tm_hour && mini == local.tm_min) {
			break;
		}
		//Sleep(100);
	}
	PlaySound("�ڗ͐�yBB.wav", NULL, SND_FILENAME | SND_SYNC | SND_LOOP);
}

void senpai::setting() {
	std::cout << "�N���������Ԃ�ݒ肵�Ă��������B" << std::endl;
	std::cout << "���͗�:XX XX >> ";
	std::cin >> zi >> hun;

	sokutei(zi, hun);
}

int main() {
	senpai TIME_;
	TIME_.setting();

	return 0;
}