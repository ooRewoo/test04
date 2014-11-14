#pragma once
#include "../lib/appEnv.hpp"
#include "../lib/random.hpp"
#include <memory>

//========================================
//�R�s�[�֎~�N���X
//========================================

class Uncopyable{
public:
protected:
	Uncopyable() = default;
private:
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable &operator=(const Uncopyable&) = delete;
};