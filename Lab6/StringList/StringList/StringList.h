#pragma once
#include <string>
#include <memory>

struct Node
{
	std::string str;
	std::shared_ptr<Node> next = nullptr;
	std::shared_ptr<Node> prev = nullptr;
};

class CStringList
{
public:
	~CStringList();
	void PushFront(std::string const &str);
	void PushBack(std::string const &str);
	void PopBack(std::string const &str);
	void Clear();
	bool IsEmpty();

	size_t GetSize();
private:
	size_t m_size;
	std::shared_ptr<Node> m_begin = nullptr;
	std::shared_ptr<Node> m_end = nullptr;
};
