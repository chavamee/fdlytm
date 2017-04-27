#include "Entries.hpp"

using namespace std;
using namespace ncf;

Entries::Entries(TextView& view) :
    Menu(),
    m_previewTextView(view)
{
}

void Entries::ShowPreview(const string& preview)
{
    string contentDumpPath = "/tmp/termfeed.content.dump.html";
    ofstream sample(contentDumpPath);

    sample << preview;

    string command = "w3m -dump -cols " + to_string(COLS - 2) + " " + contentDumpPath;
    FILE* stream = popen(command.c_str(), "r");

    string content;
    if (stream) {
        char buffer[256];
        while (not feof(stream)) {
            if (fgets(buffer, 256, stream) not_eq NULL) {
                content.append(buffer);
            }
        }
        pclose(stream);
    }
    m_previewTextView->setContent(content);
}
