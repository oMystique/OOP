#include "stdafx.h"
#include "../Calculator/var.h"

CVar::CVar(double var)
	: m_value(var)
{
};

void CVar::NotifyUpdate()const
{
	m_sig();
}

Connection CVar::SubscribeToFunction(Signal::slot_type const & handler)
{
	return m_sig.connect(handler);
}

void CVar::SetValue(double value)
{
	m_value = value;
}

boost::optional<double> CVar::GetValue()const
{
	return m_value;
}
