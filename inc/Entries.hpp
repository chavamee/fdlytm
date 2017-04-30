#ifndef APPLICATION_ENTRIES_MENU_H_
#define APPLICATION_ENTRIES_MENU_H_

#include <fdly.hpp>
#include <ncf/Menu.hpp>
#include <ncf/TextBox.hpp>

#include <iostream>
#include <fstream>


class Entries : public ncf::Menu {
    public:
        Entries(ncf::TextBox& box);

        void ShowPreview(const std::string& preview);

    private:
        ncf::TextBox& m_previewTextBox;
};

class EntryItem : public ncf::Menu::Item {
    public:
        EntryItem(Fdly::Entry& entry) : Item(entry.Title, entry.ID), m_entry{entry}
        {
        }

        bool action() override
        {
            static_cast<Entries*>(menu())->ShowPreview(m_entry.Content);
            return true;
        }

    private:
        Fdly::Entry m_entry;
};

#endif
