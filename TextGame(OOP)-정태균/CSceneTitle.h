#pragma once

#define TITLETEXT "                                            Press Any Key..."

class CSceneTitle : public CSceneBase
{
public:
	CSceneTitle();
	virtual ~CSceneTitle();

	virtual void Update();

private:
	bool _bDraw;
};

