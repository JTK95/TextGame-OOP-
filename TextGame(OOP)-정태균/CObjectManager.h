#pragma once

//--------------------------------
// ObjectManager (Singleton)
//--------------------------------
class CObjectManager
{
public:
	static CObjectManager* GetInstance();

public:
	void CreateObject(ObjectType ot, int iXpos, int iYpos);
	void DestroyObject(CBaseObject* destroyObject);

	void CollisionCheck();

public:
	void Update();
	void Render();

public: 
	CList<CBaseObject*> objList;
	CList<CBaseObject*>::CIterator iter;

private:
	CObjectManager();
	~CObjectManager();
};

