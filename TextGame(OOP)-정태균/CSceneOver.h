#pragma once

#define ENDTEXT "                                                GAME OVER..."

class CSceneOver : public CSceneBase
{
public:
	CSceneOver();
	virtual ~CSceneOver();

	virtual void Update();

private:
	bool _bDraw;

};

