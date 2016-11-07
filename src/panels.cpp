#include "panels.h"

#include <ctime>
#include <cstdlib>

MainPanel::MainPanel(wxWindow* pMainFrame): wxPanel(pMainFrame)
{
    m_pResultPanel = new ResultPanel(this);
    m_pButtonsPanel = new DicesPanel(this);
    m_SubPanelsSizer = new wxBoxSizer(wxHORIZONTAL);
    m_SubPanelsSizer->Add(m_pButtonsPanel, -1, wxEXPAND);
    m_SubPanelsSizer->Add(m_pResultPanel, -1,  wxEXPAND);
    this->SetSizer(m_SubPanelsSizer);
}

void DicesPanel::OnClick(wxCommandEvent& event)
{
    const int SIZE = event.GetId();
    const int RANDOMIZED = rand() % SIZE + 1;
    m_pResult->SetLabel( wxString::Format(wxT("%d"), RANDOMIZED) );
    m_pResult->Centre();

    ++m_RAND_COUNT;

    wxString Randomization;
    Randomization.Printf("Roll count: %d | Dice size: %d | Randomized number:% d\r\n",
                         m_RAND_COUNT, SIZE, RANDOMIZED);
    *m_pSaveInfo << Randomization;


}

ResultPanel::ResultPanel(wxWindow *pParent): wxPanel(pParent, wxID_ANY)
{
    m_pResult = new wxStaticText(this, wxID_ANY, "");
    wxBoxSizer *hSizer = new wxBoxSizer(wxHORIZONTAL);
    hSizer->Add(m_pResult, wxEXPAND | wxALIGN_CENTER_HORIZONTAL);
    wxBoxSizer *vSizer = new wxBoxSizer(wxVERTICAL);
    vSizer->Add(hSizer, wxEXPAND | wxALIGN_CENTER_VERTICAL);
    SetSizer(vSizer);
    m_pResult->Bind( wxEVT_SIZE, [&](wxSizeEvent &)->void {m_pResult->Centre();} );
}


DicesPanel::DicesPanel(wxWindow* pParent): wxPanel(pParent)
{
    const int BUTTONS_COUNT = 8;
    const int SIZES[BUTTONS_COUNT] = {4,6,8,10,12,15,20,100};
    wxButton *pDices[BUTTONS_COUNT];

    srand( time(NULL) );
    auto* pMainPanel = dynamic_cast <MainPanel *> (pParent);
    auto* pResultPanel = dynamic_cast <ResultPanel *> (pMainPanel->m_pResultPanel);
    m_pResult = dynamic_cast <wxStaticText *> (pResultPanel->m_pResult);

    m_pDicesSizer = new wxGridSizer(4, 2, 0, 0);
    m_pSaveInfo = new wxString();

    for(int i = 0;i < BUTTONS_COUNT; ++i)
    {
        pDices[i] = new wxButton( this, SIZES[i], wxString::Format(wxT("%d"), SIZES[i]) );
        m_pDicesSizer->Add(pDices[i], -1, wxEXPAND);
        pDices[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &DicesPanel::OnClick, this, SIZES[i]);
    }

    this->SetSizer(m_pDicesSizer);
    m_pDicesSizer->SetSizeHints(pMainPanel);
}


