#define WIN_MAX_X 1500
#define WIN_MAX_Y 1500
#define WIN_POS_X 0
#define WIN_POS_Y 0

#define POKEMON_CELL 50

enum MEN {
    MEN_00_Title,
    MEN_01_Action,
    MEN_02_Battle_start,
    MEN_03_Battle,
};
int Sce = MEN::MEN_00_Title;
#include "DxLib.h"
#include "Setting.h"
#include "Picture.h"
#include "Poke.h"
#include "Tec.h"
#include "Title.h"
#include "Move.h"
#include "Battle_start.h"
#include "Battle.h"
int WINAPI WinMain(

    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR IpCmdLine,
    _In_ int nShoCmd) {
    ChangeWindowMode(TRUE);
    DxLib_Init();

    //Window Init
    SetWindowInitPosition(WIN_POS_X, WIN_POS_Y);
    SetWindowText("POKEMON Mul Battle");
    SetGraphMode(WIN_MAX_X, WIN_MAX_Y, 32);
    SetBackgroundColor(255, 255, 255);
    SetDrawScreen(DX_SCREEN_BACK);

    Col.Read();
    Fon.Read();
    Sound.Read();
    Pic.Read();
    while (ScreenFlip() == 0 &&
        ClearDrawScreen() == 0 &&
        ProcessMessage() == 0 &&
        GetKey() == 0 &&
        Key[KEY_INPUT_ESCAPE] == 0)
    {
        switch (Sce)
        {
        case MEN::MEN_00_Title:
            Tit.Out();
            break;
        case MEN::MEN_01_Action:
            Mov.Out();
            break;
        case MEN::MEN_02_Battle_start:
            Battle_sta.Out();
            break;
        case MEN::MEN_03_Battle:
            Bat.Out();
            break;
        }
    }
    DxLib_End(); // DXÉâÉCÉuÉâÉäèIóπèàóù
    return 0;
}