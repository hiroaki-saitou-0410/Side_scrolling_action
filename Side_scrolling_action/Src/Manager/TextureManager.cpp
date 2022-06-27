#include"TextureManager.h"

void TextureManager::LoadTexture(const std::string& name_, const std::string& file_path)
{
	auto handle{ LoadGraph(file_path.c_str())};
	if (handle == -1)return;
	TextureData.emplace(name_, handle);
}

void TextureManager::LoadDivTexture(std::string name_, std::string file_path, int MaxTex, int Xnum, int Ynum, int TexSizeX, int TexSizeY)
{
	int tmp[Max]{ 0 };
	LoadDivGraph(file_path.c_str(), MaxTex, Xnum, Ynum, TexSizeX, TexSizeY, tmp);
	//LoadDivGraph(file_path.c_str(), MaxTex, Xnum, Ynum, TexSizeX, TexSizeY, DivTexData_[MyMachine]);

	std::string namber = "0";
	std::string a;
	for (int i = 0; i < MaxTex; i++)
	{
		//•¶ŽšŒ‹‡
		a = namber.c_str() + i;
		DivTexData.emplace(name_+= namber, tmp[i]);
	}	
}

void TextureManager::ReleaseTexture()
{
	TextureData.clear();
	//for (int i = 0; i < MaxDivTex; i++)
	//{
	//	for (int j = 0; j < Max; j++)
	//	{
	//		DeleteGraph(DivTexData[i][j]);
	//	}
	//}
	DivTexData.clear();
	InitGraph();	
}

int TextureManager::GetTexture(std::string name_)
{
	return TextureData.at(name_);
}

int TextureManager::GetDivTexture(std::string name_, int index)
{
	std::string namber = "0";
	for (int i = 0; i <= index; i++)
	{
		//•¶ŽšŒ‹‡
		namber.c_str() + i;
		name_ += namber;
	}
	return DivTexData.at(name_);
}
