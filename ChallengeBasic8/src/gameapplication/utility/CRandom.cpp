#include "CRandom.hpp"

std::mt19937 CRandom::engine = std::mt19937( std::random_device()() );

CRandom::CRandom(const unsigned long seed){
	my_engine.seed(seed);
}

//�@�V�[�h�̐ݒ�
void CRandom::SetSeed(const unsigned long seed){
	engine.seed(seed);
}

//�@��l���z�̃����_��(����)
double CRandom::Uniform(const double min, const double max){
	std::uniform_real_distribution<double>random(min, max);
	double result = random(engine);
	return result;
}

//�@��l���z�̃����_��(����)
float CRandom::Uniform(const float min, const float max){
	std::uniform_real_distribution<float>random(min, max);
	float result = random(engine);
	return result;
}

//�@��l���z�̃����_��(����)
int CRandom::Uniform(const int min, const int max){
	std::uniform_int_distribution<int>random(min, max);
	int result = random(engine);
	return result;
}

//�@�x���k�[�C���z(�w�肵���m����true���o���A0.00~1.00)
bool CRandom::Bernulli(const float probability){
	std::bernoulli_distribution random(probability);
	bool result = random(engine);
	return result;
}

//�@���K���z
//�@exexpectation�F���Ғl
//�@error�F�W���΍�(�덷)
double CRandom::Gaussian(const double expectation, const double error){
	std::normal_distribution<double>random(expectation, error);
	double result = random(engine);
	return result;
}

int CRandom::Gaussian(const int expectation, const int error){
	std::normal_distribution<double>random(expectation, error);
	int result = static_cast<int>(random(engine));
	return result;
}

//�@�I����
int CRandom::Select(const std::vector<int> &select){
	std::uniform_int_distribution<int>random(0,select.size()-1);
	int result = random(engine);
	return select[result];
}