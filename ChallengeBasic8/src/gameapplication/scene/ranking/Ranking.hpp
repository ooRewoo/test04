#pragma once
#include "../SceneManager.hpp"
#include <memory>

class CRanking : public CScene{
public:
	CRanking(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	//�@�ŏ��̏���
	void Start();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();
private:
	std::unique_ptr<Font>m_font;

	//�@����
	void Control();

};

