#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include"../CELLGAME/GameMap.h"
#include"../CELLGAME/GameRule.h"
#include"../CELLGAME/GameMap.cpp"
#include"../CELLGAME/GameRule.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace CELLGAMETEST
{
	TEST_CLASS(CEllGAMEMAP)
	{
	public:

		TEST_METHOD(setMap)
		{
			bool** aMap = new bool* [HEIGHT];
			for (int i = 0; i < HEIGHT * WIDE; i++) {
				for (int j = 0; j < HEIGHT; j++) {
					aMap[j] = new bool[WIDE];
					for (int k = 0; k < WIDE; k++) {
						aMap[j][k] = i % 2;
					}
				}
			}

			GameMap* gameMap = new GameMap();
			gameMap->setMap(aMap, 50);

			for (int i = 1; i < HEIGHT - 1; i++) {
				for (int j = 1; j < WIDE - 1; j++) {
					Assert::AreEqual(aMap[i][j], gameMap->getElement(i, j));
				}
			}

		}

		
	};
	TEST_CLASS(CEllGAMERULE) {
		TEST_METHOD(judgeElementTest01) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{0,0,0},
				{0,1,0},
				{1,0,0}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(false, gameRule.judgeElement(1, 1, theMap));
		}
		TEST_METHOD(judgeElementTest02) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{0,0,1},
				{0,1,0},
				{1,0,1}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(true, gameRule.judgeElement(1, 1, theMap));
		}
		TEST_METHOD(judgeElementTest03) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{1,1,1},
				{1,1,1},
				{1,1,1}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(false, gameRule.judgeElement(1, 1, theMap));
		}
		TEST_METHOD(judgeElementTest04) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{1,1,1},
				{1,0,1},
				{1,1,1}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(false, gameRule.judgeElement(1, 1, theMap));
		}
		TEST_METHOD(judgeElementTest05) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{1,0,0},
				{1,0,0},
				{1,1,0}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(false, gameRule.judgeElement(1, 1, theMap));
		}
		TEST_METHOD(judgeElementTest06) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{1,0,0},
				{1,0,0},
				{0,1,0}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(true, gameRule.judgeElement(1, 1, theMap));
		}
		TEST_METHOD(judgeElementTest07) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{0,0,0},
				{1,0,0},
				{0,1,0}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(false, gameRule.judgeElement(1, 1, theMap));
		}
		TEST_METHOD(judgeElementTest08) {

			GameMap gameMap;
			GameRule gameRule(&gameMap);

			bool aMap[3][3] = {
				{0,0,0},
				{1,1,0},
				{0,1,0}
			};

			bool** theMap = new bool* [3];
			for (int i = 0; i < 3; i++) {
				theMap[i] = new bool[3];
				for (int j = 0; j < 3; j++) {
					theMap[i][j] = aMap[i][j];
				}
			}

			Assert::AreEqual(true, gameRule.judgeElement(1, 1, theMap));
		}
	};
}