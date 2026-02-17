#pragma once

class TitleScene
{
public:
	TitleScene();
	~TitleScene();

public:
	void LoadTitleScene();
	void StartTitleScene();
	void StepTitleScene();
	void UpdateTitleScene();
	void DrawTitleScene();

private:
	int m_logoHandle;
	int m_select;
};
