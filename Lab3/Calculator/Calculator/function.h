#pragma once
#include "signals.h"

struct FunctionParamethers
{
	FunctionParamethers() = default;
	FunctionParamethers(std::string const &tValue1, std::string const &tOperand, std::string const &tValue2)
		: value1(tValue1)
		, operand(tOperand)
		, value2(tValue2)
	{};

	std::string value1 = "";
	std::string operand = "";
	std::string value2 = "";
};

class CFunction
{
public:
	CFunction() = default;
	CFunction(FunctionParamethers &fnParams);

	Connection SubscribeToFunction(Signal::slot_type const &handler);

	double GetValue()const;
	bool IsChanged()const;
	FunctionParamethers GetFnParamethers()const;

	void SetValue(double value);
	void Change(bool isChanged);
	void OnUpdate();
private:
	void NotifyUpdate()const;
private:
	Signal m_sig;
	FunctionParamethers m_fnParams;
	double m_value;
	bool m_isChanged = true;
};