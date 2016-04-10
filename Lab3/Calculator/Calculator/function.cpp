#include "stdafx.h"
#include "../Calculator/function.h"

void CFunction::OnUpdate()
{
	if (!m_isChanged)
	{
		m_isChanged = true;
		NotifyUpdate();
	}
}


CFunction::CFunction(FunctionParamethers & fnParams)
	: m_fnParams(fnParams)
{
}

Connection CFunction::SubscribeToFunction(Signal::slot_type const & handler)
{
	return m_sig.connect(handler);
}

double CFunction::GetValue()const
{
	return m_value;
}

bool CFunction::IsChanged()const
{
	return m_isChanged;
}

FunctionParamethers CFunction::GetFnParamethers()const
{
	return m_fnParams;
}


void CFunction::SetValue(double value)
{
	m_value = value;
}

void CFunction::Change(bool isChanged)
{
	m_isChanged = isChanged;
}

void CFunction::NotifyUpdate()const
{
	m_sig();
}
