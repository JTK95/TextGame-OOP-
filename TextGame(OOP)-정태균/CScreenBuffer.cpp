#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

#include "CScreenBuffer.h"

//-----------------------------
// 커서 or 버퍼 셋팅
//-----------------------------
CScreenBuffer::CScreenBuffer()
{
	CONSOLE_CURSOR_INFO conSoleCursor;

	// 커서 사이즈 및 존재여부
	conSoleCursor.dwSize = 1;
	conSoleCursor.bVisible = FALSE;

	// 표준콘솔 출력 핸들 반환
	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(this->hConsole, &conSoleCursor);
}

CScreenBuffer::~CScreenBuffer()
{}

CScreenBuffer* CScreenBuffer::GetInstance()
{
	static CScreenBuffer screenBuffer;

	return &screenBuffer;
}

//-----------------------------
// 버퍼 셋팅
//-----------------------------
void CScreenBuffer::ClearBuffer()
{
	memset(this->szBuffer, ' ', sizeof(this->szBuffer));
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		this->szBuffer[i][SCREEN_WIDTH - 1] = '\0';
	}
}

//-----------------------------
// 마우스 커서 위치 셋팅
//-----------------------------
void CScreenBuffer::cs_MovePosition(int xpos, int ypos)
{
	COORD coord;
	coord.X = xpos;
	coord.Y = ypos;

	SetConsoleCursorPosition(this->hConsole, coord);
}

//-----------------------------
// Draw Scene
//-----------------------------
void CScreenBuffer::DrawScene(int iHeight, const char* text)
{
	strcpy(this->szBuffer[iHeight], text);
}

//----------------------------
// Draw Sprite
//----------------------------
void CScreenBuffer::DrawSprite(int xpos, int ypos, const char sprite)
{
	this->szBuffer[ypos][xpos] = sprite;
}

//----------------------------
// Flip
//----------------------------
void CScreenBuffer::Flip()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		cs_MovePosition(0, i);
		printf("%s", this->szBuffer[i]);
	}
}