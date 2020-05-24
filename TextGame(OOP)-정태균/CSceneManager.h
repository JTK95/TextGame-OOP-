#pragma once

// 포인터만 사용하고 인스턴스화 할거를 아니면 상호참조가 생길수있으니 전방선언으로 끝내라.
//class CSceneBase;

enum class SceneList
{
	SCENETITLE = 1,
	SCENELOADING,
	SCENEGAME,
	SCENEOVER
};

//----------------------------
// SceneManager (Singleton)
//----------------------------
class CSceneManager
{
public:
	static CSceneManager* GetInstance();

public:
	void Update();

	// 씬 전환 함수 
	void LoadScene(SceneList nowScene);
	
private:
	// 초기화(TitleScene)
	CSceneManager();
	~CSceneManager();

private:
	// 씬 동적할당 및 해제를 위한 포인터
	CSceneBase* _pScene;
	 
	// 현재 씬
	SceneList _NowScene;

	// 씬 전환 체크 변수
	bool _bCheckScene;
};

