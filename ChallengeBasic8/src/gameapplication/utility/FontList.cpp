#include "FontList.hpp"


FontList::FontList()
{
	m_font_list.insert(std::make_pair(L"���C���I", std::make_shared<FTPixmapFont>("res/font/meiryo.ttc")));
	m_font_list.insert(std::make_pair(L"�߂�܃t�H���g", std::make_shared<FTPixmapFont>("res/font/menma.ttf")));
	m_font_list.insert(std::make_pair(L"MS�@�S�V�b�N", std::make_shared<FTPixmapFont>("res/font/msgothic.ttc")));
	m_font_list.insert(std::make_pair(L"MS�@����", std::make_shared<FTPixmapFont>("res/font/msmincho.ttc")));
	m_font_list.insert(std::make_pair(L"�{�N�̂��񂯂�j�b�L", std::make_shared<FTPixmapFont>("res/font/bokuno.otf")));
	m_font_list.insert(std::make_pair(L"�j�R���W", std::make_shared<FTPixmapFont>("res/font/nicomoji_1.00.ttf")));
	m_font_list.insert(std::make_pair(L"Royal", std::make_shared<FTPixmapFont>("res/font/Royal.ttf")));
	m_font_list.insert(std::make_pair(L"Pacifico", std::make_shared<FTPixmapFont>("res/font/Pacifico.ttf")));
	m_font_list.insert(std::make_pair(L"FatBoy", std::make_shared<FTPixmapFont>("res/font/FatboyUltra.otf")));
}
