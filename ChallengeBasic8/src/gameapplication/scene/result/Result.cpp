#include "Result.hpp"


CResult::CResult(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager):
CScene(app_env, scene_manager),
m_font(std::make_unique<Font>(60))
{
}

//　最初の処理
void CResult::Start(){
}

//　更新
void CResult::Update(){
	Control();
}

//　描画
void CResult::Draw(){
	m_font->DrawCenter(L"リザルト画面", 0, 0, Color(1, 1, 1));
}

//　操作
void CResult::Control(){
	if (!m_is_control)return;
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_scene_manager.lock()->TransformOfScene(CSceneManager::Scene::TITLE);
	}
}