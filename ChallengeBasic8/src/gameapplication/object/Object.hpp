#pragma once
#include "../Uncopyable.hpp"
#include "../../lib/vector.hpp"
#include <vector>
#include <memory>
#include <list>

//========================================
//�I�u�W�F�N�g�N���X(���N���X)
//========================================

class Object : private Uncopyable{
public:
	Object() = default;
	virtual ~Object() = default;

	//�@�X�V
	virtual void Update() = 0;
	//�@�`��
	virtual void Draw() = 0;
	
	//�@�폜���邩
	bool isRemove(){
		if (!m_is_active){
			return true;
		}
		else {
			return false;
		}
	}

	//�@���W���擾
	Vec2f GetPos(){
		return m_pos;
	}

	//�@���W���擾
	Vec2f GetSize(){
		return m_size;
	}

	//�@�A�N�e�B�u���擾
	bool GetisActive(){ return m_is_active; }
	
	enum class Type{
		SweetPotato,
		HolyGhost
	};

	//�@�^�C�v�̎擾
	Type GetType(){ return m_type; }

protected:
	int m_alpha;
	float m_alphaf;

	Vec2f m_pos;
	Vec2f m_size;
	Vec2f m_vec;
	Type m_type;
	//	�A�N�e�B�u�ȏ�Ԃ�
	bool m_is_active = true;
};

typedef std::vector<std::unique_ptr<Object>> ArrayVec;
typedef std::vector<std::shared_ptr<Object>> ArrayList;