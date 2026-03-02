#include "Inventory.h"

int main()
{
    // 인벤토리 객체 생성
    Inventory inventory;

    // CSV 파일로부터 데이터 로드
    inventory.LoadFromCSV("Data/Cards.csv");

    // 루프 실행
    inventory.Run();

    return 0;
}