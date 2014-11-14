#pragma once
#include "../SceneManager.hpp"
#include "../../resource/Resource.hpp"
#include <chrono>
#include <vector>

class Object;

//========================================
//�X�e�[�W�N���X
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	void Start();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();
private:

	enum class Digit{
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE
	};

	const int ReadyCenterPosX;								//�@���f�B�[�̐^�񒆂̃|�W�V����
	bool isRemove;											//�@�폜���邩�ǂ���
	bool isReady;											//�@��������
	bool isFinish;											//�@�I��������
	int m_count;											//�@�t���[���J�E���g
	int m_stage_num;										//�@���݂̃X�e�[�W��
	int m_ready_count;										//�@���f�B�[�̃J�E���g
	Vec2f m_ready_pos;										//�@���f�B�[�̃|�W�V����
	Vec2f m_finish_pos;										//�@�t�B�j�b�V���̃|�W�V����
	std::array<int, 3>m_time_digit;							//�@���Ԃ̌�
	std::vector<std::shared_ptr<Object>>m_obj_list;			//�@�I�u�W�F�N�g���X�g
	std::array<std::unique_ptr<Font>, 3>m_time_graph;		//�@���Ԃ̕\��
	CResource &m_res;										//�@���\�[�X
	std::chrono::seconds m_time;							//�@����
	std::array<int,5>m_score_digit;							//�@�X�R�A�̌�
	std::array<std::unique_ptr<Font>, 5>m_score_num_graph;	//�@�X�R�A�̐����\��
	std::unique_ptr<Font>m_score_graph;						//�@�X�R�A�̕\��
	std::unique_ptr<Font>m_stage_graph;						//�@�X�e�[�W�̕����\��
	std::unique_ptr<Font>m_stage_num_graph;					//�@�X�e�[�W�̕����\��
	std::unique_ptr<Font>m_combo_graph;						//�@�R���{�̕����\��
	std::unique_ptr<Font>m_combo_num_graph;					//�@�R���{���̕\��
	std::unique_ptr<Font>m_ready_graph;						//�@���f�B�[�̕\��
	std::unique_ptr<Font>m_finish_graph;					//�@�t�B�j�b�V���̕\��

	//�@����
	void Control();

	//�@�������Ԃ̏���
	void TimeUpdate();

	//�@���Ԃ��������鏈��
	void AddCount();

	//�@���Ԃ̕`��
	void TimeDraw();

	//�@���̏���
	void TimeDigitUpdate();

	//�@���Ԃ̍X�V
	void ToLoseTime();

	//�@�X�R�A�̐����`��
	void ScoreNumDraw();

	//�@�X�R�A�̍X�V
	void ScoreUpdate();

	//�@�X�R�A�̕����`��
	void ScoreStringDraw();

	//�@�X�e�[�W�̕����`��
	void StageStringDraw();

	//�@�X�e�[�W���̍X�V
	void StageNumUpdate();

	//�@�R���{�̕����`��
	void ComboStringDraw();

	//�@�J�ڏ���
	void Transition();

	//�@�����̏���
	void Ready();

	//�@������̏���
	void UpdateOfAfterReady();

	//�@�����̕`��
	void ReadyStringDraw();

	//�@���f�B�̈ړ�����
	void MoveReadyStirng();

	//�@�����̏���
	void Finish();

	//�@�����̕`��
	void FinishStringDraw();

	//�@���f�B�̈ړ�����
	void MoveFinishStirng();

	//�@�I�u�W�F�N�g�̍폜
	void RemoveObject();
};

