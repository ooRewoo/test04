#include "Rule.hpp"


CRule::CRule(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager):
CScene(app_env, scene_manager),
m_font(std::make_unique<Font>(90))
{
}

//�@�ŏ��̏���
void CRule::Start(){
}

//�@�X�V
void CRule::Update(){
	Control();
}

//�@�`��
void CRule::Draw(){
	m_font->DrawCenter(L"���[�����", 0, 200, Color(1, 1, 1));
}

//�@����
void CRule::Control(){
	if (!m_is_control)return;
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_scene_manager.lock()->TransformOfScene(CSceneManager::Scene::TITLE);
	}
}