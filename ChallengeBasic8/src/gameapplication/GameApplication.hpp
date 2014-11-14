#pragma once
#include "resource\Resource.hpp"
#include "scene\SceneManager.hpp"
#include "Uncopyable.hpp"
#include <memory>

//========================================
//�Q�[���A�v���P�[�V�����N���X
//========================================

class CGameApplication : private Uncopyable{
public:

	static CGameApplication& GetInstance(){
		static CGameApplication instance;
		return instance;
	}

	std::shared_ptr<AppEnv>m_app_env;

	//�@�X�V
	void Update();
private:
	CGameApplication();
	std::shared_ptr<CSceneManager>m_scene_manager;
	//�@���\�[�X�̓ǂݍ���
	CResource& m_res;
};

