#pragma once
#include "Book.h"
#include "Member.h"
#include <map>
class Collection
{
private:
	std::map<int, Book> books;
	std::map<int, Member> members;
public:

	void AddBook(int bookId,
		std::string author,
		std::string title,
		std::string genre,
		int publication_year,
		bool IsBorrowed);
	void AddMember(int MemberID, std::string Name, std::string Email, int Phone);
	void DisplayBooks();
	void DisplayMembers();
	void DisplayBook(int ID);
	void DisplayMember(int MemberID);
	void RemoveBook(int ID);
	void RemoveMember(int MemberID);
	void BorrowBook(int BookID, int MemberID);
	void ReturnBook(int BookID, int MemberID);
	~Collection();
};

