/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	mWalls(0.0f, gfx.ScreenWidth, 0.0f, gfx.ScreenHeight),
	player(Vec2(450.0f, 500.0f), 50.0f, 15.0f),
	mBall(Vec2(100.0f, 100.0f), Vec2(300.0f,300.0f))
{
	//Position of top left corner of brick grid
	const Vec2 topLeft(40.0f, 20.0f);

	//Variable for each brick
	int i = 0;

	for (int y = 0; y < mNumOfRow; y++)
	{
		for (int x = 0; x < mNumOfColumn; x++)
		{
			mBricks[i] = Brick(RectF(
				topLeft + Vec2(x * Brick::mWidth + 3, y * Brick::mHeight),
				Brick::mWidth, Brick::mHeight), brickColors[y]);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float delta = ft.Mark();

	player.Update(wnd.kbd, delta);
	player.WallCollision(mWalls);

	mBall.Update(delta);
	mBall.WallCollision(mWalls);

	for (Brick& b : mBricks)
	{
		b.BallCollision(mBall);
	}

	player.BallCollision(mBall);
}

void Game::ComposeFrame()
{
	player.Draw(gfx);
	mBall.Draw(gfx);

	for (const Brick& b : mBricks)
	{
		b.Draw(gfx);
	}
}
