#include "Rule.hpp"


CRule::CRule(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager):
CScene(app_env, scene_manager),
m_font(std::make_unique<Font>(90))
{
}

//　最初の処理
void CRule::Start(){
}

//　更新
void CRule::Update(){
	Control();
}

//　描画
void CRule::Draw(){
	m_font->DrawCenter(L"ルール画面", 0, 200, Color(1, 1, 1));
}

//　操作
void CRule::Control(){
	if (!m_is_control)return;
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_scene_manager.lock()->TransformOfScene(CSceneManager::Scene::TITLE);
	}
}