// A REST dummy program. dummy.cxx
//
// Author : J. Galan
// Date : Feb-2022
//

#include <iostream>
using namespace std;

#include "TRestTools.h"

int main(int argc, char** argv) {
    /// Just a dummy test. It will download this file to $HOME/.rest/download/
    std::string localname = TRestTools::DownloadRemoteFile("https://sultan.unizar.es/gasFiles/gases.rml");

    cout << "File downloaded to : " << localname << endl;

    return 0;
}
