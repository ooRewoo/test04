#include "SceneManager.hpp"
#include "title\Title.hpp"
#include "stage\Stage.hpp"
#include "rule\Rule.hpp"
#include "ranking\Ranking.hpp"
#include "result\Result.hpp"


CSceneManager::CSceneManager(std::shared_ptr<AppEnv>app_env) :
m_state(State::INIT),
m_scene(nullptr),
m_now_scene(Scene::STAGE),
m_app_env(app_env),
m_isFade(false),
m_alpha(255)
{
}


//　遷移処理
void CSceneManager::Transition(){
	if (m_state != State::INIT)return;



	m_scene = (m_scene_list.find(m_now_scene))->second;
	m_scene->Start();
	m_old_scene = m_now_scene;
	m_state = State::UPDATE;
}

//　更新
void CSceneManager::Update(){
	SceneUpdate();
	Transition();

	FadeIn();
	FadeOut();
}

//　描画
void CSceneManager::Draw(){
	// 描画準備
	m_app_env->setupDraw();
	
	if (m_state == State::UPDATE){
		m_scene->Draw();
	}

	drawFillBox(-m_scene->WIDTH / 2, -m_scene->HEIGHT / 2, m_scene->WIDTH, m_scene->HEIGHT, color256(0, 0, 0, m_alpha));
	// 画面更新
	m_app_env->update();
}

//　遷移したいシーンを渡す関数
void CSceneManager::TransformOfScene(const Scene next_scene){
	m_now_scene = next_scene;
	m_isFade = true;
}

//　シーンの更新
void CSceneManager::SceneUpdate(){
	if (m_state != State::UPDATE)return;
	m_scene->Update();
	if (m_now_scene != m_old_scene){
		if (!m_isFade){
			m_state = State::INIT;
		}
	}
}

//　シーンリスト
void CSceneManager::AddSceneList(){
	m_scene_list.emplace(Scene::TITLE, std::make_shared<CTitle>(m_app_env, shared_from_this()));
	m_scene_list.emplace(Scene::STAGE, std::make_shared<CStage>(m_app_env, shared_from_this()));
	m_scene_list.emplace(Scene::RULE, std::make_shared<CRule>(m_app_env, shared_from_this()));
	m_scene_list.emplace(Scene::RANKING, std::make_shared<CRanking>(m_app_env, shared_from_this()));
	m_scene_list.emplace(Scene::RESULT, std::make_shared<CResult>(m_app_env, shared_from_this()));
}

//　フェードイン
void CSceneManager::FadeIn(){
	if (m_isFade)return;
	if (m_alpha > 0){
		m_alpha-=2;
		m_scene->TransformOfisControl(false);
	}
	else{
		m_scene->TransformOfisControl(true);
	}
}

//　フェードアウト
void CSceneManager::FadeOut(){
	if (!m_isFade)return;
	if (m_alpha < 255){
		m_alpha+= 2;
		m_scene->TransformOfisControl(false);
	}
	else{
		m_isFade = false;
		m_scene->TransformOfisControl(true);
	}
}