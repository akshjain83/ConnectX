/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, checkInvalidWH)
{
	ConnectX game(4,3,4);
	ASSERT_EQ(-1, game.at(-2,-2));
}


TEST(ConnectXTest, checkValidWInvalidH)
{
	ConnectX game(4,3,4);
	ASSERT_EQ(-1, game.at(2,-2));
}

//Bug 1 here! Invalid width but still doesn't returns invalid(-1)
TEST(ConnectXTest, checkValidHInvalidW)
{
	ConnectX game(4,3,4);
	ASSERT_EQ(-1, game.at(-2,2));
}


TEST(ConnectXTest, checkValidWInvalidH2)
{
	ConnectX game(4,3,4);
	ASSERT_EQ(-1, game.at(1,5));
}

//Bug 1 here! Invalid width but still doesn't returns invalid(-1)
TEST(ConnectXTest, checkInvalidWValidH2)
{
	ConnectX game(4,3,4);
	ASSERT_EQ(-1, game.at(5,1));
}

TEST(ConnectXTest, checkInvalidWH2)
{
	ConnectX game(4,3,4);
	ASSERT_EQ(-1, game.at(5,5));
}

TEST(ConnectXTest, createInvalidW)
{
	ConnectX game(-4,3,4);
	ASSERT_EQ(2, game.whoseTurn());
}

TEST(ConnectXTest, createInvalidH)
{
	ConnectX game(4,-3,4);
	ASSERT_EQ(2, game.whoseTurn());
}

TEST(ConnectXTest, createInvalidX)
{
	ConnectX game(4,3,-4);
	ASSERT_EQ(2, game.whoseTurn());
}


TEST(ConnectXTest, createInvalidX0)
{
	ConnectX game(4,3,0);
	ASSERT_EQ(2, game.whoseTurn());
}


TEST(ConnectXTest, createInvalidH0)
{
	ConnectX game(4,0,4);
	ASSERT_EQ(2, game.whoseTurn());
}

TEST(ConnectXTest, createInvalidW0)
{
    ConnectX game(0,3,4);
	ASSERT_EQ(2, game.whoseTurn());
}

TEST(ConnectXTest, checkToggle)
{
	ConnectX game(4,3,4);
	game.placePiece(5);
    ASSERT_EQ(1, game.whoseTurn());	
    game.placePiece(1);
    ASSERT_EQ(2, game.whoseTurn());
}


TEST(ConnectXTest, checkShowBoard)
{
	ConnectX game(4,3,4);
	game.placePiece(2);
    game.placePiece(1);
    game.showBoard();
    ASSERT_EQ(2, game.whoseTurn());
}


TEST(ConnectXTest, checkPlacePieceLoops)
{
	ConnectX game(1,1,1);
	game.placePiece(1);
	ASSERT_EQ(1, game.whoseTurn());	
}

TEST(ConnectXTest, checkPlacePieceLoops2)
{
	ConnectX game(2,2,2);
	game.placePiece(1);
	ASSERT_EQ(1, game.whoseTurn());	
}

//Bug Here(Maybe), It doesn't fail as there is no way to check
//this case but it is not valid logically.;
TEST(ConnectXTest, checkInvalidXLarge)
{
	ConnectX game(2,2,16);
	game.placePiece(1);
	ASSERT_EQ(1, game.whoseTurn());	
}
