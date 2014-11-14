#pragma once
#include "../Character.hpp"
#include "../../../utility/Font.hpp"
#include <chrono>

class CHolyGhost : public CCharacter
{
public:
	CHolyGhost(std::shared_ptr<AppEnv>app_env, std::chrono::seconds& time);

	//�@�ŏ��̏���
	void Start(std::vector<std::shared_ptr<Object>>obj_list);

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	//�@�X���C�v���ꂽ�����擾
	bool GetisSwipe(){ return m_isswipe; }

private:
	const int ADD_SCORE;
	const int DIFF_SCORE;
	const std::chrono::seconds ADD_TIME;
	const std::chrono::seconds DIFF_TIME;
	bool m_istap;
	bool m_isswipe;
	bool isRemove;
	std::chrono::seconds& m_time;
	std::unique_ptr<Font>m_score_graph;
	Vec2f m_score_pos;

	//�@�����������̏���
	void isHit(Vec2f& pos);

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

	//�@�_�l�̂̕`��
	void HolyGhostDraw();
};

