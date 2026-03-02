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

	static const int TITLE_PATTERN_MAX = 6;

	int m_select;
	int m_randomIndex;
	int m_backHandle[TITLE_PATTERN_MAX];
	int m_logoHandle[TITLE_PATTERN_MAX];
};