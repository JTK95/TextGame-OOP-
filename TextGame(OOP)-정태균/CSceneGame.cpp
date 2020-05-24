#include "stdafx.h"

#include "CScreenBuffer.h"
#include "CKeyProcess.h"
#include "CBaseObject.h"
#include "CList.h"
#include "CObjectManager.h"
#include "CSceneBase.h"
#include "CSceneGame.h"

CSceneGame::CSceneGame()
{}

CSceneGame::~CSceneGame()
{}

void CSceneGame::Update()
{
	// 키보드 입력
	CKeyProcess::GetInstance()->InputKey();
	
	// 로직부
	CObjectManager::GetInstance()->Update();

	// 출력부
	CObjectManager::GetInstance()->Render();
	CScreenBuffer::GetInstance()->Flip();
}
