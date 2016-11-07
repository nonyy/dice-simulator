#include "main_frame.h"
#include "panels.h"

#include <wx/image.h>
#include <wx/msgdlg.h>
#include <wx/file.h>
#include <wx/string.h>

#ifndef __WXMSW__
    #include "../icons/app.xpm"
    #include "linux/pngs.h"
#endif

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close();
}

void MainFrame::OnSave(wxCommandEvent& event)
{
    auto* pMainPanel = dynamic_cast <MainPanel *> (m_pMainPanel);
    auto* pDicePanel = dynamic_cast <DicesPanel *> (pMainPanel->m_pButtonsPanel);
    wxFile SavingFile;
    SavingFile.Create(wxT("rolls.txt"), true);
    SavingFile.Write( *( pDicePanel->m_pSaveInfo ) );
    wxMessageBox(wxT("The rolls have been saved."), wxT("Saved"), wxOK | wxCENTER, this);
    SavingFile.Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxString Message = R"(The MIT License (MIT)
Copyright (c) 2014 Tomasz Hamerla

Full license text available at:
https://opensource.org/licenses/MIT
)";

    wxMessageBox( Message, wxT("About") );
}

MainFrame::MainFrame(const wxString &title): wxFrame (NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400,200) )
{
    SetIcon(wxICON(icons_app));

    wxImage::AddHandler(new wxPNGHandler);
    wxBitmap Exit( wxBITMAP_PNG(icons_exit) );
    wxBitmap About( wxBITMAP_PNG(icons_about) );
    wxBitmap Save( wxBITMAP_PNG(icons_save) );


    m_pToolbar = CreateToolBar( (wxTB_DEFAULT_STYLE & ~wxTB_HORIZONTAL) | wxTB_VERTICAL );
    m_pToolbar->AddTool(ID_EXIT, wxT("Exit"), Exit);
    Bind(wxEVT_COMMAND_TOOL_CLICKED, &MainFrame::OnExit, this, ID_EXIT);
    m_pToolbar->AddTool(ID_SAVE, wxT("Save the rolls"), Save);
    m_pToolbar->AddTool(ID_ABOUT, wxT("About"), About);
    Bind(wxEVT_COMMAND_TOOL_CLICKED, &MainFrame::OnAbout, this, ID_ABOUT);
    m_pToolbar->Realize();

    m_pMainPanel = new MainPanel(this);
    Bind(wxEVT_COMMAND_TOOL_CLICKED, &MainFrame::OnSave, this, ID_SAVE);

    m_pToolbar->InsertStretchableSpace(0);
    m_pToolbar->InsertStretchableSpace(4);
}
