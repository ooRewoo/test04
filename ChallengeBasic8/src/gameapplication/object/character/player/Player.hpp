#pragma once
#include "../Character.hpp"

class CPlayer : public CCharacter
{
public:
	CPlayer(std::shared_ptr<AppEnv>app_env,bool& is_contorol);

	//�@�ŏ��̏���
	void Start(std::vector<std::shared_ptr<Object>>obj_list);

	//�@�I�u�W�F���g�̍X�V
	void UpdateOfObject(std::vector<std::shared_ptr<Object>>obj_list);

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	//�@�X�R�A���擾
	int GetScore(){ return m_score; }

	//�@�X�R�A�̕ύX
	void TransformOfScore(int score){ m_score = score; }

	//�@�R���{�����擾
	int GetCombo(){ return m_combo_num; }

private:
	bool& m_is_control;													//�@����ł��邩
	int m_score;														//�@�X�R�A
	int m_combo_num;													//�@�R���{


	//�@�R���{�̍X�V
	void ComboUpdate();

	//�@���̃R���{�X�V
	void UpdateComboOfSweetpotato();

	//�@�_�l�̃R���{�X�V
	void UpdateComboOfHolyghost();

	//�@����
	void Control();
};

