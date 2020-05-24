#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneManager.h"
#include "CScreenBuffer.h"
#include "CSceneBase.h"
#include "CSceneTitle.h"

CSceneTitle::CSceneTitle()
{
	this->_bDraw = true;
}

CSceneTitle::~CSceneTitle()
{}

void CSceneTitle::Update()
{
	static DWORD titleTime = GetTickCount();

	// Press Any Key
	if (_kbhit())
	{
		CSceneManager::GetInstance()->LoadScene(SceneList::SCENELOADING);
	}

	// 1ÃÊ ¸¶´Ù ·Î°í¸¦ ±ôºýÀÌÀÚ
	if (GetTickCount() - titleTime > 1000)
	{
		this->_bDraw = !(this->_bDraw);
		titleTime = GetTickCount();
	}

	if(this->_bDraw)
	{
		CScreenBuffer::GetInstance()->DrawScene(SCREEN_HEIGHT / 2, TITLETEXT);
		this->_bDraw = !(this->_bDraw);
	}
}

