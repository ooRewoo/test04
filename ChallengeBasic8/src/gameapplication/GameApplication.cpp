#include "GameApplication.hpp"
#include <ctime>

CGameApplication::CGameApplication() :
m_app_env(std::make_shared<AppEnv>(CScene::WIDTH, CScene::HEIGHT, false, true)),
m_scene_manager(std::make_shared<CSceneManager>(m_app_env)),
m_res(CResource::GetInstance())
{
	m_scene_manager->AddSceneList();
}

void CGameApplication::Update(){
	m_scene_manager->Update();
	m_scene_manager->Draw();
}