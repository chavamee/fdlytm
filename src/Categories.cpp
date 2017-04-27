#include "Categories.hpp"

using namespace std;
using namespace ncf;

Categories::Categories(Fdly& server, Menu& entriesMenu) :
    m_entriesMenu {entriesMenu},
    m_server {server}
{
}

Categories::~Categories()
{
}

void Categories::onItemAction(Menu::Item* item)
{
    auto entries = m_server.GetEntries(item->description(), false, 100);

    std::vector<ncf::Menu::Item*> items;
    for (auto& entry : entries) {
        items.push_back(new EntryItem(entry));
    }

    m_entriesMenu.setItems(items);
}

void Categories::markCategoryRead()
{
    m_server.MarkCategoryAs(currentItem().description(), Fdly::Category::Action::READ, lastReadEntryId);

    auto entries = m_server.GetEntries(currentItem().description());
    std::vector<ncf::Menu::Item*> items;
    for (auto& entry : entries) {
        items.push_back(new EntryItem{entry});
    }
    m_entriesMenu.setItems(items);
}

int Categories::onKeyEvent(int ch)
{
    switch(ch) {
        case 'r': markCategoryRead(); break;
        default: Menu::onKeyEvent(ch); break;
    }
    return 0;
}
