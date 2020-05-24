#pragma once

//-----------------------------
// 콘솔 화면 크기
//-----------------------------
#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 30

//-----------------------------
// 화면 백버퍼 (Singleton)
//-----------------------------
class CScreenBuffer
{
public:
	static CScreenBuffer* GetInstance();

public:
	void ClearBuffer();
	void cs_MovePosition(int xpos, int ypos);

	void DrawScene(int iHeight, const char* text);
	void DrawSprite(int xpos, int ypos, const char sprite);
	void Flip();

public:
	char szBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

private:
	CScreenBuffer();
	~CScreenBuffer();

	HANDLE hConsole;
};

