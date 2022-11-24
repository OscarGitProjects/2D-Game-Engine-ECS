#include "CFontResources.h"

/* Destructor */
CFontResources::~CFontResources()
{
	m_FontMap.erase(m_FontMap.begin(), m_FontMap.end());
	m_FontMap.clear();
}
