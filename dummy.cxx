// A REST dummy program. dummy.cxx
//
// Author : J. Galan
// Date : Feb-2022
//

#include <iostream.h>
using namespace std;

#include "TRestTools.h"

int main(int argc, char** argv) {
    /// Just a dummy test. It will download this file to $HOME/.rest/download/
    std::string TRestTools::DownloadRemoteFile("https://github.com/rest-for-physics/framework/README.md");
}
