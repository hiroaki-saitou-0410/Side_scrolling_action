#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include"DxLib.h"
#include"../Singleton.h"

enum 
{
	MyMachine1,
	MyMachine2,
	MyMachine3,
	Enemys,
	Effect1,
	Effect2,
	Effect3,
	Explosion,

	MaxDivTex
};

class TextureManager:public Singleton<TextureManager>
{
public:
	TextureManager() = default;
	virtual ~TextureManager() = default;

	//@brief �e�N�X�`���[�ǂݍ���
	//@param name_ �e�N�X�`���[�̖��O
	//@param file_path Ras�t�@�C������̃t�@�C���p�X
	void LoadTexture(const std::string& name_,const std::string& file_path);

	//@brief �����e�N�X�`���[�ǂݍ���
	//@param name_ : �e�N�X�`���[�̖��O
	//@param file_path : Ras�t�@�C������̃t�@�C���p�X
	//@param MaxTex : �������鐔
	//@param Xnum : ���̕�����
	//@param Ynum : �c�̕�����
	//@param TexSizeX : �������ꂽ�e�N�X�`���[�̉��̃T�C�Y
	//@param TexSizeY : �������ꂽ�e�N�X�`���[�̏c�̃T�C�Y
	//@note �������̂𕡐���g�p���Ȃ�
	void LoadDivTexture(std::string name_, std::string file_path,int MaxTex,int Xnum,int Ynum,int TexSizeX,int TexSizeY);

	//@brief �e�N�X�`���[�S�폜
	void ReleaseTexture();

	//@brief �e�N�X�`���[�擾
	//@param name_ �e�N�X�`���[�̖��O
	//@return �e�N�X�`���[�n���h��
	//@note ���o�^�̏ꍇ��O���A���Ă���
	int GetTexture(std::string name_);

	//@brief �����e�N�X�`���[�擾
	//@param name_ �e�N�X�`���[�̖��O
	// @aram index 
	//@return �e�N�X�`���[�n���h��
	//@note ���o�^�̏ꍇ��O���A���Ă���
	int GetDivTexture(std::string name_,int index);

private:
	static const int Max{ 32 };
	//int DivTexData_[MaxDivTex][Max];
	std::map<std::string,int >DivTexData;
	std::map<std::string, int>TextureData;
};

#endif // !TEXTURE_MANAGER_H

