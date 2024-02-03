#pragma once
class TITLE {
public:
	void Out() {
		Cal();
		Draw();
	}

private:
	void Cal();
	void Draw();
};
TITLE Tit;

void TITLE::Cal() {
	if (Key[KEY_INPUT_NUMPADENTER] == 1) {
		Sce = MEN::MEN_01_Action;
	}
}

void TITLE::Draw() {
	DrawGraph(0, 0, Pic.Tit, TRUE);
	DrawFormatStringToHandle(150, 300,
		Col.Bla, Fon.c[20], "Press Enter Key.");

}