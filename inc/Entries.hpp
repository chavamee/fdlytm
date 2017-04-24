#ifndef APPLICATION_ENTRIES_MENU_H_
#define APPLICATION_ENTRIES_MENU_H_

#include "ncf/Menu.hpp"
#include "ncf/TextView.hpp"
#include "Feedly.hpp"
#include <iostream>
#include <fstream>


class Entries : public ncf::Menu {
    public:
        using Menu::Menu;

        Entries(ncf::TextView* view) :

        void showPreview(const std::string& preview);

    private:
        ncf::TextView* m_previewTextView = nullptr;
};

class EntryItem : public ncf::Menu::Item {
    public:
        EntryItem(Feedly::Entry& entry) : Item(entry.title, entry.id), m_entry{entry}
        {
        }

        bool action() override
        {
            static_cast<Entries*>(menu())->showPreview(m_entry.content);
            return true;
        }

    private:
        Feedly::Entry m_entry;
};

#endif
