#pragma once

class CPlayerObject : public CBaseObject
{

public:
	CPlayerObject(int iXpos, int iYpos);
	virtual ~CPlayerObject();

	virtual bool Update();
	virtual void Render();

public:
	void MovePlayer();
	void DeletePlayer();

	virtual int GetXpos();
	virtual int GetYpos();
	
};