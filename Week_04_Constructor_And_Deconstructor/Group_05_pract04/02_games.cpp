#include <iostream>
#include <fstream>

#pragma warning(disable : 4996)

namespace ConstantsSize
{
	constexpr size_t MAX_SIZE_TITLE = 128;
	constexpr size_t MAX_SIZE_GAMES = 10;
}

class Game
{
private:
	char title[ConstantsSize::MAX_SIZE_TITLE];
	double price;
	bool isAvailable;
	
public:
	Game(): price(0), isAvailable(0)
	{
		this->title[0] = '\0';
	}

	Game(const char* title, double price, bool isAvailable)
	{
		std::strcpy(this->title, title);
		this->price = price;
		this->isAvailable = isAvailable;
	}

	const char* getTitle()
	{
		return this->title;
	}

	double getPrice()
	{
		return this->price;
	}

	bool getIsAvailable()
	{
		return this->isAvailable;
	}

	void setTitle(const char* title)
	{
		std::strcpy(this->title, title);
	}

	void setPrice(double price)
	{
		this->price = price;
	}

	void setIsAvailable(bool isAvailable)
	{
		this->isAvailable = isAvailable;
	}
	
	bool isFree()
	{
		return this->price == 0.00;
	}

	void print()
	{
		std::cout << "[Game Title] " << this->title << std::endl;
		std::cout << "[Game Price] " << this->price << std::endl;
		std::cout << "[Is Game Available] " << this->isAvailable << std::endl;

	}
};

class GamePlatform
{
private: 
	Game games[ConstantsSize::MAX_SIZE_GAMES];
	size_t currGamesSize;
	
public:

	GamePlatform() : currGamesSize(0) {};

	size_t getCurrGamesSize()
	{
		return this->currGamesSize;
	}

	void addGame(const Game& game)
	{
		if (this->currGamesSize >= ConstantsSize::MAX_SIZE_GAMES)
		{
			std::cout << "[ERROR] No more space in game library.";
			return;
		}

		this->games[currGamesSize] = game;
		this->currGamesSize++;
	}
	
	Game getGameByTitle(const char* gameTitle)
	{
		for (int i = 0; i < this->currGamesSize; i++)
		{
			if (std::strcmp(this->games[i].getTitle(), gameTitle) == 0)
			{
				return this->games[i];
			}
		}

		return Game{};
	}

	Game getMostExpensiveGane()
	{
		int maxPrice = this->games[0].getPrice();
		int gameIdx = 0;
		for (int i = 0; i < this->currGamesSize; i++)
		{
			if (maxPrice < this->games[i].getPrice())
			{
				maxPrice = this->games[i].getPrice();
				gameIdx = i;
			}
		}
		
		return this->games[gameIdx];
	}

	Game getCheapestGame()
	{
		int minPrice = this->games[0].getPrice();
		int gameIdx = 0;
		for (int i = 0; i < this->currGamesSize; i++)
		{
			if (minPrice > this->games[i].getPrice())
			{
				minPrice = this->games[i].getPrice();
				gameIdx = i;
			}
		}

		return this->games[gameIdx];
	}

	void removeGame(const char* gameTitle)
	{
		for (int i = 0; i < this->currGamesSize; i++)
		{
			if (std::strcmp(this->games[i].getTitle(), gameTitle) == 0)
			{
				for (int j = i; j < this->currGamesSize - 1; j++)
				{
					this->games[j] = this->games[j + 1];
					this->currGamesSize--;
				}
			}
		}

		std::cout << "[ERROR] Game not found.";
		return;
	}

	void printAvailableGames()
	{
		for (int i = 0; i < this->currGamesSize; i++)
		{
			if (this->games[i].getIsAvailable())
			{
				this->games[i].print();
			}
		}
	}

	void printAllGames()
	{
		for (int i = 0; i < this->currGamesSize; i++)
		{
			std::cout << "here ";
			this->games[i].print();
		}
	}

	void saveToFileBinary(const char* fileName)
	{
		std::ofstream ofs(fileName, std::ios::binary);

		ofs.write((const char*)&this->games, sizeof(games));
		ofs.write((const char*)&this->currGamesSize, sizeof(currGamesSize));
		ofs.close();

	}

	void readFromFileBinary(const char* fileName)
	{
		std::ifstream ifs(fileName, std::ios::binary);

		ifs.read((char*)&this->games, sizeof(games));
		ifs.read((char*)&this->currGamesSize, sizeof(currGamesSize));
		ifs.close();

	}

	void sortGamesByPrice()
	{
		std::cout << this->currGamesSize << std::endl;
		int* prices = new int[this->currGamesSize];
		for (int i = 0; i < this->currGamesSize; i++)
		{
			prices[i] = this->games[i].getPrice();
		}
	
		int minIdx = 0;
		for (int i = 0; i < this->currGamesSize - 1; i++)
		{
			minIdx = i;
			for (int j = i + 1; j < this->currGamesSize; j++)
			{
				if (prices[minIdx] < prices[j])
				{
					minIdx = j;
				}
			}

			if (minIdx != i)
			{
				std::swap(this->games[i], this->games[minIdx]);
			}
		}

		delete[] prices;
	}
};

int main()
{
	/*const char* getTitle()
	double getPrice()
	bool getIsAvailable()
	void setTitle(const char* title)
	void setPrice(double price)
	void setIsAvailable(bool isAvailable)
	bool isFree()
	void print()*/
	Game game;
	game.setTitle("title");
	game.setPrice(10.21);
	game.setIsAvailable(1);

	Game gameTwo;
	gameTwo.setTitle("titleTwo");
	gameTwo.setPrice(132.21);
	gameTwo.setIsAvailable(0);
	
	std::cout << game.getTitle() << std::endl;
	std::cout << game.getPrice() << std::endl;
	std::cout << game.getIsAvailable() << std::endl;
	std::cout << game.isFree() << std::endl;
	game.print();
	std::cout << "---------------------------------" << std::endl;

	//size_t getCurrGamesSize()
	//void addGame(const Game & game)
	//Game getGameByTitle(const char* gameTitle)
	//Game getMostExpensiveGane()
	//Game getCheapestGame()
	//void removeGame(const char* gameTitle);
    //void printAvailableGames()
	//void printAllGames()
	//void saveToFileBinary(const char* fileName)
	//void readFromFileBinary(const char* fileName)
	//void sortGamesByPrice()
	
	GamePlatform gamePlatform;
	gamePlatform.addGame(game);
	gamePlatform.addGame(gameTwo);
	std::cout << "---------------------------------" << std::endl;
	gamePlatform.getGameByTitle("title").print();
	gamePlatform.getCheapestGame().print();
	gamePlatform.getMostExpensiveGane().print();
	std::cout << gamePlatform.getCurrGamesSize() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	gamePlatform.printAvailableGames();
	std::cout << gamePlatform.getCurrGamesSize() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	gamePlatform.printAllGames();
	std::cout << gamePlatform.getCurrGamesSize() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << gamePlatform.getCurrGamesSize() << std::endl;
	gamePlatform.saveToFileBinary("02_games.txt");
	gamePlatform.readFromFileBinary("02_games.txt");
	std::cout << gamePlatform.getCurrGamesSize() << std::endl;
	std::cout << "---------------------------------" << std::endl;
	gamePlatform.sortGamesByPrice();
	gamePlatform.printAllGames();

	return 0;
}