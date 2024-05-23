#include <iostream>
#include <wt/Dbo/Dbo.h>
#include <wt/Dbo/backend/Postgres.h>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

class Publisher;
class Book;
class Stock;
class Shop;
class Sale;


class Publisher
{
public:
	string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> book;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, book, Wt::Dbo::ManyToOne, "publisher");
	}
};

class Book
{
public:
	string title = "";
	Wt::Dbo::ptr<Publisher> publisher;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stock;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "book");
	}
};

class Stock
{
public:
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;
	Wt::Dbo::collection < Wt::Dbo::ptr<Sale>> sale;
	int count = 0;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::belongsTo(a, shop, "shop");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::hasMany(a, sale, Wt::Dbo::ManyToOne, "stock");

	}

};

class Shop
{
public:
	string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stock;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "shop");
	}
};

class Sale
{
public:
	int price = 0;
	string data_sale;
	Wt::Dbo::ptr<Stock> stock;
	int count = 0;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, data_sale, "data_sale");
		Wt::Dbo::belongsTo(a, stock, "stock");
		Wt::Dbo::field(a, count, "count");

	}

};

int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);


	try
	{
		string connString =
			"host=localhost "
			"port=5432 "
			"dbname=lesson06 "
			"user=lessons "
			"password=lessons";

		auto postgres = make_unique<Wt::Dbo::backend::Postgres>(connString);

		Wt::Dbo::Session s;
		s.setConnection(move(postgres));
		s.mapClass< Publisher>("publisher");
		s.mapClass< Book>("book");
		s.mapClass< Stock>("stock");
		s.mapClass< Shop>("shop");
		s.mapClass< Sale>("sale");

		s.dropTables();
		s.createTables();

		Wt::Dbo::Transaction tr{ s };

		unique_ptr<Publisher> p1{ new Publisher{"Дрофа", {}} };
		unique_ptr<Publisher> p2{ new Publisher{"Эксмо", {}} };
		unique_ptr<Publisher> p3{ new Publisher{"Просвещение", {}} };

		auto p1db = s.add<Publisher>(move(p1));
		auto p2db = s.add<Publisher>(move(p2));
		auto p3db = s.add<Publisher>(move(p3));

		unique_ptr<Shop> s1{ new Shop{"Победы", {}} };
		unique_ptr<Shop> s2{ new Shop{"Октябрьский", {}} };
		unique_ptr<Shop> s3{ new Shop{"Дыбенко", {}} };

		auto s1db = s.add<Shop>(move(s1));
		auto s2db = s.add<Shop>(move(s2));
		auto s3db = s.add<Shop>(move(s3));

		unique_ptr<Book> b1{ new Book{"Война и мир", p1db, {}} };
		unique_ptr<Book> b2{ new Book{"Анна Каренина", p2db, {}} };
		unique_ptr<Book> b3{ new Book{"Зов предков", p3db, {}} };

		auto b1db = s.add<Book>(move(b1));
		auto b2db = s.add<Book>(move(b2));
		auto b3db = s.add<Book>(move(b3));

		unique_ptr<Stock> st1{ new Stock{b1db, s1db, {}, 10} };
		unique_ptr<Stock> st2{ new Stock{b2db, s2db, {}, 15} };
		unique_ptr<Stock> st3{ new Stock{b3db, s3db, {}, 20} };

		auto st1db = s.add<Stock>(move(st1));
		auto st2db = s.add<Stock>(move(st2));
		auto st3db = s.add<Stock>(move(st3));

		unique_ptr<Sale> sl1{ new Sale{200, "2024-04-20", st1db, 2} };
		unique_ptr<Sale> sl2{ new Sale{370, "2024-04-22", st2db, 5} };
		unique_ptr<Sale> sl3{ new Sale{500, "2024-04-21", st3db, 7} };

		auto sl1db = s.add<Sale>(move(sl1));
		auto sl2db = s.add<Sale>(move(sl2));
		auto sl3db = s.add<Sale>(move(sl3));
		
		tr.commit();

		{
			Wt::Dbo::Transaction s2(s);
			string input;
			int id;
			cout << "Enter name or id of publisher: ";
			cin >> input;

			bool isNumber;

			try
			{
				id = stoi(input);
				isNumber = true;
			}
			catch(...)
			{
				isNumber = false;
			}

			Wt::Dbo::ptr<Publisher> p;

			if(isNumber)
			{
				p = s.find<Publisher>().where("id=?").bind(id);
			}
			else
			{
				p = s.find<Publisher>().where("name=?").bind(input);
			}

			if(p)
			{
				cout << "Publisher found: " << p->name << endl;

				set<string> shopNames;
				for(const auto& book : p->book)
				{
					for(const auto& stock : book->stock)
					{
						shopNames.insert(stock->shop->name);
					}
				}

				cout << "Name of shops: " << endl;
				for(const auto& shopName : shopNames)
				{
					cout << shopName << endl;
				}
			}
			else
			{
				cout << "Publisher not found: " << endl;
			}
		}

	}
	catch(Wt::Dbo::Exception& e)
	{
		cout << e.what() << endl;
	}


	return 0;

}