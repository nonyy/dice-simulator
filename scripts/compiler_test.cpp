#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Test")
    {
        auto sizer = new wxBoxSizer(wxHORIZONTAL);
        sizer->Add(new wxStaticText(this, wxID_ANY, "Press to enlarge"), wxSizerFlags().Border().Centre());

        auto btn = new wxButton(this, wxID_OK);
        btn->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
                for ( auto& w: GetChildren() )
                    w->SetFont(w->GetFont().Larger());

                Fit();
            });

        sizer->Add(btn, wxSizerFlags().Border().Centre());
        SetSizerAndFit(sizer);
        Show(true);
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit() override { new MyFrame; return true; }
};

wxIMPLEMENT_APP(MyApp);
