#ifndef APPLICATION_ENTRIES_MENU_H_
#define APPLICATION_ENTRIES_MENU_H_

#include <fdly.hpp>
#include <ncf/Menu.hpp>
#include <ncf/TextView.hpp>

#include <iostream>
#include <fstream>


class Entries : public ncf::Menu {
    public:
        Entries(ncf::TextView& view);

        void ShowPreview(const std::string& preview);

    private:
        ncf::TextView& m_previewTextView;
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
