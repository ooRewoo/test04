#pragma once
#include "../Uncopyable.hpp"
#include "../utility/Font.hpp"
#include "../../lib/appEnv.hpp"
#include <memory>
#include <unordered_map>

class CSceneManager;

//========================================
//シーンクラス(基底クラス)
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

	//　コントロールのフラグ変換
	void TransformOfisControl(bool is_control){ m_is_control = is_control; }

	//　画面のサイズ
	static const int WIDTH = 1320;
	static const int HEIGHT = 720;

protected:
	std::shared_ptr<AppEnv>m_app_env;
	std::weak_ptr<CSceneManager>m_scene_manager;
	bool m_is_control = false;

};

//========================================
//シーンマネージャークラス
//========================================

class CSceneManager :private Uncopyable, public std::enable_shared_from_this<CSceneManager>{

public:
	CSceneManager(const std::shared_ptr<AppEnv>app_env);
	//　シーンの種類
	enum class Scene{
		TITLE,
		STAGE,
		RULE,
		RANKING,
		RESULT
	};

	void AddSceneList();								//　シーンリスト
	void Update();										//　更新
	void Draw();										//　描画
	void TransformOfScene(const Scene next_scene);		//　遷移したいシーンを渡す関数
	bool GetisFade();									//　フェードしているかどうかを取得

private:

	//　状態の種類
	enum class State{
		INIT,
		UPDATE
	};

	std::shared_ptr<CScene> m_scene;		//　シーンを入れる箱
	Scene m_now_scene;						//　現在のシーン
	Scene m_old_scene;						//　遷移する前のシーン
	State m_state;							//　現在の状態

	std::shared_ptr<AppEnv>m_app_env;
	std::unordered_map<Scene, std::shared_ptr<CScene>>m_scene_list;
	
	bool m_isFade;

	int m_alpha;
	// 遷移処理
	void Transition();

	//　シーンの更新
	void SceneUpdate();

	//　フェードイン
	void FadeIn();

	//　フェードアウト
	void FadeOut();
};