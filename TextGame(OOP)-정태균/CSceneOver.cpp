#include "stdafx.h"

#include "CScreenBuffer.h"
#include "CSceneBase.h"
#include "CSceneOver.h"

CSceneOver::CSceneOver()
{
	this->_bDraw = true;
}

CSceneOver::~CSceneOver()
{}

void CSceneOver::Update()
{
	static DWORD endTime = GetTickCount();

	// 1초가 지나면 로고를 깜빡이자
	if (GetTickCount() - endTime > 1000)
	{
		this->_bDraw = !(this->_bDraw);
		endTime = GetTickCount();
	}

	if(this->_bDraw)
	{
		CScreenBuffer::GetInstance()->DrawScene(SCREEN_HEIGHT / 2, ENDTEXT);
		(this->_bDraw) = !(this->_bDraw);
	}

}

