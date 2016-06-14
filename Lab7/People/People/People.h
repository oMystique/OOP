#pragma once
#include <string>

class IPerson
{
public:
	virtual ~IPerson() = default;
	virtual std::string GetName()const = 0;
	virtual std::string GetSurName()const = 0;
	virtual std::string GetPatronymic()const = 0;
	virtual std::string GetAddress()const = 0;
};

template <typename Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(std::string const &name, std::string const &surName
		, std::string const &patronymic, std::string const &address)
		: m_name(name)
		, m_surname(surName)
		, m_patronymic(patronymic)
		, m_address(address)
	{};
	std::string GetName()const override
	{
		return m_name;
	}
	std::string GetSurName()const override
	{
		return m_surname;
	}
	std::string GetPatronymic()const override
	{
		return m_patronymic;
	}
	std::string GetAddress()const override
	{
		return m_address;
	}
private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	std::string m_address;
};

class IPupil : public IPerson
{
public:
	virtual std::string GetSchoolName()const = 0;
	virtual std::string GetClass()const = 0;
};

class CPupil : public CPersonImpl<IPupil>
{
public:
	CPupil(std::string const &name, std::string const &surName
		, std::string const &patronymic, std::string const &address
		, std::string const &schoolName, std::string const pupilClass)
		: CPersonImpl(name, surName, patronymic, address)
		, m_schoolName(schoolName)
		, m_class(pupilClass)
	{};
	std::string GetSchoolName()const override
	{
		return m_schoolName;
	}
	std::string GetClass()const override
	{
		return m_class;
	}
private:
	std::string m_schoolName;
	std::string m_class;
};

class ITeacher: public IPerson
{
public:
	virtual std::string GetCourseTitle()const = 0;
};

class CTeacher : public CPersonImpl<ITeacher>
{
public:
	CTeacher(std::string const &name, std::string const &surName
		, std::string const &patronymic, std::string const &address
		, std::string const &courseTitle)
		: CPersonImpl(name, surName, patronymic, address)
		, m_courseTitle(courseTitle)
	{};
	std::string GetCourseTitle()const override
	{
		return m_courseTitle;
	}
private:
	std::string m_courseTitle;
};


class IStudent: public IPerson
{
public:
	virtual std::string GetUniversityName()const = 0;
	virtual size_t GetStudentCardNumber()const = 0;
};

template <typename Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	CStudentImpl(std::string const &name, std::string const &surName
		, std::string const &patronymic, std::string const &address
		, std::string const &universityName, size_t studentCardNumber)
		: CPersonImpl<Base>(name, surName, patronymic, address)
		, m_universityName(universityName)
		, m_studentCardNumber(studentCardNumber)
	{
	}
	std::string GetUniversityName()const override
	{
		return m_universityName;
	}
	size_t GetStudentCardNumber()const override
	{
		return m_studentCardNumber;
	}
private:
	std::string m_universityName;
	size_t m_studentCardNumber;
};

class CStudent : public CStudentImpl<IStudent>
{
	CStudent(std::string const &name, std::string const &surName
		, std::string const &patronymic, std::string const &address
		, std::string const &universityName, size_t studentCardNumber)
		: CStudentImpl(name, surName, patronymic, address, universityName, studentCardNumber)
	{};
};

class IAdvancedStudent : public IStudent
{
public:
	virtual std::string GetDissertationTopic()const = 0;
};

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	CAdvancedStudent(std::string const &name, std::string const &surName
		, std::string const &patronymic, std::string const &address
		, std::string const &universityName, size_t studentCardNumber
		, std::string const &dissertationTopic)
		: CStudentImpl(name, surName, patronymic, address, universityName, studentCardNumber)
		, m_dissertationTopic(dissertationTopic)
	{};
	std::string GetDissertationTopic()const override
	{
		return m_dissertationTopic;
	}
private:
	std::string m_dissertationTopic;
};

class IWorker: public IPerson
{
public:
	virtual std::string GetSpeciality()const = 0;
};

class CWorker : public CPersonImpl<IWorker>
{
public:
	CWorker(std::string const &name, std::string const &surName
		, std::string const &patronymic, std::string const &address
		, std::string const &speciality)
		: CPersonImpl(name, surName, patronymic, address)
		, m_speciality(speciality)
	{};
	std::string GetSpeciality()const override
	{
		return m_speciality;
	}
private:
	std::string m_speciality;
};