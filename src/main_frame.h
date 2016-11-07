#ifndef main_frame_h
#define main_frame_h


#include <wx/frame.h>
#include <wx/toolbar.h>
#include <wx/panel.h>

//link to main window's icon source: http://www.clker.com/clipart-role-playing-dice.html
//link to other icon's source: https://www.iconfinder.com/iconsets/blueberry

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString &title);
private:
    wxToolBar *m_pToolbar;
    enum IDs{ID_EXIT = 300, ID_SAVE, ID_ABOUT};
    wxPanel *m_pMainPanel;

    void OnExit(wxCommandEvent &event);
    void OnSave(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
};


#endif // main_frame_h
