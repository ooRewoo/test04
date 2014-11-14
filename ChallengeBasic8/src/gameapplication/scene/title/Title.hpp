#pragma once
#include "../SceneManager.hpp"
#include "../../resource/Resource.hpp"
#include <memory>
#include <vector>
#include <array>
#include <unordered_map>
#include <functional>

//========================================
//�^�C�g���N���X
//========================================
class CTitle : public CScene{
public:
	CTitle(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	//�@�ŏ��̏���
	void Start();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:

	//�@�����f�[�^
	struct StringData{
		StringData(Vec2f &pos, float size, std::unique_ptr<Font> font) :
			pos_(pos),
			size_(size),
			font_(std::move(font)){};
		Vec2f pos_;
		float size_;
		std::unique_ptr<Font> font_;
	};


	//�@�J�ڂł���V�[��
	enum class Scene{
		STAGE,
		RULE,
		RANKING,
		NUM
	};

	int const STR_SELECT_HEIGHT;											//�@�I�����ڂ̕�����Y���W
	std::array<std::unique_ptr<StringData>, 3>m_title_select_str;			//�@�I�����ڂ̕����̃f�[�^
	std::unique_ptr<Font>m_title_str;										//�@�^�C�g�������̃f�[�^
	Scene m_now_select;														//�@���ݑI��ł���I������
	std::unordered_map<Scene, CSceneManager::Scene>m_transition_list;		//�@�J�ڂł���V�[�����X�g
	CResource &m_res;														//�@���\�[�X
	std::map<Scene, std::function<void()>>m_select_effect_list;					//�@�I�����ڂɂ��G�t�F�N�g���X�g


	//===============================================================================================================================================
	
	
	//�@����
	void Control();

	//�@�����̏�����
	void StringInit();

	//�@��]�̃G�t�F�N�g
	void RotationEffect();

	//�@�J�ڃ��X�g�̒ǉ�
	void AddTransitionList();

	//�@�I��ł鍀�ڂɂ��G�t�F�N�g���X�g�̒ǉ�
	void AddSelectEffectList();

	//�@�I��ł鍀�ڂɂ���ăt�H���g��ύX
	void FontDrawOfSelectStage();
	void FontDrawOfSelectRule();
	void FontDrawOfSelectRanking();
};

