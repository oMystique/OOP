#pragma once

#include <string>
#include <memory>

class CStringList
{
	struct Node
	{
		Node(const std::string & data, Node * prev, std::unique_ptr<Node> && next)
			: data(data), prev(prev), next(std::move(next))
		{
		}
		std::string data;
		Node *prev;
		std::unique_ptr<Node> next;
	};
public:
	size_t GetSize()const;
	void Append(const std::string &data);
	void AddToFront(const std::string &data);
	bool IsEmpty()const;
	void Clear();

	class CIterator
	{
		friend bool const operator==(CStringList::CIterator const &it1, CStringList::CIterator const &it2);
		friend CStringList;
		CIterator(Node *node, bool isReverse = false);
	public:
		CIterator() = default;
		std::string &operator*()const;
		CIterator &operator++()
		{
			m_node = m_node->next.get();
			return *this;
		}
	private:
		Node *m_node = nullptr;
		bool m_isReverse = false;
	};

	CIterator begin();
	CIterator end();

	void Insert(CIterator &iter, std::string const &data);
	std::string & GetBackElement();
	std::string & GetFrontElement();
	std::string const& GetBackElement()const;
	std::string const& GetFrontElement()const;
private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node *m_lastNode = nullptr;
};


inline bool const operator==(CStringList::CIterator const &it1, CStringList::CIterator const &it2)
{
	return it1.m_node == it2.m_node;
}