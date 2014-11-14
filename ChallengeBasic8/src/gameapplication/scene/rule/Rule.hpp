#pragma once
#include "../SceneManager.hpp"
#include <memory>
class CRule : public CScene{
public:
	CRule(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	//　最初の処理
	void Start();

	//　更新
	void Update();

	//　描画
	void Draw();
private:
	std::unique_ptr<Font>m_font;

	//　操作
	void Control();
};

