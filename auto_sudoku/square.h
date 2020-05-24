#pragma once
#include <vector>

class square
{
public:
	square();
	bool check(std::vector<std::vector<int>>&baseSquare, int Height, int Width, int Num);
	bool isSolved(std::vector<std::vector<int>>&baseSquare);
	bool solve(std::vector<std::vector<int>>&baseSquare, int H, int W);
	void tryToSolve();
private:
	std::vector<std::vector<int>> baseSquare;
	
};

