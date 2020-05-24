#pragma once

class CPlayerBullet : public CBaseObject
{
public:
	CPlayerBullet(int iXpos, int iYpos);
	virtual ~CPlayerBullet();

	virtual bool Update();
	virtual void Render();

	void MovePlayerBullet();
	void DeletePlayerBullet();

public:
	virtual int GetXpos();
	virtual int GetYpos();
};

