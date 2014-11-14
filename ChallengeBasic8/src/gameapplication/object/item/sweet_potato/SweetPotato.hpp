#pragma once
#include "../Implant.hpp"
#include "../../../utility/Font.hpp"
class CSweetPotato : public CImplant{
public:
	CSweetPotato(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Object> object);

	//�@�ŏ��̏���
	void Start();
	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:
	const int ADD_TAP_SCORE;
	const int ADD_SWIPE_SCORE;
	std::unique_ptr<Font>m_score_graph;
	Vec2f m_score_pos;
	//�@�^�b�v�����Ƃ��̏���
	void UpdateOfTap();

	//�@�X���C�v�����Ƃ��̏���
	void UpdateOfSwaipe();

	//�@�^�b�v�����Ƃ��̃X�R�A�\��
	void DrawOfTapScore();

	//�@�X�R�A�X�V
	void UpdateOfScore();

	//�@���̕`��
	void DrawSWeetPotato();

	//�@�폜
	void Remove();

	//�@�X���C�v�����Ƃ��̃X�R�A�\��
	void DrawOfSwipeScore();

	//�@�X�R�A�̕\��
	void DrawOfScore();

};

