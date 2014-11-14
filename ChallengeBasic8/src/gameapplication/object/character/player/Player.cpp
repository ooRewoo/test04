#include "Player.hpp"
#include "../../item/sweet_potato/SweetPotato.hpp"
#include "../holyghost/HolyGhost.hpp"

CPlayer::CPlayer(std::shared_ptr<AppEnv>app_env,bool& is_contorol) :
CCharacter(app_env),
m_is_control(is_contorol),
m_score(0),
m_combo_num(-1)
{
	m_pos = m_app_env->mousePosition();
	m_size = Vec2f(128, 128);
}

//�@�ŏ��̏���
void CPlayer::Start(std::vector<std::shared_ptr<Object>>obj_list){
	m_combo_num = -1;
	m_score = 0;
	m_pos = Vec2f(0, 0);
	m_obj_list = obj_list;
}

//�@�X�V
void CPlayer::Update(){
	if (!m_is_active)return;
	Control();
	ComboUpdate();
}

//�@�`��
void CPlayer::Draw(){
	if (!m_is_active)return;
	drawTextureBox(m_pos.x() - m_size.x() / 2, m_pos.y() - m_size.y() / 2, m_size.x(), m_size.y(),
		0, 0, 512, 512,
		*m_res.m_player_graph, Color(1, 1, 1));
}

//�@�R���{�̍X�V
void CPlayer::ComboUpdate(){
	if (!m_is_active)return;
	UpdateComboOfSweetpotato();
	UpdateComboOfHolyghost();
}

//�@���̃R���{�X�V
void CPlayer::UpdateComboOfSweetpotato(){
	for (auto it = m_obj_list.begin(); it != m_obj_list.end(); it++){
		if ((*it)->GetType() == Type::SweetPotato){
			if (((*it)->GetisActive()))return;
			if (std::dynamic_pointer_cast<CSweetPotato>(*it)->GetisSwipe()){
				m_combo_num = -1;
			}
			else{
				m_combo_num++;
			}
		}
	}
}

//�@�_�l�̃R���{�X�V
void CPlayer::UpdateComboOfHolyghost(){
	for (auto it = m_obj_list.begin(); it != m_obj_list.end(); it++){
		if ((*it)->GetType() == Type::HolyGhost){
			if (((*it)->GetisActive()))return;
			if (std::dynamic_pointer_cast<CHolyGhost>(*it)->GetisSwipe()){
				m_combo_num = -1;
			}
			else{
				m_combo_num++;
			}
		}
	}
}

void CPlayer::UpdateOfObject(std::vector<std::shared_ptr<Object>>obj_list){
	m_obj_list = obj_list;
}

//�@����
void CPlayer::Control(){
	if (!m_is_control)return;
	m_pos = m_app_env->mousePosition();
}