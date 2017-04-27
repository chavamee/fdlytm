#include <fdly.hpp>
#include "ncf/Decorators.hpp"
#include "ncf/TextView.hpp"
#include "ncf/Application.hpp"
#include "ncf/Row.hpp"
#include "ncf/Column.hpp"

#include "Categories.hpp"
#include "Entries.hpp"

#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
using namespace ncf;

static string g_APIKey;
static string g_UserID;

void print_usage()
{
    cout << "Usage:" << endl;
    cout << "   --api-key <API Key>" << endl;
    cout << "   --user-id <User ID>" << endl;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--api-key" ) == 0) {
            i++;
            if (i < argc) {
                g_APIKey = argv[i];
            }
        } else if (strcmp(argv[i], "--user-id") == 0) {
            i++;
            if (i < argc) {
                g_UserID = argv[i];
            }
        }
    }

    if (g_UserID.empty() || g_APIKey.empty()) {
        print_usage();
        return 1;
    }

    Fdly::User user{
        g_UserID,
        g_APIKey
    };

    Fdly server {
        user
    };

    Application app {};

    Column body        {};
    Row    top         {};

    TextView     prev        {};
    Entries    entriesMenu {prev};
    Categories ctgMenu     {server, entriesMenu};

    ctgMenu.optionsOff(O_SHOWDESC);
    entriesMenu.optionsOff(O_SHOWDESC);

    prev.canFocus = false;

    vector<Menu::Item*> ctgItems;
    vector<Menu::Item*> entryItems;
    auto categories = server.GetCategories();
    for (auto& ctg : categories) {
        ctgItems.push_back(new Menu::Item(ctg.Label, ctg.ID));
    }

    auto entries = server.GetEntries("All");
    for (auto& entry : entries) {
        entryItems.push_back(new EntryItem(entry));
    }

    ctgMenu.setItems(ctgItems);
    entriesMenu.setItems(entryItems);

    top.add(new ncf::Border(&entriesMenu));
    top.add(new ncf::Border(&ctgMenu));

    body.add(&top, 0);
    body.add(new ncf::Border(&prev), 1);

    prev.setContent("Hello, World!");

    app.setInitialContext(&ctgMenu);

    body.draw();

    app.start();

    return 0;
}
