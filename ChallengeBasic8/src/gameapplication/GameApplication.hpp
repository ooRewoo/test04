#pragma once
#include "resource\Resource.hpp"
#include "scene\SceneManager.hpp"
#include "Uncopyable.hpp"
#include <memory>

//========================================
//ゲームアプリケーションクラス
//========================================

class CGameApplication : private Uncopyable{
public:

	static CGameApplication& GetInstance(){
		static CGameApplication instance;
		return instance;
	}

	std::shared_ptr<AppEnv>m_app_env;

	//　更新
	void Update();
private:
	CGameApplication();
	std::shared_ptr<CSceneManager>m_scene_manager;
	//　リソースの読み込み
	CResource& m_res;
};

