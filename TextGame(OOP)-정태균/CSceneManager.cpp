#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"

//------------------------------
// Scene�ʱ�ȭ -> TitleScene
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
	// true�Ͻ� �ش� �޸𸮸� ���� ��
	if (this->_bCheckScene)
	{
		delete _pScene;
	}

	// ���� �� �����Ҵ� �� false��ȯ
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

	// �ش� �� ����
	this->_pScene->Update();
}

void CSceneManager::LoadScene(SceneList nowScene)
{
	this->_NowScene = nowScene;
	this->_bCheckScene = true;
}