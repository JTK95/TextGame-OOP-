#pragma once

#define ENEMY_COUNT 8

//----------------------------
// Object Type
//----------------------------
enum class ObjectType 
{
	PLAYER_TYPE = 1,
	ENEMY_TYPE,
	PLAYER_BULLET_TYPE,
	ENEMY_BULLET_TYPE
};

class CBaseObject
{
public:
	CBaseObject(int iObjectType, int iXpos, int iYpos);
	virtual ~CBaseObject();

	virtual bool Update() = 0;
	virtual void Render() = 0;

public:
	int GetObjectType();

	virtual int GetXpos() = 0;
	virtual int GetYpos() = 0;

protected:
	int _iXpos;
	int _iYpos;

	int _iObjectType;
};

