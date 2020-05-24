#pragma once

// �����͸� ����ϰ� �ν��Ͻ�ȭ �ҰŸ� �ƴϸ� ��ȣ������ ����������� ���漱������ ������.
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

	// �� ��ȯ �Լ� 
	void LoadScene(SceneList nowScene);
	
private:
	// �ʱ�ȭ(TitleScene)
	CSceneManager();
	~CSceneManager();

private:
	// �� �����Ҵ� �� ������ ���� ������
	CSceneBase* _pScene;
	 
	// ���� ��
	SceneList _NowScene;

	// �� ��ȯ üũ ����
	bool _bCheckScene;
};

