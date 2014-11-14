#include "Result.hpp"


CResult::CResult(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager):
CScene(app_env, scene_manager),
m_font(std::make_unique<Font>(60))
{
}

//�@�ŏ��̏���
void CResult::Start(){
}

//�@�X�V
void CResult::Update(){
	Control();
}

//�@�`��
void CResult::Draw(){
	m_font->DrawCenter(L"���U���g���", 0, 0, Color(1, 1, 1));
}

//�@����
void CResult::Control(){
	if (!m_is_control)return;
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_scene_manager.lock()->TransformOfScene(CSceneManager::Scene::TITLE);
	}
}