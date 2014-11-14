#pragma once
#include "../../lib/vector.hpp"

//=======================================
//�v�Z��
//=======================================
namespace Math{
	template<typename T>
	//�@�p�x���擾
	T GetAngle(const Vec2f &vec_a, const Vec2f &vec_b, const Vec2f &origin, bool is_degree = false);

	//�@�������擾
	double GetDistance(const Vec2f &vec);
	
	//�@���ς��擾
	double GetScalarProduct(const Vec2f &vec_a, const Vec2f &vec_b);
	
	//�@2�_�Ԃ̋������擾
	double Get2Distance(const Vec2f &vec_a, const Vec2f &vec_b);
	
	//�@2�_�Ԃ̋������擾(float)
	float Get2Distancef(const Vec2f &vec_a, const Vec2f &vec_b);
	
	//�@2�_�Ԃ̍�(vec_a - vec_b)
	Vec2f GetDiff(const Vec2f &vec_a, const Vec2f &vec_b);
};

