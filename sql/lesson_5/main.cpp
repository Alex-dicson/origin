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
    void EditClient(string email, string phone, string newFirstName, string newLastName, string newPhone);
    void DelPhone(string phone);

private:
    void SQLCreateTables(pqxx::connection& conn);
    bool SQLExistClient(string email);
    bool SQLExistPhone(string phone);
    void SQLCreatePhone(string phone, string email);
    void SQLCreateClient(string firstname, string lastName, string email);
    void SQLAddPhoneClient(string email, string phone);
    void SQLEditClient(string email, string newFirstName, string newLastName);
    void SQLEditPhone(string phone, string newPhone);
    void SQLDelPhone(string phone);
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
            "CREATE TABLE IF NOT EXISTS clients ( "
            "id SERIAL PRIMARY KEY, "
            "firstName varchar(50) NOT NULL, "
            "lastName varchar(50) NOT NULL, "
            "email varchar(100) UNIQUE NOT NULL); ");
    tr.exec (
            "CREATE TABLE IF NOT EXISTS phoneNumber ( "
            "id SERIAL PRIMARY KEY, "
            "email varchar(100) REFERENCES clients(email), "
            "phone varchar(12) UNIQUE NOT NULL); ");
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

bool Clients::SQLExistPhone(std::string phone)
{
    string value;
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string query = "SELECT phone FROM phoneNumber WHERE phone = '" + tr.esc(phone) + "';";
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

void Clients::SQLCreatePhone(std::string phone, std::string email)
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string trans = "INSERT INTO phoneNumber(email, phone) values('" + tr.esc(email) + "', '" + tr.esc(phone) + "'); ";
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
        string query = "SELECT email, phone FROM phoneNumber WHERE email = '" + tr.esc(email) + "';";
        auto value = tr.query<string, string>(query);
        for (auto elem : value)
        {
            cout << get<0>(elem) << "   " << get<1>(elem) << endl;
        }
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };
}

void Clients::SQLEditClient(std::string email, std::string newFirstName, std::string newLastName)
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string trans = "UPDATE clients SET "
                       "firstName = '" + tr.esc(newFirstName) + "', "
                       "lastName = '" + tr.esc(newLastName) + "' "
                       "WHERE email = '" + tr.esc(email) + "'; ";
        tr.exec(trans);
        tr.commit();
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };
}

void Clients::SQLEditPhone(std::string phone, std::string newPhone)
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string trans = "UPDATE phoneNumber SET phone = '" + tr.esc(newPhone) + "' WHERE phone = '" + tr.esc(phone) + "';";
        tr.exec(trans);
        tr.commit();
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };
}

void Clients::SQLCreateClient(std::string firstname, std::string lastName, std::string email)
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string trans, trans2;
        trans =
                "INSERT INTO clients (firstName, lastName, email) "
                "values('" + tr.esc(firstname) + "', '" + tr.esc(lastName)+"', '"+ tr.esc(email) + "'); ";
        tr.exec(trans);
        tr.commit();
    }
    catch (const exception& e)
    {
        cout << "Exception happened: " << e.what() << endl;
    };

}

void Clients::SQLDelPhone(std::string phone)
{
    try
    {
        pqxx::connection conn(conn_str);

        pqxx::work tr{conn};
        string trans, trans2;
        trans = "DELETE FROM phoneNumber WHERE phone = '" + tr.esc(phone) + "';";
        tr.exec(trans);
        tr.commit();
        cout << "Phone - " << phone << " delete!" << endl;
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
            Clients::SQLCreateClient(firstname, lastName, email);
        } else
        {
            Clients::SQLCreateClient(firstname, lastName, email);
            Clients::SQLCreatePhone(phone, email);
        }
    }
}

void Clients::AddPhoneClient(std::string email, std::string phone)
{
    bool ExPhone = Clients::SQLExistPhone(phone);
    if (ExPhone)
    {
        cout << "Phone exist" << endl;
    } else
    {
        Clients::SQLCreatePhone(phone, email);
        Clients::SQLAddPhoneClient(email, phone);
    }
}

void Clients::EditClient(std::string email, std::string phone, std::string newFirstName, std::string newLastName, std::string newPhone)
{
    bool ExClient = Clients::SQLExistClient(email);
    bool ExPhone = Clients::SQLExistPhone(phone);
    if(ExPhone)
    {
        Clients::SQLEditPhone(phone, newPhone);
    } else
    {
        cout << "The phone - " << phone << " was not found in the database" << endl;
    }
    if(ExClient)
    {
        Clients::SQLEditClient(email, newFirstName, newLastName);
    }else
    {
        cout << "The client with the email - " << email << " was not found!" << endl;
    }
}

void Clients::DelPhone(std::string phone)
{
    bool ExPhone = Clients::SQLExistPhone(phone);
    if(ExPhone)
    {
        Clients::SQLDelPhone(phone);
    } else
    {
        cout << "The phone - " << phone << " was not found in the database" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Clients cl;
    string firstName = "Andrei";
    string lastName = "Petrov";
    string email = "dicson-alex@yandex.ru";
    string phone = "+79637310087";
    string phone2 = "+79637310088";
    string newFirstName = "Alexei";
    string newLastName = "Kozlov";
    string newPhone = "+79000000000";
    string delPhone = "+79000000000";
    cl.AddClient(firstName, lastName, email, phone);
    cl.AddPhoneClient(email, phone2);
    cl.EditClient(email, phone, newFirstName, newLastName, newPhone);
    cl.DelPhone(delPhone);

    return 0;
}