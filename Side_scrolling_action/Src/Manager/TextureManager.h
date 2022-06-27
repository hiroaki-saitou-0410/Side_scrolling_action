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

	//@brief テクスチャー読み込み
	//@param name_ テクスチャーの名前
	//@param file_path Rasファイルからのファイルパス
	void LoadTexture(const std::string& name_,const std::string& file_path);

	//@brief 分割テクスチャー読み込み
	//@param name_ : テクスチャーの名前
	//@param file_path : Rasファイルからのファイルパス
	//@param MaxTex : 分割する数
	//@param Xnum : 横の分割数
	//@param Ynum : 縦の分割数
	//@param TexSizeX : 分割されたテクスチャーの横のサイズ
	//@param TexSizeY : 分割されたテクスチャーの縦のサイズ
	//@note 同じものを複数回使用しない
	void LoadDivTexture(std::string name_, std::string file_path,int MaxTex,int Xnum,int Ynum,int TexSizeX,int TexSizeY);

	//@brief テクスチャー全削除
	void ReleaseTexture();

	//@brief テクスチャー取得
	//@param name_ テクスチャーの名前
	//@return テクスチャーハンドル
	//@note 未登録の場合例外が帰ってくる
	int GetTexture(std::string name_);

	//@brief 分割テクスチャー取得
	//@param name_ テクスチャーの名前
	// @aram index 
	//@return テクスチャーハンドル
	//@note 未登録の場合例外が帰ってくる
	int GetDivTexture(std::string name_,int index);

private:
	static const int Max{ 32 };
	//int DivTexData_[MaxDivTex][Max];
	std::map<std::string,int >DivTexData;
	std::map<std::string, int>TextureData;
};

#endif // !TEXTURE_MANAGER_H

