#pragma once
#include "../../lib/vector.hpp"

//=======================================
//�����蔻��
//=======================================

namespace Collision{
	//�@�~�Ɠ_�̓����蔻��
	bool CircleAndPoint(Vec2f& circle_pos, float radius, Vec2f& point_pos);

	//�@�~�Ɖ~�̓����蔻��
	bool CircleAndCircle(Vec2f& a_pos, Vec2f& b_pos, float a_radius, float b_radius);

	//�@�l�p�Ǝl�p�̓����蔻��
	bool PlaneAndPlane(Vec2f& a_pos, Vec2f& a_size, Vec2f& b_pos, Vec2f& b_size);
};