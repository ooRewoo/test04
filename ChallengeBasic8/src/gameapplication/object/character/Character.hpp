#pragma once
#include "../Object.hpp"
#include "../../resource/Resource.hpp"

class CCharacter : public Object{
public:
	CCharacter(std::shared_ptr<AppEnv>m_app_env);

protected:
	int m_hp;
	Vec2f m_hit_pos;
	Vec2f m_hit_size;
	CResource& m_res;
	std::shared_ptr<AppEnv>m_app_env;									//�@�A�v���C�x���g�����锠
	std::vector<std::shared_ptr<Object>>m_obj_list;						//�@��
};

