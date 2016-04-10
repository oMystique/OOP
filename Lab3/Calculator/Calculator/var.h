#pragma once
#include "signals.h"
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

class CVar 
{
public:
	CVar() = default;
	CVar(double var);

	void NotifyUpdate()const;
	void SetValue(double value);

	Connection SubscribeToFunction(Signal::slot_type const &handler);

	boost::optional<double> GetValue()const;
private:
	boost::optional<double> m_value;
	Signal m_sig;
};