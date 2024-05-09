#include <iostream>
#include <Windows.h>
#include <pqxx/pqxx>
#pragma execution_character_set("utf-8")

using namespace std;

constexpr char* conn_str =
        "host=127.0.0.1 "
        "port=5432 "
        "dbname=lesson05 "
        "user=lessons "
        "password=lessons ";

class Clients
{
public:
    Clients();
    void AddClient(string firstname, string lastName, string email, string phone);
    void AddPhoneClient(string email, string phone);

private:
    void SQLCreateTables(pqxx::connection& conn);
    bool SQLExistClient(string email);
    bool SQLExistPhone(string phone);
    void SQLCreatePhone(string phone);
    void SQLCreateClient(string firstname, string lastName, string email, string phone);
    void SQLAddPhoneClient(string email, string phone);
};

Clients::Clients()
{
    try
    {
        pqxx::connection conn(conn_str);

        Clients::SQLCreateTables(conn);
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };

}

void Clients::SQLCreateTables(pqxx::connection& conn)
{
    pqxx::work tr{conn};
    tr.exec (
            "CREATE TABLE IF NOT EXISTS phoneNumber ( "
            "id SERIAL PRIMARY KEY, "
            "phone varchar(12) UNIQUE NOT NULL); ");
    tr.exec (
            "CREATE TABLE IF NOT EXISTS clients ( "
            "id SERIAL PRIMARY KEY, "
            "firstName varchar(50) NOT NULL, "
            "lastName varchar(50) NOT NULL, "
            "email varchar(100) UNIQUE NOT NULL, "
            "phone varchar(12) REFERENCES phoneNumber(phone)); ");
    tr.commit();
}

bool Clients::SQLExistClient(std::string email)
{
    string value;
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string query = "SELECT email FROM clients WHERE email = '" + tr.esc(email) + "';";
        value = tr.query_value<string>(query);
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };
    if (value != "" )
    {
        return TRUE;
    } else
    {
        return FALSE;
    }
}

bool Clients::SQLExistPhone(string phone)
{
    string value;
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string query = "SELECT phone FROM phoneNumber WHERE phone = '" + phone + "';";
        value = tr.query_value<string>(query);
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };
    if (value != "" )
    {
        return TRUE;
    } else
    {
        return FALSE;
    }

}

void Clients::SQLCreatePhone(string phone)
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string trans = "INSERT INTO phoneNumber(phone) values('" + tr.esc(phone) + "');";
        tr.exec(trans);
        tr.commit();
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };

}

void Clients::SQLCreateClient(std::string firstname, std::string lastName, std::string email, string phone = "")
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string trans;
        if (phone == "")
        {
            trans =
                    "INSERT INTO clients (firstName, lastName, email) "
                    "values('" + tr.esc(firstname) + "', '" + tr.esc(lastName)+"', '"+ tr.esc(email) + "'); ";
        }else
        {
            trans =
                    "INSERT INTO clients (firstName, lastName, email, phone) "
                    "values('" + tr.esc(firstname) + "', '" + tr.esc(lastName)+"', '"+ tr.esc(email) + "', '"+tr.esc(phone)+"'); ";
        }
        tr.exec(trans);
        tr.commit();
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };

}

void Clients::SQLAddPhoneClient(std::string email, std::string phone)
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string query = "SELECT phone FROM clients WHERE email = '" + tr.esc(email) + "';";
        string value = tr.query_value<string>(query);
        cout << value << endl;
        //string trans = "UPDATE clients SET email= '" + tr.esc(email) + "' WHERE phone= '" + tr.esc(phone) + "'";
        //tr.exec(trans);
        //tr.commit();
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };
}


void Clients::AddClient(std::string firstname, std::string lastName, std::string email, string phone)
{
    bool ExClient = Clients::SQLExistClient(email);
    if (ExClient)
    {
        cout << "Client exist" << endl;
    } else
    {
        bool ExPhone = Clients::SQLExistPhone(phone);
        if (ExPhone)
        {
            Clients::SQLCreateClient(firstname, lastName, email, phone);
        } else
        {
            Clients::SQLCreatePhone(phone);
            Clients::SQLCreateClient(firstname, lastName, email, phone);
        }
    }
}

void Clients::AddPhoneClient(std::string email, std::string phone)
{
    bool ExPhone = Clients::SQLExistPhone(phone);
    if (ExPhone)
    {
        Clients::SQLAddPhoneClient(email, phone);
    } else
    {
        Clients::SQLCreatePhone(phone);
        Clients::SQLAddPhoneClient(email, phone);
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Clients cl;
    string firstName = "Alexei";
    string lastName = "Kozlov";
    string email = "dicson-alex@yandex.ru";
    string phone = "+79637310088";
    string phone2 = "+79637310087";
    cl.AddClient(firstName, lastName, email, phone);
    cl.AddPhoneClient(email, phone2);

    return 0;
}