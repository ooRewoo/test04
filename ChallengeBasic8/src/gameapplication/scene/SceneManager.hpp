#pragma once
#include "../Uncopyable.hpp"
#include "../utility/Font.hpp"
#include "../../lib/appEnv.hpp"
#include <memory>
#include <unordered_map>

class CSceneManager;

//========================================
//�V�[���N���X(���N���X)
//========================================

class CScene : private Uncopyable{
public:
	CScene(const std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager) :
		m_app_env(app_env),
		m_scene_manager(scene_manager){}

	virtual ~CScene() = default;

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//�@�R���g���[���̃t���O�ϊ�
	void TransformOfisControl(bool is_control){ m_is_control = is_control; }

	//�@��ʂ̃T�C�Y
	static const int WIDTH = 1320;
	static const int HEIGHT = 720;

protected:
	std::shared_ptr<AppEnv>m_app_env;
	std::weak_ptr<CSceneManager>m_scene_manager;
	bool m_is_control = false;

};

//========================================
//�V�[���}�l�[�W���[�N���X
//========================================

class CSceneManager :private Uncopyable, public std::enable_shared_from_this<CSceneManager>{

public:
	CSceneManager(const std::shared_ptr<AppEnv>app_env);
	//�@�V�[���̎��
	enum class Scene{
		TITLE,
		STAGE,
		RULE,
		RANKING,
		RESULT
	};

	void AddSceneList();								//�@�V�[�����X�g
	void Update();										//�@�X�V
	void Draw();										//�@�`��
	void TransformOfScene(const Scene next_scene);		//�@�J�ڂ������V�[����n���֐�
	bool GetisFade();									//�@�t�F�[�h���Ă��邩�ǂ������擾

private:

	//�@��Ԃ̎��
	enum class State{
		INIT,
		UPDATE
	};

	std::shared_ptr<CScene> m_scene;		//�@�V�[�������锠
	Scene m_now_scene;						//�@���݂̃V�[��
	Scene m_old_scene;						//�@�J�ڂ���O�̃V�[��
	State m_state;							//�@���݂̏��

	std::shared_ptr<AppEnv>m_app_env;
	std::unordered_map<Scene, std::shared_ptr<CScene>>m_scene_list;
	
	bool m_isFade;

	int m_alpha;
	// �J�ڏ���
	void Transition();

	//�@�V�[���̍X�V
	void SceneUpdate();

	//�@�t�F�[�h�C��
	void FadeIn();

	//�@�t�F�[�h�A�E�g
	void FadeOut();
};