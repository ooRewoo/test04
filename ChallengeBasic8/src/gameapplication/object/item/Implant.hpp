#pragma once
#include "../Object.hpp"
#include "../../resource/Resource.hpp"

class CImplant : public Object{
public:
	CImplant(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Object> object);

	//�@���������Ƃ��̏���
	void isHit(Vec2f& pos);

	//�@�X���C�v���ꂽ�����擾
	bool GetisSwipe(){ return m_isswipe; }

protected:
	Vec2f m_hit_pos;							//�@�����蔻��p�̃|�W�V����
	Vec2f m_hit_size;							//�@�����蔻��p�̃T�C�Y
	CResource& m_res;							//�@���\�[�X�̔�
	bool m_istap;								//�@�^�b�v���ꂽ��
	bool m_isswipe;								//�@�X���C�v���ꂽ��
	bool isRemove;								//�@�폜���邩
	std::shared_ptr<AppEnv> m_app_env;			//�@�A�v���C�x���g�̔�
	std::shared_ptr<Object> m_player;			//�@�v���C���[�����锠
};

