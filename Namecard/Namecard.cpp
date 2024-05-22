#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

const int NAME_SIZE{ 21 };
const int CORP_SIZE{ 31 };
const int TEL_SIZE{ 16 };
const int REC_SIZE{ NAME_SIZE + CORP_SIZE + TEL_SIZE };

struct card
{
    char name[NAME_SIZE];
    char corp[CORP_SIZE];
    char tel[TEL_SIZE];
    card *next;
};

card *head, *tail;

void init_card()
{
    head = new card;
    tail = new card;
    head->next = tail;
    tail->next = nullptr; // Corrected to nullptr
}

void input_card()
{
    card *t = new card;

    std::cout << "\nInput namecard menu : ";
    std::cout << "\nInput name -> ";
    std::cin.ignore();
    std::cin.getline(t->name, NAME_SIZE);
    std::cout << "\nInput corporation -> ";
    std::cin.getline(t->corp, CORP_SIZE);
    std::cout << "\nInput telephone number -> ";
    std::cin.getline(t->tel, TEL_SIZE);

    t->next = head->next;
    head->next = t;
}

void print_card(card *t, std::ostream &oFile)
{
    oFile << "\n\t" << t->name << "\t" << t->corp << "\t" << t->tel;
}

void print_head(std::ostream &oFile)
{
    oFile << "\nName\t\t" << "Corporation\t\t\t" << "Telephone number";
    oFile << "\n------------------ " << "-------------------------- " << "------------";
}

void load_cards(const std::string &filename)
{
    std::ifstream file(filename);
    card *t;
    card *u;

    if (!file.is_open())
    {
        std::cout << "\n\tError : " << filename << " does not exist.";
        return;
    }

    t = head->next;
    while (t != tail)
    {
        u = t;
        t = t->next;
        delete u;
    }
    head->next = tail;

    while (true)
    {
        t = new card;
        if (!file.read(reinterpret_cast<char *>(t), sizeof(card)))
        {
            delete t;
            break;
        }
        t->next = head->next;
        head->next = t;
    }
    file.close();
}

void save_cards(const std::string &filename)
{
    std::ofstream file(filename);
    card *t;
    if (!file.is_open())
    {
        std::cout << "\n\tError : Disk write failure.";
        return;
    }

    t = head->next;
    while (t != tail)
    {
        file.write(reinterpret_cast<char *>(t), sizeof(card));
        t = t->next;
    }
    file.close();
}

bool delete_card(const char *s)
{
    card *p = head;
    card *t = p->next;
    while (t != tail && std::strcmp(s, t->name) != 0)
    {
        p = p->next;
        t = p->next;
    }
    if (t == tail)
        return false;
    p->next = t->next;
    delete t;
    return true;
}

card *search_card(const char *s)
{
    card *t = head->next;
    while (t != tail && std::strcmp(s, t->name) != 0)
        t = t->next;
    if (t == tail)
        return nullptr;
    else
        return t;
}

int select_menu()
{
    int i;
    std::string s;
    std::cout << "\n\nNAMECARD Manager";
    std::cout << "\n-----------------";
    std::cout << "\n1. Input Namecard";
    std::cout << "\n2. Delete Namecard";
    std::cout << "\n3. Search Namecard";
    std::cout << "\n4. Load Namecard";
    std::cout << "\n5. Save Namecard";
    std::cout << "\n6. List Namecard";
    std::cout << "\n7. End Namecard";
    do
    {
        std::cout << "\n\n\t: select operation -> ";
        std::getline(std::cin, s);
        try {
            i = std::stoi(s);
        }
        catch (...) {
            i = 0; // default to 0 if conversion fails
        }
    } while (i < 1 || i > 7);
    return i;
}

int main()
{
    const std::string filename = "NAMECARD.txt";
    char name[NAME_SIZE];
    int i;
    card *t;
    init_card();
    while ((i = select_menu()) != 7)
    {
        switch (i)
        {
        case 1:
            input_card();
            break;
        case 2:
            std::cout << "\n\tInput name to delete -> ";
            std::cin.ignore();
            std::cin.getline(name, NAME_SIZE);
            if (!delete_card(name))
                std::cout << "\n\tCan't find that name.";
            break;
        case 3:
            std::cout << "\n\tInput name to search -> ";
            std::cin.ignore();
            std::cin.getline(name, NAME_SIZE);
            t = search_card(name);
            if (t == nullptr)
            {
                std::cout << "\n\tCan't find that name.";
                break;
            }
            print_head(std::cout);
            print_card(t, std::cout);
            break;
        case 4:
            load_cards(filename);
            break;
        case 5:
            save_cards(filename);
            break;
        case 6:
            t = head->next;
            print_head(std::cout);
            while (t != tail)
            {
                print_card(t, std::cout);
                t = t->next;
            }
            break;
        }
    }
    std::cout << "\n\nProgram ends...";
    return 0;
}