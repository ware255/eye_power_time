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
		::SetConsoleTitle(TEXT("目力時計"));
	};
	~senpai() {};

	void setting();
};

void sokutei(int hou, int mini) {
	for (;;) {
		time_t t = time(nullptr);
		struct tm local;
		errno_t err = localtime_s(&local, &t);

		if (err != 0)
		{
			std::cout << "エラー発生" << std::endl;
			std::cin.get();
			exit(1);
		}

		if (hou == local.tm_hour && mini == local.tm_min)break;

		//Sleep(100);
	}
	PlaySound("目力先輩BB.wav", nullptr, SND_FILENAME | SND_SYNC | SND_LOOP);
}

void senpai::setting()
{
	void(*F_sokutei)(int, int) = &sokutei;
	std::cout << "起きたい時間を設定してください。" << std::endl;
	std::cout << "入力例:XX XX >> ";
	std::cin >> zi >> hun;

	(*F_sokutei)(zi, hun);
}

int main()
{
	senpai TIME_;
	TIME_.setting();

	return 0;
}
