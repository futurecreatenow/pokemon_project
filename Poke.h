#pragma once
struct POKEMON {
	int No = -1;
	char Name[100];
	char Type1[10];
	char Type2[10];
	int H = 0; //HP
	int A = 0; //�U��
	int B = 0; //�h��
	int C = 0; //����U��
	int D = 0; //����h��
	int S = 0; //�f����
	int Hp_original = 0; //���Ƃ��Ƃ�HP
	int Tec[4] = { -1,-1,-1,-1 };
};


struct POK
{
	int poke_hyota[3] = {-1,-1,-1}; //�q���E�^�̃|�P����No
	int poke_my = 0; //���̃|�P����No
	int poke_now = 0; //���퓬���̃|�P����No
	int Act = 0;
	int Tec = 0; //�ǂ̋Z���o���̂�
	int Dam = 0;
};

POK Pla;
POK Ene;

POKEMON Pokemon[]{
	//�q���E�^
	{0,"�Y�K�C�h�X","��","",
		67,125,40,30,30,58,67,
		0,1,2,3},
	//��l���A����
	{1,"���E�J�U��","��","�i��",
		1000,78,52,78,52,81,1000,
		6,7,8,12},
	//�q���E�^ 2�C��
	{2,"�C���[�N","��","�n��",
		100,100,100,100,100,100,100,
		9,10,11,0},
	//�q���E�^ 3�C��
	{3,"�C�V�c�u�e","��","�n��",
		50,50,50,50,50,50,50,
		9,10,11,0},

};