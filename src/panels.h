#ifndef panels_h
#define panels_h

#include <wx/panel.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/sizer.h>

class MainPanel : public wxPanel
{
public:
    MainPanel(wxWindow* pMainFrame);
    wxPanel *m_pButtonsPanel;
    wxPanel *m_pResultPanel;
private:
    wxBoxSizer *m_SubPanelsSizer;
};

class DicesPanel : public wxPanel
{
public:
    DicesPanel(wxWindow *pParent);
private:
    wxButton *m_pDice;
    wxStaticText *m_pResult;
    wxGridSizer *m_pDicesSizer;
    int m_RAND_COUNT = 0;
public:
    wxString *m_pSaveInfo;
private:
    void OnClick(wxCommandEvent &event);
};

class ResultPanel : public wxPanel
{
public:
    ResultPanel(wxWindow *pParent);
    wxStaticText *m_pResult;
};



#endif // panels_h
