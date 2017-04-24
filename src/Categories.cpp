#include "Categories.hpp"

using namespace std;
using namespace ncf;

Categories::Categories() :
    Menu()
{
}

Categories::~Categories()
{
}

void Categories::onItemAction(Menu::Item* item item) override
{
    auto entries = m_server->Entries(item->description(), false, 100);
    if (not entries.empty()) {
        lastReadEntryId = entries.front().id;
    }

    std::vector<ncf::Menu::Item*> items;
    for (auto& entry : entries) {
        items.push_back(new EntryItem(entry));
    }

    m_entriesMenu->setItems(items);
}

void Categories::markCategoryRead()
{
    m_server->MarkCategoryAs(currentItem().description(), Actions::READ, lastReadEntryId);

    auto entries = m_server->Entries(currentItem().description());
    std::vector<ncf::Menu::Item*> items;
    for (auto& entry : entries) {
        items.push_back(new EntryItem{entry});
    }
    m_entriesMenu->setItems(items);
}

int Categories::onKeyEvent(int ch) override
{
    switch(ch) {
        case 'r': markCategoryRead(); break;
        default: Menu::onKeyEvent(ch); break;
    }
    return 0;
}
