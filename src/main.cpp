#include "main.h"
#include "main_frame.h"
#include <wx/image.h>

IMPLEMENT_APP(Simulator);

bool Simulator::OnInit()
{

    MainFrame *pMainFrame = new MainFrame(wxT( "Dice Simulator" ) );
    pMainFrame->Centre();
    pMainFrame->Show(true);
    return true;
}
