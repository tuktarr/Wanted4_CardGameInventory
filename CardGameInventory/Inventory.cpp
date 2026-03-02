#include "Inventory.h"
#include <iostream>
#include <cstdio>
#include <Windows.h>

Inventory::Inventory()
    : currentIndex(0)
{
}

void Inventory::LoadFromCSV(const char* fileName)
{
	FILE* file = nullptr;
	if (fopen_s(&file, fileName, "r") != 0)
	{
		return;
	}

	char buffer[1024];

    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file) != nullptr)
    {
        char* context = nullptr;

        // ID 읽기
        char* token = strtok_s(buffer, ",", &context);
        if (token == nullptr)
        {
            continue;
        }
        int id = atoi(token);

        // Name 읽기
        char* name = strtok_s(nullptr, ",", &context);
        if (name == nullptr)
        {
            name = (char*)"Unknown";
        }

        // Type 읽기
        char* type = strtok_s(nullptr, ",", &context);
        if (type == nullptr)
        {
            type = (char*)"None";
        }

        // Cost 읽기
        token = strtok_s(nullptr, ",", &context);
        int cost = (token) ? atoi(token) : 0;

        // Rarity 읽기
        token = strtok_s(nullptr, ",", &context);
        int rarity = (token) ? atoi(token) : 0;

        // 카드 객체 생성 및 데이터 설정
        Cards newCard;
        newCard.SetData(id, name, type, cost, rarity);

        info.Push_back(newCard);
    }

    fclose(file);
}

void Inventory::Run()
{
    // 실행하자마자 커서를 숨깁니다. 
    // main에서 일일이 호출할 필요가 없어집니다.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo = { 100, FALSE };
    SetConsoleCursorInfo(hConsole, &cursorInfo);

	if (info.GetSize() == 0)
	{
		std::cout << "데이터가 비어있습니다. " << "\n";
		return;
	}
    system("cls");

    bool bQuit = false;
    while (!bQuit)
    {
        Gotoxy(0, 0);
        std::cout << "========= [ 카드 정보 선택 ] ========= \n";
        std::cout << " (Q): 이전 카드 | (E): 다음 카드 | (X): 종료 \n";
        std::cout << " 현재 위치: " << currentIndex + 1 << " / " << info.GetSize() << "\033[K\n";
        std::cout << "--------------------------------------" << "\n";

        info[currentIndex].ShowInfo();

        std::cout << "--------------------------------------\033[K\n";

        if (GetAsyncKeyState('Q') & 0x8000)
        {
            // 맨 앞에서 맨 뒤로
            if (currentIndex == 0)
            {
                currentIndex = info.GetSize() - 1;
            }
            else
            {
                currentIndex--;            
            }

            Sleep(200);
        }
        else if (GetAsyncKeyState('E') & 0x8000)
        {
            // 맨 뒤에서 맨 앞으로
            if (currentIndex == info.GetSize() - 1)
            {
                currentIndex = 0;
            }
            else
            {
                currentIndex++;
            }

            Sleep(200);
        }
        else if (GetAsyncKeyState('X') & 0x8000)
        {
            bQuit = true;
        }

        Sleep(10);
    }

}

void Inventory::Gotoxy(int x, int y)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

