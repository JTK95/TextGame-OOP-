#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

#include "CScreenBuffer.h"

//-----------------------------
// Ŀ�� or ���� ����
//-----------------------------
CScreenBuffer::CScreenBuffer()
{
	CONSOLE_CURSOR_INFO conSoleCursor;

	// Ŀ�� ������ �� ���翩��
	conSoleCursor.dwSize = 1;
	conSoleCursor.bVisible = FALSE;

	// ǥ���ܼ� ��� �ڵ� ��ȯ
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
// ���� ����
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
// ���콺 Ŀ�� ��ġ ����
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