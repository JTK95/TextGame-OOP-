#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"

//------------------------------
// Scene초기화 -> TitleScene
//------------------------------
CSceneManager::CSceneManager()
{
	this->_NowScene = SceneList::SCENETITLE;
	this->_pScene = new CSceneTitle;
	this->_bCheckScene = false;
}

CSceneManager::~CSceneManager()
{}

CSceneManager* CSceneManager::GetInstance()
{
	static CSceneManager sceneManager;

	return &sceneManager;
}

void CSceneManager::Update()
{
	// true일시 해당 메모리를 해제 후
	if (this->_bCheckScene)
	{
		delete _pScene;
	}

	// 현재 씬 동적할당 및 false변환
	switch (this->_NowScene)
	{
	case SceneList::SCENELOADING:
		this->_pScene = new CSceneLoading;
		this->_bCheckScene = false;
		break;
	case SceneList::SCENEGAME:
		this->_pScene = new CSceneGame;
		this->_bCheckScene = false;
		break;
	case SceneList::SCENEOVER:
		this->_pScene = new CSceneOver;
		this->_bCheckScene = false;
		break;
	}

	// 해당 씬 진행
	this->_pScene->Update();
}

void CSceneManager::LoadScene(SceneList nowScene)
{
	this->_NowScene = nowScene;
	this->_bCheckScene = true;
}