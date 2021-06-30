//AssetManager.h/cpp

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <array>
#include <fstream>

/*
template <typename T>
struct AssetRef
{
	std::
};

struct Asset
{
	virtual load();
	virtual unload();
};

class AssetManager
{
public:
	AssetManager()
	{
		std::weak_ptr<Asset> a;
	}
	
	template <typename T>
	Asset<T> getAsset(short id);

private:
};


// USER SIDE

struct TextureAsset : public Asset
{
	virtual load()
	{

	}
	virtual unload()
	{
		
	}
};


int main()
{



	return 0;
}*/

// On initialization specify the types/type ids
/*

	asset_manager({})

*/

//Then for runtime usage; something like this:
/*

	auto asset = asset_manager.find_asset<TYPE>("KEY");

*/

struct Asset
{
	
};

struct AssetRef
{
	std::shared_ptr<Asset> asset;
};


struct AssetType
{
	template <typename T>
	AssetType(std::string filetype)	:	extension(filetype)
	{

	}

	std::string extension;
};

class AssetManager
{
public:
	AssetManager(std::vector<)

private:

}

int main()
{

}
