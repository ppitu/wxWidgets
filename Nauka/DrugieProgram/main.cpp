#include "wx/wxprec.h"
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

const wxString appName = "Pierwszy program";

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
};

class MyFrame : public wxFrame
{
    public:
        MyFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size);

    private:
        wxStatusBar *sb;

        wxMenuBar *mb;

        wxMenu *mFile;
        wxMenu *mHelp;
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame  = new MyFrame(nullptr, wxID_ANY, appName, wxPoint(200, 100), wxSize(800, 600));
    frame->Show(true);

    return true;
}

MyFrame::MyFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size)
: wxFrame(parent, id, title, pos, size) //Lista inicjalzacji wxFrame
{
    mb = new wxMenuBar();

    mFile = new wxMenu();
    mHelp = new wxMenu();

    mFile->AppendCheckItem(wxID_ANY, wxT("Pokaż datę\tCtrl-D"), wxT("Pokazuje datę"));
    mFile->Append(wxID_ANY, wxT("Pokaż wersje systemu\tCtrl-W"), wxT("Pokazuje wersje systemu"));
    mFile->AppendSeparator();
    mFile->Append(wxID_ANY, wxT("Zamknij program\tCtrl-X"), wxT("Zamyka program"));

    mHelp->Append(wxID_ANY, wxT("O programie\tF1"), wxT("O programie"));

    mb->Append(mFile, wxT("&Plik"));
    mb->Append(mHelp, wxT("&Pomoc"));

    this->SetMenuBar(mb);

    sb = new wxStatusBar(this);
    sb->SetFieldsCount(2);
    this->SetStatusBar(sb);
    SetStatusText(title, 0);
    CenterOnScreen();
}
