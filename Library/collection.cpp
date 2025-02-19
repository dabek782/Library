#include "collection.h"
#include <iostream>



void Collection::AddBook(
	int bookId,
	std::string author,
	std::string title,
	std::string genre,
	int publication_year,
	bool IsBorrowed)
{
	books.emplace(bookId, Book(bookId, author, title, genre, publication_year, IsBorrowed));
	std::cout << "Book was added to library"<<std::endl;
}
void Collection::AddMember(int MemberID, std::string Name, std::string Email, int Phone)
{
	members.emplace(MemberID, Member(MemberID, Name, Email, Phone));
	std::cout << "Member was given library id"<<std::endl;
	
}
void Collection::DisplayBook(int ID)
{
	for (std::map<int, Book>::iterator i = books.begin(); i != books.end(); i++)
	{
		if (i->first == ID)
		{
			i->second.Display();
		}
		else
		{
			std::cout << "Book not found" << std::endl;
		}
	}
}
void Collection::DisplayMember(int MemberID)
{
	members[MemberID].Display();
}
void Collection::DisplayBooks()
{
	std::map<int, Book>::iterator i;
	for (i = books.begin(); i != books.end(); i++)
	{
		i->second.Display();
	}
} 
void Collection::DisplayMembers()
{
	std::map<int, Member>::iterator m;
	for (m = members.begin(); m != members.end(); m++)
	{
		m->second.Display();
	}
}
void Collection::RemoveBook(int ID)
{
	books.erase(ID);
	std::cout << "Book was removed from library" << std::endl;
}
void Collection::RemoveMember(int MemberID)
{
	std::cout << "Member was deleted from database" << std::endl;
}
void Collection::BorrowBook(int BookID, int MemberID)
{
	auto bookIt = books.find(BookID);
	auto memberIt = members.find(MemberID);
	if (bookIt == books.end())
	{
		std::cout << "Book not found" << std::endl;
	}
	else if (memberIt == members.end())
	{
		std::cout << "Member not found" << std::endl;
	}
	else if (bookIt->second.isBorrowed())
	{
		std::cout << "Book is already borrowed" << std::endl;
	}
	else
	{
		bookIt->second.Change_status(true);
		memberIt->second.AddBook(BookID);
		std::cout << "Book was succesefully borrowed" << std::endl;
	}
}
void Collection::ReturnBook(int BookID, int MemberID)
{
	std::map<int, Book>::iterator i;
	for (i = books.begin(); i != books.end(); i++)
	{
		if (i->first != BookID)
		{
			std::cout << "Book not found" << std::endl;
		}
		else if (i->first == BookID && i->second.isBorrowed() == false)
		{
			std::cout << "Book is not borrowed" << std::endl;
		}
		else
		{
			i->second.Change_status(false);
			members[MemberID].RemoveBook(BookID);
			std::cout << "Book was succesefully returned" << std::endl;
		}
	}
}
Collection::~Collection() {
	std::cout << "Library was deleted" << std::endl;


}